#include <HandleWindow.hpp>

void Window::TableDataSekolah::uidataSekolah(){
    static int current_item_index = 0;
    const char* choice[] = { "TK", "SD", "SMP", "SMA" };
    static char namasiswa[256], namaIbu[256], asalTK[256], asalSD[256], asalSMP[256];
    static int NIS, NIKIbu, noIjazahSD, noIjazahSMP;
    ImGui::Begin("Table data sekolah");
    ImGui::Text("Sekolah");
    ImGui::Separator();
    ImGui::Combo("##Pilih Bangun Type", &current_item_index, choice, IM_ARRAYSIZE(choice));
    if (current_item_index == 0){
        uiTypeTk();
    } else if (current_item_index == 1){
        uiTypeSd();
    } else if (current_item_index == 2){
        uiTypeSmp();
    } else if (current_item_index == 3){
        uiTypeSma();
    }
    
    ImGui::End();
}

void Window::TableDataSekolah::submitToTKTable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu){
    // cout << tableDataTK[currentBarisTk].dataSiswa[currentBarisTk].namasiswa << endl;
    tableDataTK[currentBarisTk+1].dataSiswa[currentBarisTk+1].namasiswa = namasiswa;
    tableDataTK[currentBarisTk+1].dataSiswa[currentBarisTk+1].NIS = NIS;
    tableDataTK[currentBarisTk+1].dataSiswa[currentBarisTk+1].NamaIbu = namaIbu;
    tableDataTK[currentBarisTk+1].dataSiswa[currentBarisTk+1].NIKIbu = NIKIbu;

    currentBarisTk++;
    cout << "Baris TK: " << currentBarisTk << endl;
}

void Window::TableDataSekolah::submitToSDTable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu, string& asalTK){
    tableDataSD[currentBarisSd+1].dataSiswa[currentBarisSd+1].namasiswa = namasiswa;
    tableDataSD[currentBarisSd+1].dataSiswa[currentBarisSd+1].NamaIbu = namaIbu;
    tableDataSD[currentBarisSd+1].dataSiswa[currentBarisSd+1].NIS = NIS;
    tableDataSD[currentBarisSd+1].dataSiswa[currentBarisSd+1].NIKIbu = NIKIbu;
    tableDataSD[currentBarisSd+1].asalTK = asalTK;

    currentBarisSd++;
}

void Window::TableDataSekolah::submitToSMPTable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu, string& asalTK, string& asalSd, int& noIjazahSD){
    tableDataSMP[currentBarisSmp+1].dataSiswa[currentBarisSmp+1].namasiswa = namasiswa;
    tableDataSMP[currentBarisSmp+1].dataSiswa[currentBarisSmp+1].NamaIbu = namaIbu;
    tableDataSMP[currentBarisSmp+1].dataSiswa[currentBarisSmp+1].NIS = NIS;
    tableDataSMP[currentBarisSmp+1].dataSiswa[currentBarisSmp+1].NIKIbu = NIKIbu;
    tableDataSMP[currentBarisSmp+1].asalTK = asalTK;
    tableDataSMP[currentBarisSmp+1].asalSD = asalSd;
    tableDataSMP[currentBarisSmp+1].noIjazahSD = noIjazahSD;

    currentBarisSmp++;
}

void Window::TableDataSekolah::submitToSMATable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu, string& asalTK,  string& asalSd, int& noIjazahSD, string& asalSMP, int& noIjazahSmp){
    tableDataSMA[currentBarisSma+1].dataSiswa[currentBarisSma+1].namasiswa = namasiswa;
    tableDataSMA[currentBarisSma+1].dataSiswa[currentBarisSma+1].NamaIbu = namaIbu;
    tableDataSMA[currentBarisSma+1].dataSiswa[currentBarisSma+1].NIS = NIS;
    tableDataSMA[currentBarisSma+1].dataSiswa[currentBarisSma+1].NIKIbu = NIKIbu;
    tableDataSMA[currentBarisSma+1].asalTK = asalTK;
    tableDataSMA[currentBarisSma+1].asalSD = asalSd;
    tableDataSMA[currentBarisSma+1].noIjazahSD = noIjazahSD;
    tableDataSMA[currentBarisSma+1].asalSMP = asalSMP;
    tableDataSMA[currentBarisSma+1].noIjazahSMP = noIjazahSmp;

    currentBarisSma++;
}


