#include <HandleWindow.hpp>

void Window::pertemuan7::contohPenggunaanArray(){
    Separator();
    int angka[5] = {10, 20, 30, 40, 50};
    Text("Elemen pertama: %i", angka[0]);
    Text("Elemen keempat: %i", angka[3]);
}

void Window::pertemuan7::studyKasus1(){
    Separator();
    Barang inventaris[3] = {
        {"Laptop", 10, 15000.00},
        {"Printer", 5, 3000.00},
        {"Kamera", 8, 5000.00}
    };
    double totalNilai = 0;
    for (int i = 0; i < 3; i++) {
        totalNilai += inventaris[i].jumlah * inventaris[i].harga;
        Text("Nama Barang: %s, Jumlah: %i, Harga: %f", inventaris[i].nama.c_str(), inventaris[i].jumlah, inventaris[i].harga);
    }
    Text("Total Nilai Inventaris: %f", totalNilai);
}

void Window::pertemuan7::studyKasus2(){
    Separator();
    Buku perpustakaan[2] = {
        {"Belajar C++", "John Doe", 2020},
        {"Algoritma dan Struktur Data", "Jane Doe", 2021}
    };
    Text("Daftar Buku di Perpustakaan:");
    for (int i = 0; i < 2; i++) {
        Text("Judul: %s, Penulis: %s, Tahun Terbit: %d", perpustakaan[i].judul.c_str(), perpustakaan[i].penulis.c_str(), perpustakaan[i].tahunTerbit);
    }
}

void Window::pertemuan7::studyKasus3(){
    Separator();
    double penjualan[5] = {200.00, 150.00, 300.00, 250.00, 400.00};
    double totalPenjualan = 0;
    for (int i = 0; i < 5; i++) {
        totalPenjualan += penjualan[i];
    }
    Text("Total Penjualan: %f", totalPenjualan);
}

void Window::pertemuan7::studyKasus4(){
    Separator();
    Kamar kamar[2] = {
        {"101", "Standard", 500.00},
        {"102", "Deluxe", 800.00}
    };
    Reservasi reservasi = {"Fahmi", "2024-10-20", "2024-10-22"};
    Text("Reservasi Kamar:");
    Text("Nama: %s, Kamar: %s, Tipe: %s, Harga: %f", reservasi.namaPelanggan.c_str(), kamar[0].nomorKamar.c_str(), kamar[0].tipe.c_str(), kamar[0].harga);
}

void Window::pertemuan7::studyKasus5(){
    Separator();
    Karyawan karyawan[3] = {
        {"Alice", 10000.00, {"Manager"}},
        {"Bob", 5000.00, {"Staff"}},
        {"Charlie", 3000.00, {"Intern"}}
    };

    double totalGaji = 0;
    Text("Data Karyawan:");
    for (int i = 0; i < 3; i++) {
        totalGaji += karyawan[i].gaji;
        Text("Nama: %s, Jabatan: %s, Gaji: %f", karyawan[i].nama.c_str(), karyawan[i].jabatan.namaJabatan.c_str(), karyawan[i].gaji);
    }
    Text("Total Gaji: %f", totalGaji);
}

void Window::pertemuan7::contohTableArray2Dimensi(){
    Separator();
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    // Menampilkan elemen-elemen array
    Text("Elemen-elemen dalam array dua dimensi:");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            Text("Baris %i, Kolom %i: %i", i, j, arr[i][j]);
        }
    }
    // Akses elemen tertentu
    Text("Elemen pada Baris 1, Kolom 2: %i", arr[1][2]);
}

void Window::pertemuan7::contohTableArray3Dimensi(){
    Separator();
    int arr[2][2][3] = {
        {
            {1, 2, 3},
            {4, 5, 6}
        },
        {
            {7, 8, 9},
            {10, 11, 12}
        }
    };
    // Menampilkan elemen-elemen array
    Text("Elemen-elemen dalam array tiga dimensi:");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                Text("Lapisan %i, Baris %i, Kolom %i: %i", i, j, k, arr[i][j][k]);
            }
        }
    }
    // Akses elemen tertentu
    Text("Elemen pada Lapisan 1, Baris 0, Kolom 2: %i", arr[1][0][2]);
}