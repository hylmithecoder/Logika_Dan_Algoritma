#include <HandleWindow.hpp>

void Window::error_callback(int error, const char* description) {
    cerr << "Error: " << description << endl;
}

int Window::getPagePDF(const char* filePath){
    // Cek apakah file ada
    FILE* testFile = fopen(filePath, "rb");
    if (!testFile) {
        cerr << "File tidak ditemukan: " << filePath << endl;
        return 0;
    }

    fclose(testFile);
    doc = fz_open_document(ctx, filePath);
        
        if (!doc) {
            cerr << "Dokumen NULL setelah fz_open_document" << endl;
            fz_throw(ctx, FZ_ERROR_GENERIC, "Failed to open document");
        }
        
        // Cek apakah dokumen perlu password
        if (fz_needs_password(ctx, doc)) {
            cerr << "PDF memerlukan password" << endl;
            fz_drop_document(ctx, doc);
            doc = nullptr;
        }
        
    // Dapatkan jumlah halaman
    totalPages = fz_count_pages(ctx, doc);
    return totalPages;
}

vector<GLuint> Window::readPDFFile(const char* filePath) {
    cleanup();
    vector<GLuint> allTexturePages;
    
    // Cek apakah file ada
    FILE* testFile = fopen(filePath, "rb");
    if (!testFile) {
        cerr << "File tidak ditemukan: " << filePath << endl;
        return vector<GLuint>();
    }
    fclose(testFile);
    
    cout <<"Mencoba membuka PDF: " << filePath << endl;
    
    fz_try(ctx) {
        // Buka dokumen PDF dengan error handling yang lebih baik
        doc = fz_open_document(ctx, filePath);
        
        if (!doc) {
            cerr << "Dokumen NULL setelah fz_open_document" << endl;
            fz_throw(ctx, FZ_ERROR_GENERIC, "Failed to open document");
        }
        
        // Cek apakah dokumen perlu password
        if (fz_needs_password(ctx, doc)) {
            cerr << "PDF memerlukan password" << endl;
            fz_drop_document(ctx, doc);
            doc = nullptr;
            return vector<GLuint>();
        }
        
        // Dapatkan jumlah halaman
        totalPages = fz_count_pages(ctx, doc);
        praktikum6.totalPages = totalPages;
        cout <<"Total halaman: " << totalPages << endl;
        
        if (totalPages <= 0) {
            cerr << "PDF tidak memiliki halaman" << endl;
            fz_drop_document(ctx, doc);
            doc = nullptr;
            return vector<GLuint>();
        }
        
        // Render semua halaman ke texture
        for (int i = 0; i < totalPages; i++) {
            cout <<"Rendering halaman" << i + 1 << "..." << endl;
            
            fz_page* page = fz_load_page(ctx, doc, i);
            
            // Dapatkan bound halaman
            fz_rect bounds = fz_bound_page(ctx, page);
            
            // Buat matrix untuk scaling (zoom)
            fz_matrix transform = fz_scale(2.0f, 2.0f); // 2x zoom
            bounds = fz_transform_rect(bounds, transform);
            
            // Render halaman ke pixmap
            fz_pixmap* pix = fz_new_pixmap_from_page(
                ctx, page, transform, 
                fz_device_rgb(ctx), 0
            );
            
            if (!pix) {
                cerr << "Gagal membuat pixmap untuk halaman " << i << endl;
                fz_drop_page(ctx, page);
                continue;
            }
            
            // Konversi ke texture OpenGL
            GLuint texture = createTextureFromPixmap(pix);
            cout << "Texture: " << texture << endl;
            allTexturePages.push_back(texture);
            // praktikum6.currentPageTextures = pageTextures;
            // cout << "PageTextures size: " << praktikum6.currentPageTextures.size() << endl;
            // Bersihkan
            fz_drop_pixmap(ctx, pix);
            fz_drop_page(ctx, page);
        }
        
        pdfLoaded = true;
        cout <<"PDF berhasil dimuat: " << totalPages << "halaman" << endl;
        return allTexturePages;
    }
    fz_catch(ctx) {
        const char* errMsg = fz_caught_message(ctx);
        cerr << "Gagal membuka PDF: " << errMsg  << endl;
        
        if (doc) {
            fz_drop_document(ctx, doc);
            doc = nullptr;
        }
        pdfLoaded = false;
    }
}