void Window::TableDataSekolah::showTableTK(TKTable tableData[]){
    if (currentBarisTk < 0){
        return;
    }

    if (ImGui::BeginTable("Table Data TK", 5, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        ImGui::TableSetupColumn("Nama Siswa");
        ImGui::TableSetupColumn("NIS");
        ImGui::TableSetupColumn("Nama Ibu");
        ImGui::TableSetupColumn("NIK Ibu");
        ImGui::TableSetupColumn("Action");

        // Display headers
        ImGui::TableHeadersRow();

        for (int i = 1; i <= currentBarisTk; ++i){
            // ImGui::Text("Kolom ke %i", i);
            ImGui::TableNextRow(); // Start a new row

            ImGui::TableSetColumnIndex(0); // Go to the first column
            ImGui::Text("%s", tableData[i].dataSiswa[i].namasiswa.c_str());
            
            ImGui::TableSetColumnIndex(1); // Go to the first column
            ImGui::Text("%i", tableData[i].dataSiswa[i].NIS);
            
            ImGui::TableSetColumnIndex(2); // Go to the first column
            ImGui::Text("%s", tableData[i].dataSiswa[i].NamaIbu.c_str());
            
            ImGui::TableSetColumnIndex(3); // Go to the first column
            ImGui::Text("%i", tableData[i].dataSiswa[i].NIKIbu);

            ImGui::TableSetColumnIndex(4); // Go to the first column
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.1f, 0.2f, 1.0f));
            ImGui::PushID(i);
            if (ImGui::Button("Delete")){
                deleteDataSiswaTypeTk(tableData, currentBarisTk);
            }
            ImGui::PopID();
            ImGui::PopStyleColor();
        }

        ImGui::EndTable();
    }    
}

void Window::TableDataSekolah::showTableSD(SDTable tableData[]){
    if (currentBarisSd < 0){
        return;
    }

    if (ImGui::BeginTable("Table Data SD", 6, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        ImGui::TableSetupColumn("Nama Siswa");
        ImGui::TableSetupColumn("NIS");
        ImGui::TableSetupColumn("Nama Ibu");
        ImGui::TableSetupColumn("NIK Ibu");
        ImGui::TableSetupColumn("Asal TK");
        ImGui::TableSetupColumn("Action");

        // Display headers
        ImGui::TableHeadersRow();

        for (int i = 1; i <= currentBarisSd; ++i){
            // ImGui::Text("Kolom ke %i", i);
            ImGui::TableNextRow(); // Start a new row

            ImGui::TableSetColumnIndex(0); // Go to the first column
            ImGui::Text("%s", tableData[i].dataSiswa[i].namasiswa.c_str());
            
            ImGui::TableSetColumnIndex(1); // Go to the first column
            ImGui::Text("%i", tableData[i].dataSiswa[i].NIS);
            
            ImGui::TableSetColumnIndex(2); // Go to the first column
            ImGui::Text("%s", tableData[i].dataSiswa[i].NamaIbu.c_str());
            
            ImGui::TableSetColumnIndex(3); // Go to the first column
            ImGui::Text("%i", tableData[i].dataSiswa[i].NIKIbu);

            ImGui::TableSetColumnIndex(4); // Go to the first column
            ImGui::Text("%s", tableData[i].asalTK.c_str());

            ImGui::TableSetColumnIndex(5); // Go to the first column
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.1f, 0.2f, 1.0f));
            ImGui::PushID(i);
            if (ImGui::Button("Delete")){
                deleteDataSiswaTypeSd(tableData, currentBarisSd);
            }
            ImGui::PopID();
            ImGui::PopStyleColor();
        }

        ImGui::EndTable();
    }
}

