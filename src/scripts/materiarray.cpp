#include <HandleWindow.hpp>

void Window::TableDataSekolah::uidataSekolah(){
    static int current_item_index = 0;
    const char* choice[] = { "TK", "SD", "SMP", "SMA" };
    static char namasiswa[256], namaIbu[256], asalTK[256], asalSD[256], asalSMP[256];
    static int NIS, NIKIbu, noIjazahSD, noIjazahSMP;
    Begin("Table data sekolah");
    Text("Sekolah");
    Separator();
    Combo("##Pilih Bangun Type", &current_item_index, choice, IM_ARRAYSIZE(choice));
    if (current_item_index == 0){
        uiTypeTk();
    } else if (current_item_index == 1){
        uiTypeSd();
    } else if (current_item_index == 2){
        uiTypeSmp();
    } else if (current_item_index == 3){
        uiTypeSma();
    }
    
    End();
}

void Window::TableDataSekolah::submitToTKTable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu){
    // cout << tableDataTK[currentBarisTk].dataSiswa[currentBarisTk].namasiswa << endl;
    tableDataTK[currentBarisTk+1].namasiswa = namasiswa;
    tableDataTK[currentBarisTk+1].NIS = NIS;
    tableDataTK[currentBarisTk+1].NamaIbu = namaIbu;
    tableDataTK[currentBarisTk+1].NIKIbu = NIKIbu;

    currentBarisTk++;
    cout << "Baris TK: " << currentBarisTk << endl;
}

void Window::TableDataSekolah::submitToSDTable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu, string& asalTK){
    tableDataSD[currentBarisSd+1].namasiswa = namasiswa;
    tableDataSD[currentBarisSd+1].NamaIbu = namaIbu;
    tableDataSD[currentBarisSd+1].NIS = NIS;
    tableDataSD[currentBarisSd+1].NIKIbu = NIKIbu;
    tableDataSD[currentBarisSd+1].asalTK = asalTK;

    currentBarisSd++;
}

void Window::TableDataSekolah::submitToSMPTable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu, string& asalTK, string& asalSd, int& noIjazahSD){
    tableDataSMP[currentBarisSmp+1].namasiswa = namasiswa;
    tableDataSMP[currentBarisSmp+1].NamaIbu = namaIbu;
    tableDataSMP[currentBarisSmp+1].NIS = NIS;
    tableDataSMP[currentBarisSmp+1].NIKIbu = NIKIbu;
    tableDataSMP[currentBarisSmp+1].asalTK = asalTK;
    tableDataSMP[currentBarisSmp+1].asalSD = asalSd;
    tableDataSMP[currentBarisSmp+1].noIjazahSD = noIjazahSD;

    currentBarisSmp++;
}

void Window::TableDataSekolah::submitToSMATable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu, string& asalTK,  string& asalSd, int& noIjazahSD, string& asalSMP, int& noIjazahSmp){
    tableDataSMA[currentBarisSma+1].namasiswa = namasiswa;
    tableDataSMA[currentBarisSma+1].NamaIbu = namaIbu;
    tableDataSMA[currentBarisSma+1].NIS = NIS;
    tableDataSMA[currentBarisSma+1].NIKIbu = NIKIbu;
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

    if (BeginTable("Table Data TK", 5, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        TableSetupColumn("Nama Siswa");
        TableSetupColumn("NIS");
        TableSetupColumn("Nama Ibu");
        TableSetupColumn("NIK Ibu");
        TableSetupColumn("Action");

        // Display headers
        TableHeadersRow();

        for (int i = 1; i <= currentBarisTk; ++i){
            // Text("Kolom ke %i", i);
            TableNextRow(); // Start a new row

            TableSetColumnIndex(0); // Go to the first column
            Text("%s", tableData[i].namasiswa.c_str());
            
            TableSetColumnIndex(1); // Go to the first column
            Text("%i", tableData[i].NIS);
            
            TableSetColumnIndex(2); // Go to the first column
            Text("%s", tableData[i].NamaIbu.c_str());
            
            TableSetColumnIndex(3); // Go to the first column
            Text("%i", tableData[i].NIKIbu);

            TableSetColumnIndex(4); // Go to the first column
            PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.1f, 0.2f, 1.0f));
            PushID(i);
            if (Button("Delete")){
                deleteDataSiswaTypeTk(tableData, currentBarisTk);
            }
            PopID();
            PopStyleColor();
        }

        EndTable();
    }    
}

