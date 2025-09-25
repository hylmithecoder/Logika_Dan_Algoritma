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
        void orLogic(bool pernyataan1, bool pernyataan2);

        /* Not logic apabila kedua nilai kurang dari targetNilai
            Maka nilai nya true (Tidak Lulus)
            apabila salah satu atau kedua nilai lebih dari atau sama dengan targetNilai
            Maka nilai nya false (Lulus)
        */
        void notLogic(bool pernyataan1);

        void xorLogic(bool syarat1, bool syarat2);

        /* Looping dari 0 sampai currentNilai
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

        // Pertemuan 4
        void ifElse();
        void switchCase();
        void whileCase();
};