void Window::TableDataSekolah::showTableSMP(SMPTable tableData[]){
    if (currentBarisSmp < 0){
        return;
    }

    if (ImGui::BeginTable("Table Data SMP", 8, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        ImGui::TableSetupColumn("Nama Siswa");
        ImGui::TableSetupColumn("NIS");
        ImGui::TableSetupColumn("Nama Ibu");
        ImGui::TableSetupColumn("NIK Ibu");
        ImGui::TableSetupColumn("Asal TK");
        ImGui::TableSetupColumn("Asal SD");
        ImGui::TableSetupColumn("No Ijazah SD");
        ImGui::TableSetupColumn("Action");

        // Display headers
        ImGui::TableHeadersRow();

        for (int i = 1; i <= currentBarisSmp; ++i){
            // ImGui::Text("Kolom ke %i", i);
            ImGui::TableNextRow(); // Start a new row

            ImGui::TableSetColumnIndex(0); // Go to the first column
            ImGui::Text("%s", tableData[i].dataSiswa[i].namasiswa.c_str());
            
            ImGui::TableSetColumnIndex(1); // Go to the first column
            ImGui::Text("%i", tableData[i].dataSiswa[i].NIS);
            
            ImGui::TableSetColumnIndex(2); // Go to the first column
            ImGui::Text("%s", tableData[i].dataSiswa[i].NamaIbu.c_str());
            
            ImGui::TableSetColumnIndex(3); // Go to the first column
            ImGui::Text("%i", tableData[i].dataSiswa[i].NIKIbu);

            ImGui::TableSetColumnIndex(4); // Go to the first column
            ImGui::Text("%s", tableData[i].asalTK.c_str());

            ImGui::TableSetColumnIndex(5); // Go to the first column
            ImGui::Text("%s", tableData[i].asalSD.c_str());

            ImGui::TableSetColumnIndex(6); // Go to the first column
            ImGui::Text("%i", tableData[i].noIjazahSD);

            ImGui::TableSetColumnIndex(7); // Go to the first column
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.1f, 0.2f, 1.0f));
            ImGui::PushID(i);
            if (ImGui::Button("Delete")){
                deleteDataSiswaTypeSmp(tableData, currentBarisSmp);
            }
            ImGui::PopID();
            ImGui::PopStyleColor();
        }

        ImGui::EndTable();
    }
}

void Window::TableDataSekolah::showTableSMA(SMATable tableData[]){
    if (currentBarisSma < 0){
        return;
    }
    

    if (ImGui::BeginTable("Table Data SMA", 10, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        ImGui::TableSetupColumn("Nama Siswa");
        ImGui::TableSetupColumn("NIS");
        ImGui::TableSetupColumn("Nama Ibu");
        ImGui::TableSetupColumn("NIK Ibu");
        ImGui::TableSetupColumn("Asal TK");
        ImGui::TableSetupColumn("Asal SD");
        ImGui::TableSetupColumn("No Ijazah SD");
        ImGui::TableSetupColumn("Asal SMP");
        ImGui::TableSetupColumn("No Ijazah SMP");
        ImGui::TableSetupColumn("Action");

        // Display headers
        ImGui::TableHeadersRow();

        for (int i = 1; i <= currentBarisSma; ++i){
            // ImGui::Text("Kolom ke %i", i);
            ImGui::TableNextRow(); // Start a new row

            ImGui::TableSetColumnIndex(0); // Go to the first column
            ImGui::Text("%s", tableData[i].dataSiswa[i].namasiswa.c_str());
            
            ImGui::TableSetColumnIndex(1); // Go to the first column
            ImGui::Text("%i", tableData[i].dataSiswa[i].NIS);
            
            ImGui::TableSetColumnIndex(2); // Go to the first column
            ImGui::Text("%s", tableData[i].dataSiswa[i].NamaIbu.c_str());
            
            ImGui::TableSetColumnIndex(3); // Go to the first column
            ImGui::Text("%i", tableData[i].dataSiswa[i].NIKIbu);

            ImGui::TableSetColumnIndex(4); // Go to the first column
            ImGui::Text("%s", tableData[i].asalTK.c_str());

            ImGui::TableSetColumnIndex(5); // Go to the first column
            ImGui::Text("%s", tableData[i].asalSD.c_str());

            ImGui::TableSetColumnIndex(6); // Go to the first column
            ImGui::Text("%i", tableData[i].noIjazahSD);

            ImGui::TableSetColumnIndex(7); // Go to the first column
            ImGui::Text("%s", tableData[i].asalSMP.c_str());

            ImGui::TableSetColumnIndex(8); // Go to the first column
            ImGui::Text("%i", tableData[i].noIjazahSMP);

            ImGui::TableSetColumnIndex(9); // Go to the first column
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.1f, 0.2f, 1.0f));
            ImGui::PushID(i);
            if (ImGui::Button("Delete")){
                deleteDataSiswaTypeSma(tableData, currentBarisSma);
            }
            ImGui::PopID();
            ImGui::PopStyleColor();
        }

        ImGui::EndTable();
    }
}