void Window::renderPDF(const vector<GLuint>& currentPageTextures, int& currentPage, const int& totalPages) {
    if (currentPageTextures.empty()) {
        ImGui::Text("Tidak ada PDF yang dimuat");
        return;
    }
    
    if (currentPage >= totalPages) {
        currentPage = 0;
    }
    
    ImGui::Text("Halaman %d dari %d", currentPage + 1, totalPages);
    
    if (ImGui::Button("< Sebelumnya") && currentPage > 0) {
        currentPage--;
    }
    ImGui::SameLine();
    if (ImGui::Button("Selanjutnya >") && currentPage < totalPages - 1) {
        currentPage++;
    }
    
    ImGui::Separator();
    

    if (currentPageTextures.empty()) {
        cout << "Tidak ada textures yang dimuat" << endl;
        return;
    }
    if (currentPage >= currentPageTextures.size()) {
        cout << "Index halaman tidak valid: " << currentPage << " (total: " << currentPageTextures.size() << ")" << endl;
        return;
    }

    GLuint currentTexture = currentPageTextures[currentPage];
    
    // Dapatkan ukuran texture
    int w, h;
    glBindTexture(GL_TEXTURE_2D, currentTexture);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);
    
    // Tampilkan sebagai image di ImGui
    ImVec2 size = ImGui::GetContentRegionAvail();
    float scale = std::min(size.x / w, size.y / h);
    
    ImGui::Image((ImTextureID)(intptr_t)currentTexture, 
                 ImVec2(w * scale, h * scale));
}

void Window::initMuPDF() {
    if (ctx) return; // Sudah diinit
    
    // Alokasi memory untuk context dengan ukuran yang cukup
    ctx = fz_new_context(NULL, NULL, 256 << 20); // 256 MB
    if (!ctx) {
        cerr << "ERROR: Cannot create MuPDF context" << endl;
        return;
    }
    
    cout <<"✓ MuPDF context created successfully " << endl;
    
    // Register document handlers
    fz_try(ctx) {
        fz_register_document_handlers(ctx);
        cout <<"✓ MuPDF document handlers registered" << endl;
    }
    fz_catch(ctx) {
        cerr << "ERROR: Cannot register document handlers: " <<  fz_caught_message(ctx) << endl;
        fz_drop_context(ctx);
        ctx = nullptr;
    }
}

void Window::init(){

    srand(static_cast<unsigned int>(time(0)));
    
    if (!glfwInit()){
        return;
    }

    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    // float main_scale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor()); // Valid on GLFW 3.3+ only
    window = glfwCreateWindow(width, height, "Logika Dan Algoritma", NULL, NULL);
    // Setelah membuat jendela dengan window = glfwCreateWindow(width, height, "Logika Dan Algoritma", NULL, NULL);
    int screenWidth, screenHeight;
    glfwGetWindowSize(window, &screenWidth, &screenHeight);
    int windowWidth = width;
    int windowHeight = height;
    int xPos = (screenWidth - windowWidth) / 2;
    int yPos = (screenHeight - windowHeight) / 2;

    glfwSetWindowPos(window, xPos, yPos);
    if (!window) {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate(); // Terminate GLFW if window creation fails
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    float base_font_size = 22.0f;
    io.Fonts->AddFontFromFileTTF("/home/hylmi/Hylmi/Pemrograman_Berorientasi_Objek/C++/GameEngineSDL/assets/fonts/zh-cn.ttf", base_font_size);

    // io.Fonts->AddFontDefault();
    // io.FontGlobalScale = 2.0f;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();

    g_io = io;

     // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Make the window's context current
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    initMuPDF();
    praktikum2.totalPages = getPagePDF(filePaths[0]);
    praktikum2.currentPageTextures = readPDFFile(filePaths[0]);
    praktikum4.totalPages = getPagePDF(filePaths[1]);
    praktikum4.currentPageTextures = readPDFFile(filePaths[1]);
    praktikum6.totalPages = getPagePDF(filePaths[2]);
    praktikum6.currentPageTextures = readPDFFile(filePaths[2]);
    per13.totalPages = getPagePDF(filePaths[3]);
    per13.currentPageTextures = readPDFFile(filePaths[3]);
}

void Window::Clean(){
    cleanup();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);          
    glfwTerminate();
}

void Window::kalkulatorWindow(){
    static float number1 = 0; 
    static float number2 = 0;
    ImGui::Begin("Kalkulator window");
    ImGui::InputFloat("Angka pertama", &number1);
    ImGui::InputFloat("Angka kedua", &number2);
    ImGui::Separator();
    handleButton(number1, number2);
    ImGui::End();
}

void Window::handleButton(float& number1, float& number2){
    if (ImGui::Button("Tambah")) {
        eksekusi = "Tambah";
        hasil = tambah(number1, number2);
    } else if (ImGui::Button("Kurang")) {
        eksekusi = "Kurang";
        hasil = kurang(number1, number2);
    } else if (ImGui::Button("Kali")) {
        eksekusi = "Kali";
        hasil = kali(number1, number2);
    } else if (ImGui::Button("Bagi")) {
        eksekusi = "Bagi";
        hasil = bagi(number1, number2);
    }
    // cout << "Hasil: " << hasil << endl;
    ImGui::Text("Hasil %s: %f", eksekusi.c_str(), hasil);
}

