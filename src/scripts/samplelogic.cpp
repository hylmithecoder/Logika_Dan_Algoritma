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

void SampleLogic::Pertemuan5::totalBilanganGenap(){
    cout << "Method mencari total bilangan genap" << endl;
    int total = 0;
    for (int i = 2; i <= 50; i += 2) { // Inisialisasi dengan 2, menambah 2 di setiap iterasi
        total += i;
    }
    cout << "Total bilangan genap dari 1 hingga 50 adalah: " << total << endl;
}

void SampleLogic::Pertemuan5::deretFibonacci(){
    cout << "Method deret fibonacci" << endl;
    int n = 10; // Jumlah elemen Fibonacci yang ingin ditampilkan
    int a = 0, b = 1, c;
    cout << "Deret Fibonacci: " << a << " " << b << " ";
    for (int i = 3; i <= n; i++) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

void SampleLogic::Pertemuan5::matrixIdentitas(){
    cout << "Method matrix identitas" << endl;
    int n;
    cout << "Masukkan ukuran matriks identitas: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

}

void SampleLogic::Pertemuan5::menghitungFaktorial(){
    cout << "Method menghitung faktorial" << endl;
    int angka, faktorial = 1;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;
    for (int i = 1; i <= angka; i++) {
        faktorial *= i; // Mengalikan nilai faktorial dengan i
    }
    cout << "Faktorial dari " << angka << " adalah: " << faktorial << endl;
}

void SampleLogic::Pertemuan5::menghitungBilanganGanjil(){
    cout << "Method menghitung bilangan ganjil" << endl;
    int i = 1, total = 0;
    while (i <= 50) {
        total += i;
        i += 2; // Menambah 2 untuk mendapatkan bilangan ganjil berikutnya
    }
    cout << "Total bilangan ganjil dari 1 hingga 50 adalah: " << total << endl;
}

void SampleLogic::Pertemuan5::menebakAngka(){
    cout << "Method menebak angka" << endl;
    int angka_rahasia = 7; // Angka rahasia
    int tebak;

    cout << "Tebak angka rahasia (antara 1 hingga 10): ";
    cin >> tebak;
    while (tebak != angka_rahasia) {
        cout << "Salah! Coba lagi: ";
        cin >> tebak;
    }
    cout << "Benar! Angka rahasia adalah: " << angka_rahasia << endl;
}

void SampleLogic::Pertemuan5::menghitungJumlahDigit(){
    cout << "Method menghitung jumlah digit dalam sebuah angka" << endl;
    int angka, jumlah_digit = 0;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;
    while (angka != 0) {
        angka /= 10; // Menghapus digit terakhir
        jumlah_digit++;
    }
    cout << "Jumlah digit dalam angka adalah: " << jumlah_digit << endl;
}

void SampleLogic::Pertemuan5::menampilkanBilanganPrima(){
    cout << "Method menampilkan bilangan prima" << endl;
    int i = 2;
    while (i <= 100) {
        bool prima = true;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                prima = false;
                break;
            }
        }
        if (prima) {
            cout << i << " ";
        }
        i++;
    }
    cout << endl;
}