void Window::TableDataSekolah::uiTypeTk(){
    static char namasiswa[256], namaIbu[256];
    static int NIS, NIKIbu, jumlahSiswa = 0, currentJumlahSiswa = 0;

    if (currentJumlahSiswa == 0){
        ImGui::Text("Masukkan dahulu jumlah siswa yang akan diinput\nJumlah siswa: ");
        ImGui::SameLine();
        ImGui::InputInt("##Jumlahsiswa", &jumlahSiswa);
        if (ImGui::Button("init jumlah siswa")){
            currentJumlahSiswa = jumlahSiswa;
        }
    } else {
        ImGui::Text("Table data TK");
        ImGui::Text("Nama siswa");
        ImGui::SameLine();
        ImGui::InputText("##Namasiswa", namasiswa, IM_ARRAYSIZE(namasiswa));
        ImGui::Text("NIS");
        ImGui::SameLine();
        ImGui::InputInt("##NIS", &NIS);
        ImGui::Text("Nama Ibu");
        ImGui::SameLine();
        ImGui::InputText("##Namaibu", namaIbu, IM_ARRAYSIZE(namaIbu));
        ImGui::Text("NIK Ibu");
        ImGui::SameLine();
        ImGui::InputInt("##NIKIbu", &NIKIbu);
        string convertedNama = namasiswa, convertedNamaIbu = namaIbu;
        if (currentJumlahSiswa == currentBarisTk){
            ImGui::Text("Melebihi batas jumlah siswa");
        } else {
            if (ImGui::Button("Tambah siswa")){
                submitToTKTable(convertedNama, convertedNamaIbu, NIS, NIKIbu);
            }                        
            ImGui::SameLine();
            ImGui::Text("Total siswa: %i", currentBarisTk);
        }
        showTableTK(tableDataTK);
    }
}

void Window::TableDataSekolah::uiTypeSd(){
    static char namasiswa[256], namaIbu[256], asalTK[256];
    static int NIS, NIKIbu, jumlahSiswa, currentJumlahSiswa = 0;

    if (currentJumlahSiswa == 0){
        ImGui::Text("Masukkan dahulu jumlah siswa yang akan diinput\nJumlah siswa: ");
        ImGui::SameLine();
        ImGui::InputInt("##Jumlahsiswa", &jumlahSiswa);
        if (ImGui::Button("Tambah siswa")){
            currentJumlahSiswa = jumlahSiswa;
        }
    } else {
        ImGui::Text("Table data SD");
        ImGui::Text("Nama siswa");
        ImGui::SameLine();
        ImGui::InputText("##Namasiswa", namasiswa, IM_ARRAYSIZE(namasiswa));
        ImGui::Text("NIS");
        ImGui::SameLine();
        ImGui::InputInt("##NIS", &NIS);
        ImGui::Text("Nama Ibu");
        ImGui::SameLine();
        ImGui::InputText("##Namaibu", namaIbu, IM_ARRAYSIZE(namaIbu));
        ImGui::Text("NIK Ibu");
        ImGui::SameLine();
        ImGui::InputInt("##NIKIbu", &NIKIbu);
        ImGui::Text("Asal TK");
        ImGui::SameLine();
        ImGui::InputText("##AsalTk", asalTK, IM_ARRAYSIZE(asalTK));
        string convertedNama = namasiswa, convertedNamaIbu = namaIbu, convertedAsalTK = asalTK;
        if (currentJumlahSiswa == currentBarisSd){
                ImGui::Text("Melebihi batas jumlah siswa");
        } else { 
            if (ImGui::Button("Tambah siswa")){
                submitToSDTable(convertedNama, convertedNamaIbu, NIS, NIKIbu, convertedAsalTK);
            }
            ImGui::SameLine();
            ImGui::Text("Total siswa: %i", currentBarisSd);
        }
        showTableSD(tableDataSD);
    }
}

