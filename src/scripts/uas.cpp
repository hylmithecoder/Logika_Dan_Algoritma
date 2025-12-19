#include "imgui.h"
#include <HandleWindow.hpp>
#include <algorithm>

void Window::UASSemester1::handleWindow() {
    static int current_item_index = 0;
    const char* choice[] = { "Soal 2", "Soal 3", "Soal 4", "Soal 5", "Soal 6", "Soal 7", "Soal 8", "Soal 9", "Soal 10", "Soal 11", "Soal 12" };
    Begin("UAS Semester 1 Logika dan Algoritma");
    Text("JAWABAN UAS SEMESTER 1 LOGIKA DAN ALGORITMA PEMROGRAMAN");
    Text("Nama: Hylmi Muhammad Fiary Mahdi");
    Text("NIM : 2505181108");
    Separator();

    Text("Pilih Soal");
    Combo("##Pilih Soal", &current_item_index, choice, IM_ARRAYSIZE(choice));
    if (current_item_index == 0){
        soalNo2();
    } else if (current_item_index == 1){
        soalNo3();
    } else if (current_item_index == 2){
        soalNo4();
    } else if (current_item_index == 3){
        soalNo5();
    } else if (current_item_index == 4){
        soalNo6();
    } else if (current_item_index == 5){
        soalNo7();
    } else if (current_item_index == 6){
        soalNo8();
    } else if (current_item_index == 7){
        soalNo9();
    } else if (current_item_index == 8){
        soalNo10();
    } else if (current_item_index == 9){
        soalNo11();
    } else if (current_item_index == 10){
        soalNo12();
    }

    End();
}

void Window::UASSemester1::soalNo2() {
    static int gaji, tunjangan, potongan, jumlahKaryawan, setJumlahKaryawan;
    static char buffer[256];
    Text("Soal Nomor 2");
    Text("Input data karyawan. menghitung gaji pokok, tunjangan, dan potongan, menampilkan slip gaji");
    if (setJumlahKaryawan != 0){
        Text("Jumlah Karyawan: %d", setJumlahKaryawan);
        Text("Masukkan Nama: ");
        InputText("##nama siswa", buffer, IM_ARRAYSIZE(buffer));
        Text("Masukkan Gaji: ");
        InputInt("##gaji", &gaji);
        Text("Masukkan Tunjangan: ");
        InputInt("##tunjangan", &tunjangan);
        Text("Masukkan Potongan: ");
        InputInt("##potongan", &potongan);
        if (Button("Tambah Karyawan")){
            int slipGaji = gaji + tunjangan - potongan;
            AddDataKaryawan(buffer, tunjangan, slipGaji, potongan, gaji);
        }

        if (dataKaryawan.size() == setJumlahKaryawan){
            ShowTableKaryawan();
        }
    } else {
        Text("Jumlah Karyawan: ");
        InputInt("##jumlah karyawan", &jumlahKaryawan);
        if (Button("Set Jumlah Karyawan"))
            setJumlahKaryawan = jumlahKaryawan;
    }
}

void Window::UASSemester1::AddDataKaryawan(string nama, int tunjangan, int slipGaji, int potongan, int gaji) {
    dataKaryawan.push_back({nama, tunjangan, slipGaji, potongan, gaji});
}

