#include <HandleWindow.hpp>

void Window::Pertemuan14::handleWindow(){
    Begin("Praktikum 13");
    soal1();
    soal2();
    soal3();
    soal4();
    soal5();
    soal6();
    End();
}

void Window::Pertemuan14::soal1(){
    static vector<Kendaraan> kendaraan = {{5.0, 10.0}, {8.0, 20.0}, {3.5, 35.0}}; // Contoh kendaraan
    static float panjangJembatan = 100.0; // Panjang jembatan dalam meter
    Text("Perhitungan Struktur Beban pada Jembatan");
    float totalBeban = hitungBebanTotal(kendaraan, panjangJembatan);
    Text("Total beban pada jembatan: %f ton", totalBeban);
}

void Window::Pertemuan14::soal2(){
    Separator();
    static float kecepatanAwal = 10.0, kecepatanAkhir = 8.0; // Kecepatan akhir (m/s)
    float densitas = 1000.0;    // Densitas air (kg/m3)
    float ketinggianAwal = 10.0; // Ketinggian awal (m)
    float ketinggianAkhir = 5.0; // Ketinggian akhir (m)
    float tekanan = hitungTekanan(kecepatanAwal, kecepatanAkhir, densitas, ketinggianAwal, ketinggianAkhir);
    Text("Perubahan tekanan: %f Pascal", tekanan);
}

void Window::Pertemuan14::soal3(){
    Separator();
    static float kapasitasPanas = 4186.0, massa = 5.0;             // Massa air (kg)
    float energi = 10000.0;        // Energi yang diserap (J)
    float suhuAkhir = hitungSuhuAkhir(kapasitasPanas, massa, energi);
    Text("Suhu akhir: %f C", suhuAkhir );
}

void Window::Pertemuan14::soal4(){
    Separator();
    static float pendapatan = 1000000.0, biayaProduksi = 400000.0;
    float biayaOperasional = 200000.0;
    float labaBersih = hitungLabaBersih(pendapatan, biayaProduksi, biayaOperasional);
    Text("Laba Bersih: %f", labaBersih);
}

void Window::Pertemuan14::soal5(){
    Separator();
    static int jumlahAwal = 500, barangTerjual = 150, barangDiterima = 200;
    int stokTersisa = hitungStokTersisa(jumlahAwal, barangTerjual, barangDiterima);
    Text("Stok barang tersisa: %i", stokTersisa);
}

void Window::Pertemuan14::soal6(){
    Separator();
    static float hargaAwal = 1000.0, diskon = 0.15; // 15% diskon
    float hargaAkhir = hitungHargaAkhir(hargaAwal, diskon);
    Text("Harga akhir setelah diskon: %f", hargaAkhir);
}