void Window::TableDataSekolah::showTableSD(SDTable tableData[]){
    if (currentBarisSd < 0){
        return;
    }

    if (BeginTable("Table Data SD", 6, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        TableSetupColumn("Nama Siswa");
        TableSetupColumn("NIS");
        TableSetupColumn("Nama Ibu");
        TableSetupColumn("NIK Ibu");
        TableSetupColumn("Asal TK");
        TableSetupColumn("Action");

        // Display headers
        TableHeadersRow();

        for (int i = 1; i <= currentBarisSd; ++i){
            // Text("Kolom ke %i", i);
            TableNextRow(); // Start a new row

            TableSetColumnIndex(0); // Go to the first column
            Text("%s", tableData[i].namasiswa.c_str());
            
            TableSetColumnIndex(1); // Go to the first column
            Text("%i", tableData[i].NIS);
            
            TableSetColumnIndex(2); // Go to the first column
            Text("%s", tableData[i].NamaIbu.c_str());
            
            TableSetColumnIndex(3); // Go to the first column
            Text("%i", tableData[i].NIKIbu);

            TableSetColumnIndex(4); // Go to the first column
            Text("%s", tableData[i].asalTK.c_str());

            TableSetColumnIndex(5); // Go to the first column
            PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.1f, 0.2f, 1.0f));
            PushID(i);
            if (Button("Delete")){
                deleteDataSiswaTypeSd(tableData, currentBarisSd);
            }
            PopID();
            PopStyleColor();
        }

        EndTable();
    }
}

void Window::TableDataSekolah::showTableSMP(SMPTable tableData[]){
    if (currentBarisSmp < 0){
        return;
    }

    if (BeginTable("Table Data SMP", 8, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        TableSetupColumn("Nama Siswa");
        TableSetupColumn("NIS");
        TableSetupColumn("Nama Ibu");
        TableSetupColumn("NIK Ibu");
        TableSetupColumn("Asal TK");
        TableSetupColumn("Asal SD");
        TableSetupColumn("No Ijazah SD");
        TableSetupColumn("Action");

        // Display headers
        TableHeadersRow();

        for (int i = 1; i <= currentBarisSmp; ++i){
            // Text("Kolom ke %i", i);
            TableNextRow(); // Start a new row

            TableSetColumnIndex(0); // Go to the first column
            Text("%s", tableData[i].namasiswa.c_str());
            
            TableSetColumnIndex(1); // Go to the first column
            Text("%i", tableData[i].NIS);
            
            TableSetColumnIndex(2); // Go to the first column
            Text("%s", tableData[i].NamaIbu.c_str());
            
            TableSetColumnIndex(3); // Go to the first column
            Text("%i", tableData[i].NIKIbu);

            TableSetColumnIndex(4); // Go to the first column
            Text("%s", tableData[i].asalTK.c_str());

            TableSetColumnIndex(5); // Go to the first column
            Text("%s", tableData[i].asalSD.c_str());

            TableSetColumnIndex(6); // Go to the first column
            Text("%i", tableData[i].noIjazahSD);

            TableSetColumnIndex(7); // Go to the first column
            PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.1f, 0.2f, 1.0f));
            PushID(i);
            if (Button("Delete")){
                deleteDataSiswaTypeSmp(tableData, currentBarisSmp);
            }
            PopID();
            PopStyleColor();
        }

        EndTable();
    }
}

