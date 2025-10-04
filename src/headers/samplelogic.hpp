#pragma once
#include <iostream>
#include <string>
using namespace std;

class SampleLogic{
    public: 
        SampleLogic();
        ~SampleLogic();
        int targetNilai, nilai1, nilai2;

        /* And logic apabila kedua nilai sama dengan / lebih dari nilai targetNilai
            Maka nilai nya true (Lulus)
            apabila salah satu atau kedua nilai kurang dari targetNilai
            Maka nilai nya false (Tidak Lulus)
        */
        void andLogic(int nilaiA, int nilaiB);

        /* Or logic apabila salah satu nilai lebih besar atau sama dengan targetNilai
            Maka nilai nya true (Lulus)
            apabila kedua nilai kurang dari targetNilai
            Maka nilai nya false (Tidak Lulus)
        */
        void orLogic(bool pernyataan0, bool pernyataan2);

        /* Not logic apabila kedua nilai kurang dari targetNilai
            Maka nilai nya true (Tidak Lulus)
            apabila salah satu atau kedua nilai lebih dari atau sama dengan targetNilai
            Maka nilai nya false (Lulus)
        */
        void notLogic(bool pernyataan0);

        void xorLogic(bool syarat0, bool syarat2);

        /* Looping dari -1 sampai currentNilai
        */
        void loop(const int& currentNilai);

        void tambah(int a, int b);
        void faktorial();
        void penjumlahanArray();
        void cekNilaiTerbesar();
        void pengulanganWithWhile();
        void drawStarTriangle();
        void countAverage();
        void helloWorld();
        void tablePerkalian();

        void LogicAndOrNotXor();
        void TrueTable();

        /* Cek apakah bilangan genap pakai % operator untuk mendapatkan sisa pembagian*/
        void cekBilanganGenap(int nilai);
        bool isLooping();

        // Pertemuan 3
        void ifElse();
        void switchCase();
        void jenisHari();
        void whileCase();
        void menentukanGajiKaryawanDariJam();

        // Soal 1 Algoritma Nilai 
        void soal1Algoritma();
        string nilaiAkhir(int nilaiSiswa);

        // Soal 2 kalkulator sederhana
        struct kalkulator {
            void soal2Kalkulator();
            int isValidChoiceMenu(){
                int choiceMenu;
                cin >> choiceMenu;

                if (!choiceMenu){
                    cout << "Harus angka";
                    exit(0);
                } else if (choiceMenu > 4){
                    cout << "Pilih antara 1 - 4 saja";
                    exit(0);
                } else {
                    return choiceMenu;
                }
            }

            int isValidBilangan(){
                int bilangan;
                cin >> bilangan;

                if (!bilangan){
                    cout << "Harus angka";
                    exit(0);
                } else {
                    return bilangan;
                }
            }

            void HandleSwitchKalkulator(int currentChoice, int angka1, int angka2){
                int hasil;
                switch(currentChoice){
                    case 1:
                        hasil = penjumlahan(angka1, angka2);
                        cout << "Hasil penjumlahan = " << hasil;
                        break;

                    case 2:
                        hasil = pengurangan(angka1, angka2);
                        cout << "Hasil pengurangan = " << hasil;
                        break;

                    case 3:
                        hasil = perkalian(angka1, angka2);
                        cout << "Hasil perkalian = " << hasil;
                        break;

                    case 4:
                        hasil = pembagian(angka1, angka2);
                        cout << "Hasil pembagian = " << hasil;
                        break;
                        
                    default:
                        exit(0);
                        break;
                }
            }

            int penjumlahan(int a, int b){
                int total = a + b;
                return total;
            };
            int pengurangan(int a, int b) {
                int total = a -b;
                return total;
            };
            int perkalian(int a, int b){
                int total = a * b;
                return total;
            };
            double pembagian(int a, int b){
                double total = a / b;
                return total;
            };
        };

        struct tebakAngka
        {
            int targetAngka, userInput, countTebak = 1;
            int generateRandomAngka(){
                int min = 1, max = 50; 
                return min + rand() % (max - min + 1);
            }

            void checkAngka(int target, int input){
                if (input == target){
                    cout << "Benar! anda menebak dalam " << countTebak<< " kali percobaan" << endl;
                }
                else if (input > target){
                    cout << "Terlalu besar!" << endl;
                } else {
                    cout << "Terlalu kecil! " << endl;
                }

                countTebak += 1;
            }

            void soal3TebakAngka();

            int isValidInput(){
                int input;
                cin >> input;

                if (!input){
                    cout << "Hanya angka" << endl;
                    exit(0);
                } else {
                    return input;
                }
            }

        };
        
        // Pertemuan 5
        struct Pertemuan5{
            // For
            void totalBilanganGenap();
            void deretFibonacci();
            void matrixIdentitas();
            void menghitungFaktorial();

            // while
            void menghitungBilanganGanjil();
            void menebakAngka();
            void menghitungJumlahDigit();
            void menampilkanBilanganPrima();
            void convertToBinary();

            // do while
            void ratarataNilaiSiswa();
            void mengvalidasiInput();
            void menampilkanMenu();
            void cetakDerekBilangan();
            void tebakAngkaDoWhile();
        };

        struct LatihanPertemuan5
        {
            // Soal1
            const int jumlahSiswa = 10; 
            double totalIPK, ratarataIPK;

            float jumlahIpk(int currentSiswa){
                double total = 0;
                double arraySiswa[currentSiswa];
                for (int i = 0; i < currentSiswa; ++i){
                    cout << "Masukkan ipk mahasiswa ke " << i + 1 << ": ";
                    cin >> arraySiswa[i];
                    total += arraySiswa[i];
                }
                return total;
            }

            float average(float totalIpk,int currentSiswa){
                float total = totalIPK / currentSiswa;
                return total;
            }

            void Soal1();

            int validasiAngka(){
                int angka;
                cin >> angka;
                if (!angka){
                    cout << "Harus angka";
                    exit(0);
                }
                return angka;
            }

            // Soal2
            int literTersedia = 0, totalPenjualan;
            void Soal2();
            void Soal2IfVersion();
            void Soal2UpdateHandler(string req){
                cout << "Method soal2 if version\n"
                "Apakah ada pelanggan (ada/tidak): ";
                cin >> req;
                if (req == "ada"){
                    cout << "Masukkan jumlah liter yang ingin dibeli: ";
                    int literDibeli, totalPlusLiter, totalYangDibeli;
                    literDibeli = validasiAngka();
                    totalPlusLiter = totalDibeli(literDibeli);
                    totalYangDibeli = totalPlusLiter + totalPlusPPN(totalPlusLiter);
                    cout << "Liter: " << literDibeli << " L" << endl;
                    cout << "Total plus liter: " << totalPlusLiter << endl;
                    cout << "Total di beli: " << totalYangDibeli << endl;
                    totalPenjualan += totalYangDibeli;
                    literTersedia -= literDibeli;
                    Soal2UpdateHandler(req);
                } else {
                    cout << "Total Penjualan Hari ini "<< totalPenjualan << endl;
                    exit(0);
                }
            }

            int totalDibeli(int literDibeli){
                int total = literDibeli * 10000;
                return total;
            }

            int totalPlusPPN(int currentHarga){
                int total = currentHarga * 10 / 100;
                return total;
            }
        };
        Pertemuan5 pertemuanke5;
};