void SampleLogic::Pertemuan5::ratarataNilaiSiswa(){
    cout << "Method rata-rata nilai" << endl;
    double nilai, total = 0;
    int jumlah = 0;
    char lanjut;
    do {
        cout << "Masukkan nilai mahasiswa (0-100): ";
        cin >> nilai;
        
        // Validasi nilai yang diinput harus antara 0 hingga 100
        if (nilai >= 0 && nilai <= 100) {
            total += nilai;  // Menambahkan nilai ke total
            jumlah++;        // Menambah jumlah mahasiswa
        } else {
            cout << "Nilai tidak valid, masukkan nilai antara 0 hingga 100!" << endl;
        }
        // Menanyakan apakah ingin memasukkan nilai lagi
        cout << "Apakah ingin memasukkan nilai lagi? (y/t): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');  // Ulangi jika pengguna mengetik 'y'
    if (jumlah > 0) {
        double rataRata = total / jumlah;
        cout << "Rata-rata nilai mahasiswa adalah: " << rataRata << endl;
    } else {
        cout << "Tidak ada nilai yang dimasukkan." << endl;
    }
}


void SampleLogic::Pertemuan5::convertToBinary(){
    cout << "Method convertToBinary" << endl;
    int desimal, biner = 0, sisa, pangkat = 1;
    cout << "Masukkan bilangan desimal: ";
    cin >> desimal;
    while (desimal > 0) {
        sisa = desimal % 2;
        biner += sisa * pangkat;
        desimal /= 2;
        pangkat *= 10;
    }
    cout << "Bilangan biner: " << biner << endl;
}

void SampleLogic::Pertemuan5::mengvalidasiInput(){
    cout << "Method Validasi input pengguna" << endl;
    int angka;
    do {
        cout << "Masukkan angka positif: ";
        cin >> angka;

        if (angka < 0) {
            cout << "Angka tidak boleh negatif. Coba lagi!" << endl;
        }
    } while (angka < 0);  // Ulangi jika angka yang dimasukkan negatif
    cout << "Angka positif yang dimasukkan adalah: " << angka << endl;
}

void SampleLogic::Pertemuan5::cetakDerekBilangan(){
    cout << "Method cetak derek bilangan" << endl;
    int n, i = 1;
    cout << "Masukkan nilai n: ";
    cin >> n;
    cout << "Deret bilangan dari 1 hingga " << n << " adalah: ";
    do {
        cout << i << " ";
        i++;
    } while (i <= n);  // Ulangi hingga i lebih besar dari n
    cout << endl;
}

void SampleLogic::Pertemuan5::tebakAngkaDoWhile(){
    cout << "Method tebak angka do while" << endl;
    int angka_rahasia = 42;  // Angka rahasia yang harus ditebak
    int tebakan;
    do {
        cout << "Tebak angka antara 1 hingga 100: ";
        cin >> tebakan;

        if (tebakan > angka_rahasia) {
            cout << "Terlalu tinggi! Coba lagi." << endl;
        } else if (tebakan < angka_rahasia) {
            cout << "Terlalu rendah! Coba lagi." << endl;
        } else {
            cout << "Selamat, tebakan Anda benar!" << endl;
        }
    } while (tebakan != angka_rahasia);  // Ulangi hingga tebakan benar

}

void SampleLogic::Pertemuan5::menampilkanMenu(){
    cout << "Method menampilkan menu" << endl;
    int pilihan;

    do {
        cout << "\n=== MENU PROGRAM ===" << endl;
        cout << "1. Opsi 1" << endl;
        cout << "2. Opsi 2" << endl;
        cout << "3. Opsi 3" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Anda memilih Opsi 1." << endl;
                break;
            case 2:
                cout << "Anda memilih Opsi 2." << endl;
                break;
            case 3:
                cout << "Anda memilih Opsi 3." << endl;
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi!" << endl;
                break;
        }
    } while (pilihan != 4);  // Ulangi hingga pengguna memilih

}

void SampleLogic::LatihanPertemuan5::Soal1(){
    cout << "Masukkan nilai IPK untuk 10 mahasiswa" << endl;
    totalIPK = jumlahIpk(jumlahSiswa);
    ratarataIPK = average(totalIPK, jumlahSiswa);
    cout << "Total IPK dari " << jumlahSiswa << " Mahasiswa adalah: " << totalIPK << endl;
    cout << "Rata-Rata Ipk dari " << jumlahSiswa << " Mahasiswa adalah: " << ratarataIPK << endl;
}

void SampleLogic::LatihanPertemuan5::Soal2(){
    string req;
    cout << "If version atau tidak (iya/no): ";
    cin >> req;
    if (req == "iya"){
        Soal2IfVersion();
    }
    
    cout << "Masukkan jumlah liter yang tersedia untuk hari ini: ";
    cin >> literTersedia;

    while (literTersedia > 0){
        cout << "Masukkan jumlah liter yang ingin dibeli: ";
        int literDibeli, totalPlusLiter, totalYangDibeli;
        literDibeli = validasiAngka();
        if (literDibeli > literTersedia){
            cout << "Melebihi liter tersedia" << endl;
            exit(0);
        }
        totalPlusLiter = totalDibeli(literDibeli);
        totalYangDibeli = totalPlusLiter + totalPlusPPN(totalPlusLiter);
        cout << "Liter: " << literDibeli << " L" << endl;
        cout << "Total plus liter: " << totalPlusLiter << endl;
        cout << "Total di beli: " << totalYangDibeli << endl;
        totalPenjualan += totalYangDibeli;
        literTersedia -= literDibeli;
    }
    cout << "Total Penjualan Hari ini "<< totalPenjualan <<"\nLiter Tersedia sudah habis";
}

void SampleLogic::LatihanPertemuan5::Soal2IfVersion(){
    string req;
    Soal2UpdateHandler(req);
}

void SampleLogic::Pertemuan7::tableArray2Dimensi(){
    cout << "Method array2Dimensi" << endl;
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void SampleLogic::Pertemuan7::tableArray3Dimensi(){
    cout << "Method array3dimensi" << endl;
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
    cout << "Elemen-elemen dalam array tiga dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "Lapisan " << i << ", Baris " << j << ", Kolom " << k << ": " << arr[i][j][k] << endl;
            }
        }
    }

    // Akses elemen tertentu
    cout << "Elemen pada Lapisan 1, Baris 0, Kolom 2: " << arr[1][0][2] << endl;  // Output: 9

}