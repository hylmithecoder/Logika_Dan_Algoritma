#include <HandleWindow.hpp>

void Window::Pertemuan10::windowPer10(){
    Begin("Pertemuan 10");
    soal1.handleSoal1();
    soal2.handleSoal2();
    End();
}

void Window::Pertemuan10::Soal1::handleSoal1(){
    static int gajiKotor = 0, jumlahKaryawan = 0, setJumlahKaryawan = 0, jumlahGaji = 0, jumlahPajak = 0, golongan = 0, currentGaji = 0, hariKerja = 0, gajiBersih = 0;
    static char setNamaKaryawan[256] = "";
    Text("Soal 1");
    if (setJumlahKaryawan != 0){
        Text("1. Nama Karyawan: ");
        SameLine();
        InputText("##setNamaKaryawan", setNamaKaryawan, IM_ARRAYSIZE(setNamaKaryawan));
        Text("2. Golongan: ");
        SameLine();
        InputInt("##golongan", &golongan);
        Text("3. Hari Kerja: ");
        SameLine();
        InputInt("##hariKerja", &hariKerja);
        if (setJumlahKaryawan != currentBaris){
            if (Button("Tambah Pegawai")){
                currentGaji = tetapkanGaji(golongan);
                currentGaji = currentGaji + setTunjangan(golongan, currentGaji);
                currentGaji = currentGaji + uangTransport(hariKerja);
                gajiKotor = currentGaji;
                gajiBersih = gajiKotor - PPH(gajiKotor);
                jumlahGaji += gajiBersih;
                jumlahPajak += PPH(gajiKotor);
                string convertedName = setNamaKaryawan;
                inputPegawaiHandler(convertedName, currentGaji, gajiKotor, golongan, peg);
                currentGaji = 0;
                currentBaris++;
            }
        } else {
            Text("Melebihi batas jumlah karyawan");
        }
        
        showPegawai(peg);        
    } else {
        Text("Masukkan jumlah karyawan: ");
        InputInt("##jumlahKaryawan", &jumlahKaryawan);
        if (Button("set jumlah karyawan")){
            setJumlahKaryawan = jumlahKaryawan;
        }
    }

    if (currentBaris > 0){
        // for (int i = 0; i < currentBaris; i++){
            Text("Total Penghasilan bersih semua karyanwan: %d", jumlahGaji);
            Text("Total pajak semua karyawan: %d", jumlahPajak);
        // }
    }
}

void Window::Pertemuan10::Soal1::inputPegawaiHandler(string setNamaKaryawan, int gajiBersih, int gajiKotor, int golongan, Pegawai peg[]){
    cout << "Nama Karyawan: " << setNamaKaryawan << endl << "Gaji Bersih: " << gajiBersih << endl << "Gaji Kotor: " << gajiKotor << endl << "Golongan: " << golongan << endl << "" << endl;
    peg[currentBaris+1].nama = setNamaKaryawan;
    peg[currentBaris+1].gaji = gajiBersih;
    peg[currentBaris+1].gajiKotor = gajiKotor;
    peg[currentBaris+1].golongan = golongan;
}

void Window::Pertemuan10::Soal1::showPegawai(Pegawai peg[]){
    if (BeginTable("Table Data TK", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        TableSetupColumn("Nama Pegawai");
        TableSetupColumn("Golongan");
        TableSetupColumn("Gaji Kotor");
        TableSetupColumn("Gaji Bersih");

        // Display headers
        TableHeadersRow();

        for (int i = 1; i <= currentBaris; ++i){
            // Text("Kolom ke %i", i);
            TableNextRow(); // Start a new row

            TableSetColumnIndex(0); // Go to the first column
            Text("%s", peg[i].nama.c_str());
            
            TableSetColumnIndex(1); // Go to the first column
            Text("%i", peg[i].golongan);
            
            TableSetColumnIndex(2); // Go to the first column
            Text("%i", peg[i].gajiKotor);
            
            TableSetColumnIndex(3); // Go to the first column
            Text("%i", peg[i].gaji);

        }

        EndTable();
    }
}

void Window::Pertemuan10::Soal2::handleSoal2(){
    static int keuntunganLaba = 0, setKeuntunganLaba = 0, totalLaba = 0, totalProduksiKursi = 0 , totalProdusksiMeja = 0, hargaTotalKursi = 0, hargaTotalMeja = 0;
    static vector<int> labaTarget;    
    Separator();
    Text("Soal 2");
    Text("Masukkan Target keuntungan laba: ");
    InputInt("##keuntunganLaba", &keuntunganLaba);

    if (Button("Set keuntungan laba")){
        setKeuntunganLaba = keuntunganLaba;
        labaTarget = totalTargetLaba(targetLaba);
        totalProduksiKursi = produksiKursi(labaTarget[0]);
        totalProdusksiMeja = produksiMeja(labaTarget[0]);
        hargaTotalKursi = totalProduksiKursi * HK;
        hargaTotalMeja = totalProdusksiMeja * HM;
        totalLaba = hargaTotalKursi + hargaTotalMeja;

        if (totalLaba < targetLaba && totalLaba >= 30000) {
            int kursiNeeded = (targetLaba - totalLaba) / HK;
            int mejaNeeded = (targetLaba - totalLaba) / HM;
            totalProduksiKursi += kursiNeeded;
            totalProdusksiMeja += mejaNeeded;
            hargaTotalKursi = totalProduksiKursi * HK;
            hargaTotalMeja = totalProdusksiMeja * HM;
            totalLaba = hargaTotalKursi + hargaTotalMeja;
            cout << "Target Laba: " << targetLaba << endl;
            cout << "Rekomendasi Produksi Kursi: " << totalProduksiKursi << endl;
            cout << "Rekomendasi Produksi Meja: " << totalProdusksiMeja << endl;
            cout << "laba kursi: " << hargaTotalKursi << endl;
            cout << "laba meja: " << hargaTotalMeja << endl;
            cout << "Total Laba: " << totalLaba << endl;
        }
    }

    // if (keuntunganLaba != 0){
    //     Text("Target Laba: %i", setKeuntunganLaba);
    //     Text("Rekomendasi Produksi Kursi: %i", totalProduksiKursi);
    //     Text("Rekomendasi Produksi Meja: %i", totalProdusksiMeja);
    //     Text("laba kursi: %i", hargaTotalKursi);
    //     Text("laba meja: %i", hargaTotalMeja);
    //     Text("Total Laba: %i", totalLaba);
    // }
}