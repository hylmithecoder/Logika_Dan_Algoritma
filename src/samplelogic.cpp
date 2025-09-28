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

// Pertemuan 4
void SampleLogic::ifElse(){
    cout << "Method ifElse" << endl;
    int usia;
    // Input usia
    cout << "Masukkan usia Anda: ";
    cin >> usia;
    // Menentukan kategori usia
    if (usia <= 12) {
        cout << "Anda adalah Anak-anak." << endl;
    } else if (usia <= 17) {
        cout << "Anda adalah Remaja." << endl;
    } else if (usia <= 64) {
        cout << "Anda adalah Dewasa." << endl;
    } else {
        cout << "Anda adalah Lansia." << endl;
    }
}

void SampleLogic::switchCase(){
    cout << "Method switchCase" << endl;
    int hari = 3;
    switch (hari) {
        case 1:
            cout << "Senin" << endl;
            break;
        case 2:
            cout << "Selasa" << endl;
            break;
        case 3:
            cout << "Rabu" << endl;
            break;
        default:
            cout << "Hari tidak valid" << endl;
    }
}

void SampleLogic::jenisHari(){
    int nomor_hari;
    // Input nomor hari
    cout << "Masukkan nomor hari (1-7): ";
    cin >> nomor_hari;
    // Menentukan jenis hari
    if (nomor_hari == 1) {
        cout << "Senin" << endl;
    } else if (nomor_hari == 2) {
        cout << "Selasa" << endl;
    } else if (nomor_hari == 3) {
        cout << "Rabu" << endl;
    } else if (nomor_hari == 4) {
        cout << "Kamis" << endl;
    } else if (nomor_hari == 5) {
        cout << "Jumat" << endl;
    } else if (nomor_hari == 6) {
        cout << "Sabtu" << endl;
    } else if (nomor_hari == 7) {
        cout << "Minggu" << endl;
    } else {
        cout << "Nomor hari tidak valid." << endl;
    }

}

void SampleLogic::whileCase(){
    cout << "Method While case" << endl;
    int i = 0;
    while (i < 5) {
        cout << "i adalah " << i << endl;
        i++;
    }
}

void SampleLogic::menentukanGajiKaryawanDariJam(){
    int jamKerja;
    float tarifPerJam = 20.0; // Tarif per jam kerja
    float gaji;

    // Input jam kerja
    cout << "Masukkan jumlah jam kerja: ";
    cin >> jamKerja;

    // Menentukan gaji
    if (jamKerja <= 40) {
        gaji = jamKerja * tarifPerJam;
    } else {
        // Jam lembur
        int jamLembur = jamKerja - 40;
        gaji = (40 * tarifPerJam) + (jamLembur * tarifPerJam * 1.5);
    }

    cout << "Gaji karyawan adalah: $" << gaji << endl;
}

string SampleLogic::nilaiAkhir(int nilaiSiswa){
    string nilaiHuruf;

    if (nilaiSiswa >= 85){
       nilaiHuruf = "A";   
    } else {
       if (nilaiSiswa >= 70){
          nilaiHuruf = "B";
       } else {
          if (nilaiSiswa >= 55){
              nilaiHuruf = "C";
          } else {
             if (nilaiSiswa >= 40){
                nilaiHuruf = "D";
             } else {
                 nilaiHuruf = "E";
             }
          }
       }
    }

    return nilaiHuruf;
}

void SampleLogic::soal1Algoritma(){
    string nilaiHuruf;
    int nilaiSiswa;

    cout << "Masukkan Nilai Siswa: " ;
    cin >> nilaiSiswa;
    nilaiHuruf = nilaiAkhir(nilaiSiswa);
    cout << "Nilai Siswa: " << nilaiSiswa << endl;
    cout << "Nilai huruf: " << nilaiHuruf << endl;
}

void SampleLogic::kalkulator::soal2Kalkulator(){
    int choiceMenu, bil1, bil2;
    double hasilAkhir;
    cout << "Menu:\n"
    "1. Penjumlahan\n"
    "2. Pengurangan\n" 
    "3. Perkalian\n"
    "4. Pembagian\n"
    "Pilih Menu: ";

    choiceMenu = isValidChoiceMenu();

    cout << "Masukkan bilangan pertama: ";
    bil1 = isValidBilangan();
    cout << "Masukkan bilangan kedua:";
    bil2 = isValidBilangan();
    HandleSwitchKalkulator(choiceMenu, bil1, bil2);

}

void SampleLogic::tebakAngka::soal3TebakAngka(){
    srand(time(0));

    targetAngka = generateRandomAngka();
    do {
        cout << "Tebak angka (1 - 50): ";
        userInput = isValidInput();
        checkAngka(targetAngka, userInput);

    } while(targetAngka != userInput);
}