void Window::TableDataSekolah::showTableSMA(SMATable tableData[]){
    if (currentBarisSma < 0){
        return;
    }
    

    if (BeginTable("Table Data SMA", 10, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        TableSetupColumn("Nama Siswa");
        TableSetupColumn("NIS");
        TableSetupColumn("Nama Ibu");
        TableSetupColumn("NIK Ibu");
        TableSetupColumn("Asal TK");
        TableSetupColumn("Asal SD");
        TableSetupColumn("No Ijazah SD");
        TableSetupColumn("Asal SMP");
        TableSetupColumn("No Ijazah SMP");
        TableSetupColumn("Action");

        // Display headers
        TableHeadersRow();

        for (int i = 1; i <= currentBarisSma; ++i){
            // Text("Kolom ke %i", i);
            TableNextRow(); // Start a new row

            TableSetColumnIndex(0); // Go to the first column
            Text("%s", tableData[i].namasiswa.c_str());
            
            TableSetColumnIndex(1); // Go to the first column
            Text("%i", tableData[i].NIS);
            
            TableSetColumnIndex(2); // Go to the first column
            Text("%s", tableData[i].NamaIbu.c_str());
            
            TableSetColumnIndex(3); // Go to the first column
            Text("%i", tableData[i].NIKIbu);

            TableSetColumnIndex(4); // Go to the first column
            Text("%s", tableData[i].asalTK.c_str());

            TableSetColumnIndex(5); // Go to the first column
            Text("%s", tableData[i].asalSD.c_str());

            TableSetColumnIndex(6); // Go to the first column
            Text("%i", tableData[i].noIjazahSD);

            TableSetColumnIndex(7); // Go to the first column
            Text("%s", tableData[i].asalSMP.c_str());

            TableSetColumnIndex(8); // Go to the first column
            Text("%i", tableData[i].noIjazahSMP);

            TableSetColumnIndex(9); // Go to the first column
            PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.1f, 0.2f, 1.0f));
            PushID(i);
            if (Button("Delete")){
                deleteDataSiswaTypeSma(tableData, currentBarisSma);
            }
            PopID();
            PopStyleColor();
        }

        EndTable();
    }
}

void Window::TableDataSekolah::uiTypeTk(){
    static char* namasiswa, *namaIbu;
    static int NIS, NIKIbu, jumlahSiswa = 0, currentJumlahSiswa = 0;

    if (currentJumlahSiswa == 0){
        Text("Masukkan dahulu jumlah siswa yang akan diinput\nJumlah siswa: ");
        jumlahSiswa = inputInt("##Jumlahsiswa");
        if (Button("init jumlah siswa")){
            currentJumlahSiswa = jumlahSiswa;
        }
    } else {
        Text("Table data TK");
        Text("Nama siswa");
        namasiswa = inputText("##Namasiswa");
        Text("NIS");
        NIS = inputInt("##NIS");
        Text("Nama Ibu");
        namaIbu = inputText("##Namaibu");
        Text("NIK Ibu");
        SameLine();
        InputInt("##NIKIbu", &NIKIbu);
        string convertedNama = namasiswa, convertedNamaIbu = namaIbu;
        if (currentJumlahSiswa == currentBarisTk){
            Text("Melebihi batas jumlah siswa");
        } else {
            if (Button("Tambah siswa")){
                submitToTKTable(convertedNama, convertedNamaIbu, NIS, NIKIbu);
            }                        
            SameLine();
            Text("Total siswa: %i", currentBarisTk);
        }
        showTableTK(tableDataTK);
    }
}