void Window::UASSemester1::ShowTableKaryawan() {
    if (dataKaryawan.size() == 0){
        return;
    }
    
    if (BeginTable("Table Data Karyawan", 5, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        TableSetupColumn("Nama");
        TableSetupColumn("Tunjangan");
        TableSetupColumn("Slip Gaji");
        TableSetupColumn("Potongan");
        TableSetupColumn("Gaji");
        TableHeadersRow();
        for (int i = 0; i < dataKaryawan.size(); i++) {
            TableNextRow();
            TableSetColumnIndex(0);
            Text("%s", dataKaryawan[i].nama.c_str());
            TableSetColumnIndex(1);
            Text("%d", dataKaryawan[i].tunjangan);
            TableSetColumnIndex(2);
            Text("%d", dataKaryawan[i].slipGaji);
            TableSetColumnIndex(3);
            Text("%d", dataKaryawan[i].potongan);
            TableSetColumnIndex(4);
            Text("%d", dataKaryawan[i].gaji);
        }
        EndTable();
    }
}

void Window::UASSemester1::soalNo3(){
    static int setTargetArray = 0, arrayInput = 0, angka = 0, currentInput = 0;
    static vector<int> arrayNormal;
    
    Text("Soal 3");
    Text("Buat Program yang memisahkan array ke dalam dua array baru: arrayGenap dan arrayGanjil");
    if (setTargetArray != 0){
        Text("Masukkan angka sebanyak %i kali", setTargetArray);
        InputInt("##angka", &angka);

        if (currentInput >= setTargetArray){
            showArray("Array Genap", genapArray);
            showArray("Array Ganjil", ganjilArray);
        } else {
            if (Button("Input")){
                int getAngka = angka;
                cout << "current input: " << getAngka << endl;
                arrayNormal.push_back(getAngka);
                currentInput++;
                tentukanArrayGenap(arrayNormal);
            }
        }
    } else {
        Text("Masukkan banyak elemen dalam array:");
        SameLine();
        InputInt("##InputBanyakElemen", &arrayInput);
        if (Button("Buat Array")){
            setTargetArray = arrayInput;
        }
    }
}

void Window::UASSemester1::soalNo4() {
    static int setPenjualan;
    Separator();
    Text("Soal Nomor 4");
    Text("Input data penjualan. menghitung total penjualan");
    

    if (penjualan.size() == 7){
        int totalPenjualan = 0;
        for (int i = 0; i < penjualan.size(); i++){
            totalPenjualan += penjualan[i];
        }
        Text("Total Penjualan: %d", totalPenjualan);
    } else {    
        Text("Masukkan Penjualan: ");
        InputInt("##penjualan", &setPenjualan);
        if (Button("Tambah Penjualan")){
            penjualan.push_back(setPenjualan);
        }
    }
}

void Window::UASSemester1::soalNo5() {
    static int setNilai, nilai = 0;
    Separator();
    Text("Soal Nomor 5");
    Text("Kasus penjumlahan deret, Gunakan rekursif untuk menghitung jumlah bilangan dari 1 sampai n");
    if (setNilai != 0){
        cetakDeret(setNilai);
    } else {
        Text("Masukkan Nilai: ");
        InputInt("##nilai", &nilai);
        if (Button("Tambah Nilai")){
            setNilai = nilai;
        }
    }
}

void Window::UASSemester1::cetakDeret(int n) {
    if (n == 1){
        Text("%d", n);
    } else {
        cetakDeret(n - 1);
        Text("%d", n);
    }
}

void Window::UASSemester1::soalNo6() {
    static int setNilai, nilai = 0;
    Separator();
    Text("Soal Nomor 6");
    Text("Input data nilai. mencetak mundur");
    if (setNilai != 0){
        cetakMundur(setNilai);
    } else {
        Text("Masukkan Nilai: ");
        InputInt("##nilai", &setNilai);
        if (Button("Tambah Nilai")){
            setNilai = nilai;
        }
    }
}

void Window::UASSemester1::cetakMundur(int n) {
    for (int i = n; i >= 0; i--){
        Text("%d", i);
    }
}

void Window::UASSemester1::soalNo7() {
    static int setNilai, nilai = 0;
    Separator();
    Text("Soal Nomor 7");
    Text("Perbandingan loop rekursif dan iterasi");
    if (setNilai != 0){
        Text("Iterasi");
        cetakDeretIterasi(setNilai);
        Text("Rekursif");
        cetakDeret(setNilai);
    } else {
        Text("Masukkan Nilai: ");
        InputInt("##nilai", &nilai);
        if (Button("Tambah Nilai")){
            setNilai = nilai;
        }
    }   
}

void Window::UASSemester1::cetakDeretIterasi(int n) {
    for (int i = 1; i <= n; i++){
        Text("%d", i);
    }
}

void Window::UASSemester1::soalNo8() {
    static int nilai = 0, setNilai;
    Separator();
    Text("Soal Nomor 8");
    Text("Input data nilai. mencetak fibonacci");
    if (setNilai != 0){
        cetakFibonacci(setNilai);
    } else {
        Text("Masukkan Nilai: ");
        InputInt("##nilai1", &nilai);
        if (Button("Tambah Nilai ##1")){
            setNilai = nilai;
        }
    }
}

void Window::UASSemester1::cetakFibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 3; i <= n; i++){
        c = a + b;
        Text("%d", c);
        a = b;
        b = c;
    }   
}