void Window::TableDataSekolah::uiTypeSmp(){
    static char namasiswa[256], namaIbu[256], asalTK[256], asalSD[256];
    static int NIS, NIKIbu, noIjazahSD,jumlahSiswa = 0, currentJumlahSiswa = 0;

    if (currentJumlahSiswa == 0){
        ImGui::Text("Masukkan dahulu jumlah siswa yang akan diinput\nJumlah siswa: ");
        ImGui::SameLine();
        ImGui::InputInt("##Jumlahsiswa", &jumlahSiswa);
        if (ImGui::Button("Tambah siswa")){
            currentJumlahSiswa = jumlahSiswa;
        }
    } else {

        tableDataSMP[currentJumlahSiswa];
        tableDataSMP->dataSiswa[currentJumlahSiswa];
        ImGui::Text("Table data SMP");
        ImGui::Text("Nama siswa");
        ImGui::SameLine();
        ImGui::InputText("##Namasiswa", namasiswa, IM_ARRAYSIZE(namasiswa));
        ImGui::Text("NIS");
        ImGui::SameLine();
        ImGui::InputInt("##NIS", &NIS);
        ImGui::Text("Nama Ibu");
        ImGui::SameLine();
        ImGui::InputText("##Namaibu", namaIbu, IM_ARRAYSIZE(namaIbu));
        ImGui::Text("NIK Ibu");
        ImGui::SameLine();
        ImGui::InputInt("##NIKIbu", &NIKIbu);
        ImGui::Text("Asal TK");
        ImGui::SameLine();
        ImGui::InputText("##AsalTk", asalTK, IM_ARRAYSIZE(asalTK));
        ImGui::Text("Asal SD");
        ImGui::SameLine();
        ImGui::InputText("##AsalSD", asalSD, IM_ARRAYSIZE(asalSD));
        ImGui::Text("No Ijazah SD");
        ImGui::SameLine();
        ImGui::InputInt("##NoIjazahSD", &noIjazahSD);
        string convertedNama = namasiswa, convertedNamaIbu = namaIbu, convertedAsalTK = asalTK, convertedAsalSd = asalSD;

        if (currentJumlahSiswa == currentBarisSmp){
            ImGui::Text("Melebihi batas jumlah siswa");
        } else {
            if (ImGui::Button("Tambah siswa")){
                submitToSMPTable(convertedNama, convertedNamaIbu, NIS, NIKIbu, convertedAsalTK, convertedAsalSd, noIjazahSD);
            }
            ImGui::SameLine();
            ImGui::Text("Total siswa: %i", currentBarisSmp);
        }
        showTableSMP(tableDataSMP);
    }
}

void Window::TableDataSekolah::uiTypeSma(){
    static char namasiswa[256], namaIbu[256], asalTK[256], asalSD[256], asalSMP[256];
    static int NIS, NIKIbu, noIjazahSD, noIjazahSMP, jumlahSiswa = 0, currentJumlahSiswa = 0;

    if (currentJumlahSiswa == 0){
        ImGui::Text("Masukkan dahulu jumlah siswa yang akan diinput\nJumlah siswa: ");
        ImGui::SameLine();
        ImGui::InputInt("##Jumlahsiswa", &jumlahSiswa);
        if (ImGui::Button("Tambah siswa")){
            currentJumlahSiswa = jumlahSiswa;
        }
    } else {
        tableDataSMA[currentJumlahSiswa];
        tableDataSMA->dataSiswa[currentJumlahSiswa];

        ImGui::Text("Table data SMA");
        ImGui::Text("Nama siswa");
        ImGui::SameLine();
        ImGui::InputText("##Namasiswa", namasiswa, IM_ARRAYSIZE(namasiswa));
        ImGui::Text("NIS");
        ImGui::SameLine();
        ImGui::InputInt("##NIS", &NIS);
        ImGui::Text("Nama Ibu");
        ImGui::SameLine();
        ImGui::InputText("##Namaibu", namaIbu, IM_ARRAYSIZE(namaIbu));
        ImGui::Text("NIK Ibu");
        ImGui::SameLine();
        ImGui::InputInt("##NIKIbu", &NIKIbu);
        ImGui::Text("Asal TK");
        ImGui::SameLine();
        ImGui::InputText("##AsalTk", asalTK, IM_ARRAYSIZE(asalTK));
        ImGui::Text("Asal SD");
        ImGui::SameLine();
        ImGui::InputText("##AsalSD", asalSD, IM_ARRAYSIZE(asalSD));
        ImGui::Text("No Ijazah SD");
        ImGui::SameLine();
        ImGui::InputInt("##NoIjazahSD", &noIjazahSD);
        ImGui::Text("Asal SMP");
        ImGui::SameLine();
        ImGui::InputText("##AsalSMP", asalSMP, IM_ARRAYSIZE(asalSMP));
        ImGui::Text("No Ijazah SMP");
        ImGui::SameLine();
        ImGui::InputInt("##NoIjazahSMP", &noIjazahSMP);
        string convertedNama = namasiswa, convertedNamaIbu = namaIbu, convertedAsalTK = asalTK, convertedAsalSd = asalSD, convertedAsalSMP = asalSMP;
        if (currentJumlahSiswa == currentBarisSma){
            ImGui::Text("Melebihi batas jumlah siswa");
        } else {
            if (ImGui::Button("Tambah siswa")){
                submitToSMATable(convertedNama, convertedNamaIbu, NIS, NIKIbu, convertedAsalTK, convertedAsalSd, noIjazahSD, convertedAsalSMP, noIjazahSMP);
            }
            ImGui::SameLine();
            ImGui::Text("Total siswa: %i", currentBarisSma);
        }
            showTableSMA(tableDataSMA);
        }
}

