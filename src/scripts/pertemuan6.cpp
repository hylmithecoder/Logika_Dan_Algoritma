#include <HandleWindow.hpp>

void Window::pertemuan6::uipertemuan6(){
    static int choice = 0;
    const char* studyCase[] = { "Study Kasus A", "Study Kasus B", "Study Kasus C" };
    Window* parent = (Window*)this;
    ImGui::Begin("Pertemuan 6");
    ImGui::Text("Pertemuan 6 FUNGSI DAN MODULARISASI PROGRAM DENGAN C++");
    ImGui::Text("PDF Nya");
    parent->renderPDF(currentPageTextures, currentPage, totalPages);
    ImGui::Combo("##Study Kasus", &choice, studyCase, IM_ARRAYSIZE(studyCase));
    ImGui::Separator();
    handleStudyKasus(choice);
    ImGui::End();
}

void Window::pertemuan6::A_soal1(){
    ImGui::Separator();
    ImGui::Text("Studi kasus A 1");
    int penjumlahan = tambah(10, 20);
    ImGui::Text("Hasil penjumlahan: %d", penjumlahan);
}

void Window::pertemuan6::A_soal2(){
    ImGui::Separator();
    ImGui::Text("Studi kasus A 2");
    tampilkanPesan();
}

void Window::pertemuan6::A_soal3(){
    static float panjang = 0, lebar = 0;
    static bool onClick = false;
    ImGui::Separator();
    ImGui::Text("Studi kasus A 3\nMasukkan Panjang");
    ImGui::InputFloat("##Panjang", &panjang);
    ImGui::Text("Masukkan Lebar");
    ImGui::InputFloat("##Lebar", &lebar);
    if (ImGui::Button("Hitung")) {        
        onClick = true;        
    }
    if (onClick){
        float luas = luasPersegiPanjang(panjang, lebar);
        ImGui::Text("Hasil: %f", luas);
    }
}

void Window::pertemuan6::A_soal4(){
    static int angka = 0;
    ImGui::Separator();
    ImGui::Text("Studi kasus A 4 Menghitung Faktorial \nMasukkan sebuah angka");
    ImGui::InputInt("##angkaa_4", &angka);
    ImGui::Text("Faktorial dari %i adalah %i", angka, faktorial(angka));
}

void Window::pertemuan6::A_soal5(){
    static int batas = 0;
    ImGui::Separator();
    ImGui::Text("Studi kasus A 5 Mencetak bilangan genap \nMasukkan batas");
    ImGui::InputInt("##Batas", &batas);
    cetakGenap(batas);
}

void Window::pertemuan6::B_soal1(){
    static int sisi = 0;
    ImGui::Separator();
    ImGui::Text("Studi kasus B 1 Menghitung persegi \nMasukkan angka:");
    ImGui::InputInt("##angkab_soal1", &sisi);
    ImGui::Text("Kuadrat dari %i adalah %i", sisi, kuadrat(sisi));
}

void Window::pertemuan6::B_soal2(){
    static float angka1 = 0, angka2 = 0, angka3 = 0;
    ImGui::Separator();
    ImGui::Text("Studi kasus B 2 Menghtung rata-rata \nMasukkan angka1:");
    ImGui::InputFloat("##angkab_soal2_1", &angka1);
    ImGui::Text("Masukkan angka2:");
    ImGui::InputFloat("##angkab_soal2_2", &angka2);
    ImGui::Text("Masukkan angka3:");
    ImGui::InputFloat("##angkab_soal2_3", &angka3);
    ImGui::Text("Rata-rata dari %f, %f, %f adalah %f", angka1, angka2, angka3, hitungRataRata(angka1, angka2, angka3));
}


void Window::pertemuan6::B_soal3(){
    static char input[256] = "";
    ImGui::Separator();
    ImGui::Text("Studi kasus B 3 Menghitung panjang string\nMasukkan teks");
    ImGui::InputText("##Teksb_3", input, IM_ARRAYSIZE(input));
    ImGui::Text("Panjang teks: %d", panjangString(input));
}

void Window::pertemuan6::B_soal4(){
    static int angka1 = 0, angka2 = 0;
    ImGui::Separator();
    ImGui::Text("Studi kasus B 4 Menukar dua bilangan\nMasukkan angka pertama");
    ImGui::InputInt("##Teksb_4_1", &angka1);
    ImGui::Text("Masukkan angka kedua");
    ImGui::InputInt("##Teksb_4_2", &angka2);
    ImGui::Text("Sebelum ditukar: x = %i, y = %i", angka1, angka2);
    int tukarx = angka2;
    int tukary = angka1;
    ImGui::Text("Setelah ditukar: x = %i, y = %i", tukarx, tukary);
}