void Window::TableDataSekolah::uiTypeSd(){
    static char* namasiswa, *namaIbu, asalTK[256];
    static int NIS, NIKIbu, jumlahSiswa, currentJumlahSiswa = 0;

    if (currentJumlahSiswa == 0){
        Text("Masukkan dahulu jumlah siswa yang akan diinput\nJumlah siswa: ");
        jumlahSiswa = inputInt("##Jumlahsiswa");
        if (Button("Tambah siswa")){
            currentJumlahSiswa = jumlahSiswa;
        }
    } else {
        Text("Table data SD");
        Text("Nama siswa");
        namasiswa = inputText("##Namasiswa");
        Text("NIS");
        NIS = inputInt("##NIS");
        Text("Nama Ibu");
        namaIbu = inputText("##Namaibu");
        Text("NIK Ibu");
        NIKIbu = inputInt("##NIKIbu");
        Text("Asal TK");
        SameLine();
        InputText("##AsalTK", asalTK, IM_ARRAYSIZE(asalTK));
        string convertedNama = namasiswa, convertedNamaIbu = namaIbu, convertedAsalTK = asalTK;
        if (currentJumlahSiswa == currentBarisSd){
                Text("Melebihi batas jumlah siswa");
        } else { 
            if (Button("Tambah siswa")){
                submitToSDTable(convertedNama, convertedNamaIbu, NIS, NIKIbu, convertedAsalTK);
            }
            SameLine();
            Text("Total siswa: %i", currentBarisSd);
        }
        showTableSD(tableDataSD);
    }
}

void Window::TableDataSekolah::uiTypeSmp(){
    static char* namasiswa, *namaIbu, *asalTK, *asalSD;
    static int NIS, NIKIbu, noIjazahSD,jumlahSiswa = 0, currentJumlahSiswa = 0;

    if (currentJumlahSiswa == 0){
        Text("Masukkan dahulu jumlah siswa yang akan diinput\nJumlah siswa: ");
        jumlahSiswa = inputInt("##Jumlahsiswa");
        if (Button("Tambah siswa")){
            currentJumlahSiswa = jumlahSiswa;
        }
    } else {
        Text("Table data SMP");
        Text("Nama siswa");
        namasiswa = inputText("##Namasiswa");
        Text("NIS");
        NIS = inputInt("##NIS");
        Text("Nama Ibu");
        namaIbu = inputText("##Namaibu");
        Text("NIK Ibu");
        NIKIbu = inputInt("##NIKIbu");
        Text("Asal TK");
        asalTK = inputText("##AsalTK");
        Text("Asal SD");
        asalSD = inputText("##AsalSD");
        Text("No Ijazah SD");
        noIjazahSD = inputInt("##NoIjazahSD");
        string convertedNama = namasiswa, convertedNamaIbu = namaIbu, convertedAsalTK = asalTK, convertedAsalSd = asalSD;

        if (currentJumlahSiswa == currentBarisSmp){
            Text("Melebihi batas jumlah siswa");
        } else {
            if (Button("Tambah siswa")){
                submitToSMPTable(convertedNama, convertedNamaIbu, NIS, NIKIbu, convertedAsalTK, convertedAsalSd, noIjazahSD);
            }
            SameLine();
            Text("Total siswa: %i", currentBarisSmp);
        }
        showTableSMP(tableDataSMP);
    }
}