void Window::UASSemester1::soalNo9() {
    static int setNilai, nilai = 0;
    Separator();
    Text("Soal Nomor 9");
    Text("Kasus operasi Stack, Buat program c++ yang mengimplementasikan push dan pop");
    Text("Masukkan Nilai: ");
    InputInt("##nilai", &nilai);
    if (Button("Tambah Nilai")){
        setNilai = nilai;
        array.push_back(setNilai);
    }
    if (Button("Pop")){
        array.pop_back();
    }
    
    ShowTables(array);
}

void Window::UASSemester1::ShowTables(vector<int> currentArray) {
    for (int i = 0; i < currentArray.size(); i++){
        Text("%d", currentArray[i]);
    }
}


void Window::UASSemester1::soalNo10() {
    static int buffer = 0, setArraySize, setNilai;
    Separator();
    Text("Soal Nomor 10");
    Text("Input data nilai. mengurutkan array");
    if (setArraySize != 0){
        Text("Masukkan Suatu Nilai: ");
        InputInt("##nilai", &buffer);
        if (Button("Tambah Nilai")){
            setNilai = buffer;
            array.push_back(buffer);
            buffer = 0;
        }
        if (array.size() == setArraySize){
            SortArray(array);
        }
    } else {
        Text("Masukkan Nilai Kapasitas Array: ");
        InputInt("##arraySize", &buffer);
        if (Button("Set Array")){
            setArraySize = buffer;
            buffer = 0;
        }
    }
}

void Window::UASSemester1::SortArray(vector<int> currentArray) {
    sort(currentArray.begin(), currentArray.end());
    for (int i = 0; i < currentArray.size(); i++){
        Text("%d", currentArray[i]);
    }
}

void Window::UASSemester1::soalNo11() {
    Separator();   
}

void Window::UASSemester1::soalNo12() {
    static int buffer = 0, setMahasiswaSize, setNilai;
    static char bufferString[256];
    Separator();
    Text("Soal Nomor 12");
    Text("Input data mahasiswa. mengurutkan ranking sesuai nilai");
    if (setMahasiswaSize != 0){
        Text("Masukkan Nama: ");
        InputText("##nama", bufferString, IM_ARRAYSIZE(bufferString));
        Text("Masukkan Nilai: ");
        InputInt("##nilai2", &buffer);
        if (Button("Tambah Nilai")){
            setNilai = buffer;
            mahasiswa.push_back({bufferString, buffer});
            buffer = 0;
            memset(bufferString, 0, IM_ARRAYSIZE(bufferString));
        }

        if (mahasiswa.size() == setMahasiswaSize){
            SortRanking(mahasiswa);
        }
    } else {
        Text("Masukkan Nilai Kapasitas Array: ");
        InputInt("##arraySize", &buffer);
        if (Button("Set Array")){
            setMahasiswaSize = buffer;
            buffer = 0;
        }
    }
}

void Window::UASSemester1::SortRanking(vector<Mahasiswa> currentArray) {
    for (int i = 0; i < currentArray.size(); i++){
        if (currentArray[i].nilai > currentArray[i + 1].nilai){
            Mahasiswa temp = currentArray[i];
            currentArray[i] = currentArray[i + 1];
            currentArray[i + 1] = temp;
        }
    }
    for (int i = 0; i < currentArray.size(); i++){
        Text("%s", currentArray[i].nama.c_str());
    }
}
