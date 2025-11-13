#include <HandleWindow.hpp>

void Window::UTS::handleUI(){
    Begin("UTS");
    soal1();
    soal2();
    soal3();
    soal4();
    End();
}

void Window::UTS::soal1(){
    static float sisi;
    static bool onClick = false;
    Separator();
    Text("Soal1, Menghitung luas persegi dan volume kubus");
    Text("Masukkan sisi persegi: ");
    InputFloat("##soal1", &sisi);
    if (Button("Hitung luas dan volume")) onClick = true;
    if (onClick){
        Text("Luas persegi: %f", luasPersegi(sisi));
        Text("Volume kubus: %f", volumeKubus(sisi));
    }
}

void Window::UTS::soal2(){
    static int bil;
    static bool onClick = false;
    Separator();
    Text("Soal2, Menghitung bilangan prima");
    Text("Masukkan bilangan: ");
    InputInt("##soal2", &bil);
    if (Button("Hitung")) onClick = true;
    if (onClick){
        bilPrima(bil);
    }
}

void Window::UTS::soal3(){
    static int bil;
    static bool onClick = false;
    Separator();
    Text("Soal3, Menjumlahkan bilangan faktorial");
    InputInt("##soal3", &bil);
    if (Button("Hitung faktorial")) onClick = true;
    if (onClick){
        Text("Faktorial dari %d adalah %d", bil, faktorial(bil));
    }
}

void Window::UTS::soal4(){
    static int bil1, bil2, bil3, bil4;
    static bool onClick = false;
    Separator();
    Text("Soal4, Tabel 3x4\n1. Bilangan 1");
    InputInt("##bil1soal4", &bil1);
    Text("2. Bilangan 2");
    InputInt("##bil2soal4", &bil2);
    Text("3. Bilangan 3");
    InputInt("##bil3soal4", &bil3);
    if (Button("Tambah Data")){
        onClick = true;
        pushToMatrix(bil1, bil2, bil3, matrix);
        currentBaris++;
    }
    if (onClick){
        Separator();
        showMatrix(matrix);
    }
}