void Window::TableDataSekolah::deleteDataSiswaTypeTk(TKTable tableData[], int& currentBarisTk){
    tableData[currentBarisTk].dataSiswa[currentBarisTk].namasiswa = "";
    tableData[currentBarisTk].dataSiswa[currentBarisTk].NIS = 0;
    tableData[currentBarisTk].dataSiswa[currentBarisTk].NamaIbu = "";
    tableData[currentBarisTk].dataSiswa[currentBarisTk].NIKIbu = 0;
    currentBarisTk--;
}

void Window::TableDataSekolah::deleteDataSiswaTypeSd(SDTable tableData[], int& currentBarisSd){
    tableData[currentBarisSd].dataSiswa[currentBarisSd].namasiswa = "";
    tableData[currentBarisSd].dataSiswa[currentBarisSd].NIS = 0;
    tableData[currentBarisSd].dataSiswa[currentBarisSd].NamaIbu = "";
    tableData[currentBarisSd].dataSiswa[currentBarisSd].NIKIbu = 0;
    tableData[currentBarisSd].asalTK = "";
    currentBarisSd--;
}

void Window::TableDataSekolah::deleteDataSiswaTypeSmp(SMPTable tableData[], int& currentBarisSmp){
    tableData[currentBarisSmp].dataSiswa[currentBarisSmp].namasiswa = "";
    tableData[currentBarisSmp].dataSiswa[currentBarisSmp].NIS = 0;
    tableData[currentBarisSmp].dataSiswa[currentBarisSmp].NamaIbu = "";
    tableData[currentBarisSmp].dataSiswa[currentBarisSmp].NIKIbu = 0;
    tableData[currentBarisSmp].asalTK = "";
    tableData[currentBarisSmp].asalSD = "";
    tableData[currentBarisSmp].noIjazahSD = 0;
    currentBarisSmp--;
}

void Window::TableDataSekolah::deleteDataSiswaTypeSma(SMATable tableData[], int& currentBarisSma){
    tableData[currentBarisSma].dataSiswa[currentBarisSma].namasiswa = "";
    tableData[currentBarisSma].dataSiswa[currentBarisSma].NIS = 0;
    tableData[currentBarisSma].dataSiswa[currentBarisSma].NamaIbu = "";
    tableData[currentBarisSma].dataSiswa[currentBarisSma].NIKIbu = 0;
    tableData[currentBarisSma].asalTK = "";
    tableData[currentBarisSma].asalSD = "";
    tableData[currentBarisSma].noIjazahSD = 0;
    tableData[currentBarisSma].asalSMP = "";
    tableData[currentBarisSma].noIjazahSMP = 0;
    currentBarisSma--;
}

void Window::TableDataSekolah::editDataSiswaTypeSd(SDTable tableData[], int& currentBaris){
    ImGui::PushID(currentBarisSd);
    if (ImGui::Button("Edit"))
    {
        ImGui::OpenPopup("Edit data"); // Open the popup with a specific ID
    }
    ImGui::PopID();

    // BeginPopup returns true only if the popup is open
    if (ImGui::BeginPopup("Edit data"))
    {
        ImGui::Text("Nama Siswa: %s", tableData[currentBaris].dataSiswa[currentBaris].namasiswa.c_str());
        ImGui::Separator();
        if (ImGui::MenuItem("Close"))
        {
            ImGui::CloseCurrentPopup(); // Close the current popup
        }
        ImGui::EndPopup();
    }
}