void Window::pertemuan6::B_soal5(){
    static int angka[1];
    ImGui::Separator();
    ImGui::Text("Studi kasus B 5 Mencari nilai maksimum\nMasukkan dua angka");
    ImGui::InputInt2("##Teksb_5_1", angka);
    ImGui::Text("NIlai maksimum: %i", maximum(angka[0], angka[1]));
}

void Window::pertemuan6::C_soal1(){
    Window* parent = (Window*)this;
    static float angka1, angka2;
    string eksekusi;
    ImGui::Separator();
    ImGui::Text("Studi kasus C 1 Kalkulator sederhana\nMasukkan angka pertama");
    ImGui::InputFloat("##angkac1_1", &angka1);
    ImGui::Text("Masukkan angka kedua");
    ImGui::InputFloat("##angkac1_2", &angka2);
    
    if (ImGui::Button("Tambah")) {
        eksekusi = "Tambah";
        hasilKalkulator = parent->tambah(angka1, angka2);
    } else if (ImGui::Button("Kurang")) {
        eksekusi = "Kurang";
        hasilKalkulator = parent->kurang(angka1, angka2);
    } else if (ImGui::Button("Kali")) {
        eksekusi = "Kali";
        hasilKalkulator = parent->kali(angka1, angka2);
    } else if (ImGui::Button("Bagi")) {
        eksekusi = "Bagi";
        hasilKalkulator = parent->bagi(angka1, angka2);
    }
    // cout << "Hasil: " << hasil << endl;
    ImGui::Text("Hasil %s: %f", eksekusi.c_str(), hasilKalkulator);
}

void Window::pertemuan6::C_soal2(){
    static int current_item_index = 0;
    const char* choice[] = { "Persegi", "Persegi Panjang", "Lingkaran" };

    ImGui::Separator();
    ImGui::Text("Studi kasus C 2 mencari luas bangun datar\nMasukkan Panjang");
    ImGui::Combo("Pilih Bangun Datar", &current_item_index, choice, IM_ARRAYSIZE(choice));
    if (current_item_index == 0){
        uiForPersegi();
    } else if (current_item_index == 1){
        uiForPersegiPanjang();
    } else if (current_item_index == 2){
        uiForLingkaran();
    }
}

void Window::pertemuan6::C_soal3(){
    static vector<string> siswa;
    static char searchName[256] = "";
    static char currentInputName[256] = "";
    static bool isFound = false;

    ImGui::Separator();
    ImGui::Text("Studi kasus C 3 mengelola daftar siswa\nMasukkan nama siswa yang ingin ditambah");
    ImGui::InputText("##Teksc_3_1", currentInputName, IM_ARRAYSIZE(currentInputName));
    string nameTostr = currentInputName;
    siswa = handleButtonCSoal3(siswa, nameTostr);
    HandleCariSiswa(searchName, siswa, isFound);
    ImGui::Text("Daftar Siswa:");
    for (int i = 0; i < siswa.size(); i++){
        ImGui::Text("%i.%s", (i+1), siswa[i].c_str());
    }
}

void Window::pertemuan6::C_soal4(){
    static float nilaiTugas, nilaiUjian; 

    ImGui::Separator();
    ImGui::Text("Studi kasus C 4 Menghitung nilai mahasiswa\nMasukkan nilai tugas");
    ImGui::InputFloat("##soalc_4_1", &nilaiTugas);
    ImGui::Text("Masukkan nilai ujian");
    ImGui::InputFloat("##soalc_4_2", &nilaiUjian);
    float nilaiAkhir = hitungNilaiAkhir(nilaiTugas, nilaiUjian);
    tampilkanNilai(nilaiAkhir);
}

void Window::pertemuan6::C_soal5(){
    static int currentMenuMakanan = 0, jumlah = 0;
    const char* choiceMakanan[] = { "Nasi Goreng - $10", "Mie Ayam - $8", "Sate Ayam - $12" };

    ImGui::Separator();
    ImGui::Text("Studi kasus C 5 pemesanan makanan\nPilih Menu makanan");
    ImGui::Combo("##menumakanan", &currentMenuMakanan, choiceMakanan, IM_ARRAYSIZE(choiceMakanan));
    ImGui::Text("Masukkan jumlah pesanan");
    ImGui::InputInt("##jumlah", &jumlah);
    showHarga(currentMenuMakanan, jumlah, choiceMakanan[currentMenuMakanan]);
}
