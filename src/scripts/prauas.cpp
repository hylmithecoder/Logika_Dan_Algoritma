#include <HandleWindow.hpp>

void Window::Prauas::handleWindowPraus(){
    Begin("Pra UAS");
    soal1();
    soal2();
    soal3();
    soal4();
    soal5();
    End();
}

void Window::Prauas::soal1(){
    static int setTargetArray = 0, arrayInput = 0, angka = 0, currentInput = 0;
    static vector<int> arrayNormal;
    
    Text("1. Buat Program yang memisahkan array ke dalam dua array baru: arrayGenap dan arrayGanjil");
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

void Window::Prauas::soal2(){
    static int jumlahLine = 0, setJumlahLine = 0;
    Separator();
    Text("2. Buat modul cetakGaris(n) yang mencetak garis pemisah sebanyak n karakter");
    if (setJumlahLine != 0){
        printLine(setJumlahLine);
    } else {
        Text("Masukkan nilai n untuk mencetak garis");
        SameLine();
        InputInt("##MasukkanJumlahLine", &jumlahLine);
        if (Button("Buat Garis")){
            setJumlahLine = jumlahLine;
        }
    }
}

void Window::Prauas::soal3(){
    static int totalBelanja = 0, setTotalBelanja = 0;
    Separator();
    Text("3. Buat program kasir yang memberikan voucher tambahan bila total belanja > 1 juta");
    if (setTotalBelanja != 0){
        Text("Total belanja: %i", setTotalBelanja);
        if (setTotalBelanja > 1000000){
            Text("Selamat Anda Mendapatkan Voucher");
        }
    } else {
        Text("Masukkan total belanja yang di beli konsumen: ");
        SameLine();
        InputInt("##InputHarga", &totalBelanja);
        if (Button("Input Harga Belanja")){
            setTotalBelanja = totalBelanja;
        }
    }
}

void Window::Prauas::soal4(){
    static int jari = 0, setJari = 0;
    static double getLuas = 0;
    Separator();
    Text("Buat fungsi luasLingkaran(r) yang mengembalikan luas (gunakan konstanta pi = 3.14)");
    Text("Masukkan jari-jari lingkaran: ");
    SameLine();
    InputInt("##InputJari", &jari);
    if (Button("Input Jari-jari")){
        setJari = jari;
        getLuas = luasLingkaran(setJari);
        cout << "Luas Lingkaran: " << getLuas << endl;
    }

    if (setJari != 0){
        Text("Luas Lingkaran: %f", getLuas);
    } 
}

void Window::Prauas::soal5(){
    static int input = 0, setNormalArray = 0, inputArray = 0, currentInput = 0;
    static vector<int> normalArray;
    Separator();
    Text("Input array integer, lalu tampilkan jumlah pasangan elemen yang jika di jumlahkan menghasilkan angka tertentu");
    if (setNormalArray != 0){
        if (currentInput >= setNormalArray){
            for (int i = 0; i < pasangan.size(); i++){
                Text("Pasangan %i: %d dan %d", i + 1, pasangan[i].a, pasangan[i].b);
                Text("Penjumlahan pasangan %i: %d", i + 1, pasangan[i].a + pasangan[i].b);
            }
        } else {
            Text("Masukkan angka sebanyak %i kali", setNormalArray);
            InputInt("##angkasoal5", &input);
            if (Button("Submit")){
                int getAngka = input;
                cout << "current input: " << getAngka << endl;
                normalArray.push_back(getAngka);
                if (normalArray.size() == setNormalArray){
                    cout << "current input: " << normalArray.size() << endl;
                    pasanganArray(normalArray);
                }
                currentInput++;
            }
        }

    } else {
        Text("Masukkan banyak elemen dalam array:");
        SameLine();
        InputInt("##InputBanyakElemen3", &inputArray);
        if (Button("Tambah array")){
            setNormalArray = inputArray;
        }
    }
}