float Window::tambah(const float& angka1,const float& angka2){
    float tambah = angka1 + angka2;
    // ImGui::Text("Hasil penjumlahan: %f", tambah);
    return tambah;
}

float Window::kurang(const float& angka1,const float& angka2){
    float tambah = angka1 - angka2;
    // ImGui::Text("Hasil pengurangan: %f", tambah);
    return tambah;
}

float Window::kali(const float& angka1,const float& angka2){
    float tambah = angka1 * angka2;
    // ImGui::Text("Hasil pengalian: %f", tambah);
    return tambah;
}

float Window::bagi(const float& angka1,const float& angka2){
    float tambah = angka1 / angka2;
    // ImGui::Text("Hasil pembagian: %f", tambah);
    return tambah;
}

void Window::Update(ImGuiIO& io){

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

        // Main Dockspace
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        
        ImGui::Begin("DockSpace", nullptr, window_flags);
        ImGui::PopStyleVar(2);
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        // #ifdef ImGuiConfigFlags_DockingEnable
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);

        kalkulatorWindow();
        praktikum2.uipertemuan2();
        praktikum4.uipertemuan4();
        praktikum6.uipertemuan6();
        dataSekolah.uidataSekolah();
        praktikum7.ui();
        uts.handleUI();
        per10.windowPer10();
        studyCase.windowStudyCase();
        per12.windowPer12();
        per13.windowPer13();

        ImGui::End();
        // Render
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
        // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
        //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(window);
    }
}

void Window::Main(){
    init();
    Update(g_io);
    Clean();
}

void Window::cleanup() {
    // Hapus semua texture
    for (GLuint tex : pageTextures) {
        glDeleteTextures(1, &tex);
    }
    pageTextures.clear();
    
    // Tutup dokumen
    if (doc) {
        fz_drop_document(ctx, doc);
        doc = nullptr;
    }
    
    // Reset semua state
    // pdfLoaded = false;
    totalPages = 0;
}

void Window::pertemuan6::renderPDF() {
    if (currentPageTextures.empty()) {
        ImGui::Text("Tidak ada PDF yang dimuat");
        return;
    }
    
    if (currentPage >= totalPages) {
        currentPage = 0;
    }
    
    ImGui::Text("Halaman %d dari %d", currentPage + 1, totalPages);
    
    if (ImGui::Button("< Sebelumnya") && currentPage > 0) {
        currentPage--;
    }
    ImGui::SameLine();
    if (ImGui::Button("Selanjutnya >") && currentPage < totalPages - 1) {
        currentPage++;
    }
    
    ImGui::Separator();
    

    if (currentPageTextures.empty()) {
        cout << "Tidak ada textures yang dimuat" << endl;
        return;
    }
    if (currentPage >= currentPageTextures.size()) {
        cout << "Index halaman tidak valid: " << currentPage << " (total: " << currentPageTextures.size() << ")" << endl;
        return;
    }

    GLuint currentTexture = currentPageTextures[currentPage];
    
    // Dapatkan ukuran texture
    int w, h;
    glBindTexture(GL_TEXTURE_2D, currentTexture);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);
    
    // Tampilkan sebagai image di ImGui
    ImVec2 size = ImGui::GetContentRegionAvail();
    float scale = std::min(size.x / w, size.y / h);
    
    ImGui::Image((ImTextureID)(intptr_t)currentTexture, 
                 ImVec2(w * scale, h * scale));
}

GLuint Window::createTextureFromPixmap(fz_pixmap* pix) {
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    // Upload texture data
    int w = fz_pixmap_width(ctx, pix);
    int h = fz_pixmap_height(ctx, pix);
    unsigned char* samples = fz_pixmap_samples(ctx, pix);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, 
                 GL_RGB, GL_UNSIGNED_BYTE, samples);
    
    return texture;
}

void Window::choiceModule(){
    ImGui::Begin("Choice module");
    ImGui::Text("Pilih Module yang mana ingin di buka");
    ImGui::End();
}

void Window::pertemuan2::uipertemuan2(){
    Window* parent = (Window*)this;
    ImGui::Begin("Pertemuan 2");
    ImGui::Text("Pertemuan 2 Logika matematika dalam c++");
    parent->renderPDF(currentPageTextures, currentPage, totalPages);
    soal1();
    soal2();
    ImGui::End();
}

void Window::pertemuan4::uipertemuan4(){
    Window* parent = (Window*)this;
    ImGui::Begin("Pertemuan 4");
    ImGui::Text("Pertemuan 4 Percabangan dalam pemrograman");
    parent->renderPDF(currentPageTextures, currentPage, totalPages);
    ImGui::End();
}