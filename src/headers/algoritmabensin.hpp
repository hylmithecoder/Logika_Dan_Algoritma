#include <iostream>
#include <vector>
using namespace std;

class AlgoritmaBensin{
    public: 

        int hargaPertalite = 10000, hargaPertamax = 13100, hargaDexlite = 14600, hargaBiosolar = 6500;
        int setHarga;
        string jenisKendaraan, jenisSolar, jenisBensin;
        int jumlahLiter, hargaPajak;
        int inputHargaBensin(){
            int hargaBensin;
            cin >> hargaBensin;
            return hargaBensin;
        }

        int hargaPPN(int currentHargaJual){
            int total = currentHargaJual * 10 / 100;
            hargaPajak = total;
            return total;
        }

        int hargaBeli(int currentHargaJual){
            int total = currentHargaJual + hargaPPN(currentHargaJual);
            return total;
        }

        void checkJenisKendaraan(string& currentJenisKendaraan);

        int setHargaJual();
};