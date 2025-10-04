#include <HandleWindow.hpp>

void Window::error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

void Window::init(){

    if (!glfwInit()){
        return;
    }

    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    // float main_scale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor()); // Valid on GLFW 3.3+ only
    window = glfwCreateWindow(width, height, "Logika Dan Algoritma", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
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

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    // style.ScaleAllSizes(main_scale);
    // style.FontScaleDpi = main_scale;   

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


}

void Window::Clean(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);          
    glfwTerminate();
}

void Window::kalkulatorWindow(){
    static double number1 = 0; 
    static double number2 = 0;
    ImGui::Begin("Kalkulator window");
    ImGui::InputDouble("Angka pertama: ", &number1);
    ImGui::InputDouble("Angka kedua: ", &number2);
    ImGui::Separator();
    handleButton(number1, number2);
    ImGui::End();
}

void Window::handleButton(double& number1, double& number2){
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
    cout << "Hasil: " << hasil << endl;
    ImGui::Text("Hasil %s: %f", eksekusi.c_str(), hasil);
}

double Window::tambah(const double& angka1,const double& angka2){
    double tambah = angka1 + angka2;
    // ImGui::Text("Hasil penjumlahan: %f", tambah);
    return tambah;
}

double Window::kurang(const double& angka1,const double& angka2){
    double tambah = angka1 - angka2;
    // ImGui::Text("Hasil pengurangan: %f", tambah);
    return tambah;
}

double Window::kali(const double& angka1,const double& angka2){
    double tambah = angka1 * angka2;
    // ImGui::Text("Hasil pengalian: %f", tambah);
    return tambah;
}

double Window::bagi(const double& angka1,const double& angka2){
    double tambah = angka1 / angka2;
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

        kalkulatorWindow();

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