void Window::TableDataSekolah::uiTypeSma(){
    static char* namasiswa, *namaIbu, *asalTK, *asalSD, *asalSMP;
    static int NIS, NIKIbu, noIjazahSD, noIjazahSMP, jumlahSiswa = 0, currentJumlahSiswa = 0;

    if (currentJumlahSiswa == 0){
        Text("Masukkan dahulu jumlah siswa yang akan diinput\nJumlah siswa: ");
        SameLine();
        InputInt("##Jumlahsiswa", &jumlahSiswa);
        if (Button("Tambah siswa")){
            currentJumlahSiswa = jumlahSiswa;
        }
    } else {
        Text("Table data SMA");
        Text("Nama siswa");
        namasiswa = inputText("##Namasiswa");
        Text("NIS");
        NIS = inputInt("##NIS");
        Text("Nama Ibu");
        namaIbu = inputText("##Namaibu");
        Text("NIK Ibu");
        NIKIbu = inputInt("##NIKIbu");
        Text("Asal TK");
        asalTK = inputText("##AsalTK");
        Text("Asal SD");
        asalSD = inputText("##AsalSD");
        Text("No Ijazah SD");
        noIjazahSD = inputInt("##NoIjazahSD");
        Text("Asal SMP");
        asalSMP = inputText("##AsalSMP");
        Text("No Ijazah SMP");
        noIjazahSMP = inputInt("##NoIjazahSMP");
        string convertedNama = namasiswa, convertedNamaIbu = namaIbu, convertedAsalTK = asalTK, convertedAsalSd = asalSD, convertedAsalSMP = asalSMP;
        if (currentJumlahSiswa == currentBarisSma){
            Text("Melebihi batas jumlah siswa");
        } else {
            if (Button("Tambah siswa")){
                submitToSMATable(convertedNama, convertedNamaIbu, NIS, NIKIbu, convertedAsalTK, convertedAsalSd, noIjazahSD, convertedAsalSMP, noIjazahSMP);
            }
            SameLine();
            Text("Total siswa: %i", currentBarisSma);
        }
            showTableSMA(tableDataSMA);
        }
}

void Window::TableDataSekolah::deleteDataSiswaTypeTk(TKTable tableData[], int& currentBarisTk){
    tableData[currentBarisTk].namasiswa = "";
    tableData[currentBarisTk].NIS = 0;
    tableData[currentBarisTk].NamaIbu = "";
    tableData[currentBarisTk].NIKIbu = 0;
    currentBarisTk--;
}

void Window::TableDataSekolah::deleteDataSiswaTypeSd(SDTable tableData[], int& currentBarisSd){
    tableData[currentBarisSd].namasiswa = "";
    tableData[currentBarisSd].NIS = 0;
    tableData[currentBarisSd].NamaIbu = "";
    tableData[currentBarisSd].NIKIbu = 0;
    tableData[currentBarisSd].asalTK = "";
    currentBarisSd--;
}

void Window::TableDataSekolah::deleteDataSiswaTypeSmp(SMPTable tableData[], int& currentBarisSmp){
    tableData[currentBarisSmp].namasiswa = "";
    tableData[currentBarisSmp].NIS = 0;
    tableData[currentBarisSmp].NamaIbu = "";
    tableData[currentBarisSmp].NIKIbu = 0;
    tableData[currentBarisSmp].asalTK = "";
    tableData[currentBarisSmp].asalSD = "";
    tableData[currentBarisSmp].noIjazahSD = 0;
    currentBarisSmp--;
}

void Window::TableDataSekolah::deleteDataSiswaTypeSma(SMATable tableData[], int& currentBarisSma){
    tableData[currentBarisSma].namasiswa = "";
    tableData[currentBarisSma].NIS = 0;
    tableData[currentBarisSma].NamaIbu = "";
    tableData[currentBarisSma].NIKIbu = 0;
    tableData[currentBarisSma].asalTK = "";
    tableData[currentBarisSma].asalSD = "";
    tableData[currentBarisSma].noIjazahSD = 0;
    tableData[currentBarisSma].asalSMP = "";
    tableData[currentBarisSma].noIjazahSMP = 0;
    currentBarisSma--;
}

void Window::TableDataSekolah::editDataSiswaTypeSd(SDTable tableData[], int& currentBaris){
    PushID(currentBarisSd);
    if (Button("Edit"))
    {
        OpenPopup("Edit data"); // Open the popup with a specific ID
    }
    PopID();

    // BeginPopup returns true only if the popup is open
    if (BeginPopup("Edit data"))
    {
        Text("Nama Siswa: %s", tableData[currentBaris].namasiswa.c_str());
        Separator();
        if (MenuItem("Close"))
        {
            CloseCurrentPopup(); // Close the current popup
        }
        EndPopup();
    }
}