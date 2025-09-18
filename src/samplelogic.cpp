#include <samplelogic.hpp>

void SampleLogic::andLogic(int nilaiA, int nilaiB){
    targetNilai = 80;
    if (nilaiA >= targetNilai && nilaiB >= targetNilai){
        cout << "Siswa lulus" << endl;
    } else {
        cout << "Siswa tidak lulus"  << endl;
    }
}

void SampleLogic::orLogic(bool pernyataan1, bool pernyataan2){
    if (pernyataan1 || pernyataan2){
        cout << "Siswa Di bebaskan dari ujian" << endl;
    } else {
        cout << "Siswa harus mengikuti ujian" << endl;
    }
}

void SampleLogic::xorLogic(bool syarat1, bool syarat2){
    bool isMemenuhi = syarat1 ^ syarat2;

    if (isMemenuhi){
        cout << "Siswa berhak mendapatkan beasiswa" << endl;
    } else {
        cout << "Siswa tidak berhak mendapatkan beasiswa" << endl;
    }
}

void SampleLogic::notLogic(bool pernyataan1){
    if (!pernyataan1){
        cout << "Peringatan: Siswa belum mengumpulkan tugas"<< endl;
    } else {
        cout << "Tugas sudah dikumpulkan" << endl;
    }
}

void SampleLogic::loop(const int& currentNilai){
    for (int i = 1; i < currentNilai; i++){
        cout << "Looping ke: " << i << endl;
    }
}

bool SampleLogic::isLooping(){
    cout << "Ingin lanjut kan logic lagi? ";
    string lanjut;
    cin >> lanjut;
    if (lanjut == "y" || lanjut == "Y" || lanjut == "yes" || lanjut == "YES"){
        return true;
    } else {
        return false;
    }
}

void SampleLogic::cekBilanganGenap(int nilai){
    cout << "Method cekBilanganGenap" << endl;
    if (nilai % 2 == 0){
        cout << nilai << " adalah bilangan genap" << endl;
    } else {
        cout << nilai << " adalah bilangan ganjil" << endl;
    }
}

SampleLogic::SampleLogic(){
    // cout << "===============Init terlebih dahulu==================" << endl;
    // cout << "Masukkan target nilai: ";
    // cin >> targetNilai;
    // cout << "Masukkan nilai pertama: ";
    // cin >> nilai1;
    // cout << "Masukkan nilai kedua: ";
    // cin >> nilai2;
    // cout << "====================================================" << endl;
}

SampleLogic::~SampleLogic(){
    cout << "==================Selesai============================" << endl;  
}

void SampleLogic::tambah(int a, int b) {
    cout << "Method tambah" << endl;
    int hasil = a + b;
    cout << "Hasil penjumlahan: " << hasil << endl;
}

void SampleLogic::faktorial() {
    cout << "Method faktorial" << endl;
    int n;
    cout << "Masukkan bilangan untuk faktorial: ";
    cin >> n;
    int hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    cout << "Faktorial dari " << n << " adalah " << hasil << endl;
}

void SampleLogic::penjumlahanArray() {
    cout << "Method penjumlahanArray" << endl;
    const int size = 5;
    int arr[size], sum = 0;
    std::cout << "Masukkan " << size << " angka: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    std::cout << "Jumlah dari array adalah " << sum << std::endl;
}

void SampleLogic::cekNilaiTerbesar() {
    cout << "Method cekNilaiTerbesar" << endl;
    int a, b, c;
    cout << "Masukkan nilai-nilai: ";
    cin >> a >> b >> c;
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    cout << "Angka terbesar adalah " << max << endl;
}

void SampleLogic::pengulanganWithWhile(){
    cout << "Method pengulanganWithWhile" << endl;
    int i = 1;
    while (i <= 5) {
        cout << "Perulangan ke-" << i << endl;
        ++i;
    }
}

void SampleLogic::drawStarTriangle(){
    cout << "Method drawStarTriangle" << endl;
    int n;
    cout << "Masukkan jumlah baris: ";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

void SampleLogic::countAverage(){
    cout << "Method countAverage" << endl;
    int num, count = 0;
    double sum = 0.0;
    std::cout << "Masukkan jumlah angka (0 untuk berhenti): ";
    while (std::cin >> num && num != 0) {
        sum += num;
        ++count;
        std::cout << "Masukkan angka berikutnya (0 untuk berhenti): ";
    }
    if (count != 0) {
        std::cout << "Rata-rata adalah " << (sum / count) << std::endl;
    } else {
        std::cout << "Tidak ada angka yang dimasukkan." << std::endl;
    }

}

void SampleLogic::helloWorld(){
    cout << "Method helloWorld" << endl;
    cout << "Hello, World!" << endl;
}

void SampleLogic::tablePerkalian(){
    cout << "Method tablePerkalian" << endl;
    int num;
    cout << "Masukkan angka untuk tabel perkalian: ";
    cin >> num;
    for (int i = 1; i <= 10; ++i) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
}

void SampleLogic::LogicAndOrNotXor(){
    cout << "Method LogicAndOrNotXor" << endl;
    bool A = true;
    bool B = false;

    // AND
    cout << "A AND B: " << (A && B) << endl;  // Output: 0 (false)
 
    // OR
    cout << "A OR B: " << (A || B) << endl;   // Output: 1 (true)
    
    // NOT
    cout << "NOT A: " << (!A) << endl;        // Output: 0 (false)
    
    // XOR
    cout << "A XOR B: " << (A ^ B) << endl;   // Output: 1 (true)
}

void SampleLogic::TrueTable(){
    cout << "Method TrueTable" << endl;
    bool values[] = {false, true};
    
    cout << "A\tB\tA AND B\tA OR B\n";
    for (bool A : values) {
        for (bool B : values) {
            cout << A << "\t" << B << "\t" << (A && B) << "\t" << (A || B) << endl;
        }
    }

}