#include <samplelogic.hpp>

void Update(){
    SampleLogic logic;

    int nilai1 = logic.nilai1;
    int nilai2 = logic.nilai2;
    int cekNilai, targetLooping;

    logic.andLogic(nilai1, nilai2);
    logic.orLogic(nilai1, nilai2);
    logic.notLogic(nilai1);

    logic.helloWorld();
    logic.penjumlahanArray();
    
    cout << "Masukkan nilai untuk di cek genap atau ganjil: ";
    cin >> cekNilai;
    logic.cekBilanganGenap(cekNilai);
    logic.faktorial();
    logic.penjumlahanArray();
    logic.pengulanganWithWhile();
    logic.cekNilaiTerbesar();
    logic.tablePerkalian();
    logic.drawStarTriangle();
    logic.countAverage();

    cout << "Masukkan nilai untuk looping: ";
    cin >> targetLooping;
    logic.loop(targetLooping);

    // Ulangin kalau mau
    bool loopAgain = logic.isLooping();
    if (loopAgain){
        Update();
    } else {
        return;
    }
}

void andLogicInputSiswa(SampleLogic& logicClass){
    cout << "Method and" << endl ;
    int nilaiSiswa, persentaseKehadiran;
    cout << "Masukkan Nilai siswa: ";
    cin >> nilaiSiswa;
    cout << "Masukkan persentase kehadiran: ";
    cin >> persentaseKehadiran;

    logicClass.andLogic(nilaiSiswa, persentaseKehadiran);
}

void orLogicUjian(SampleLogic& logicClass){
    cout << "Method or" << endl ;
    bool pernyataan1, pernyataan2;
    cout << "Apakah siswa mengikuti seminar? (1 untuk ya, 0 untuk tidak): ";
    cin >> pernyataan1;
    cout << "Apakah siswa mengikuti seminar? (1 untuk ya, 0 untuk tidak): ";
    cin >> pernyataan2;

    logicClass.orLogic(pernyataan1, pernyataan2);
}

void notLogicPengumpulanTugas(SampleLogic& logicClass){
    cout << "Method not" << endl;
    bool pernyataan;
    cout << "Apakah tugas siswa sudah dikumpulkan? (1 untuk ya, 0 untuk tidak): ";
    cin >> pernyataan;
    logicClass.notLogic(pernyataan);
}

void xorLogicKasusBeasiswa(SampleLogic& logicClass){
    cout << "Method xor" << endl;
    bool pernyataan1, pernyataan2;
    cout << "Apakah siswa memiliki keunggulan akademik? (1 untuk ya, 0 untuk tidak):";
    cin >> pernyataan1;
    cout << "Apakah siswa memiliki keunggulan non-akademik? (1 untuk ya, 0 untuk tidak):";
    cin >> pernyataan2;

    logicClass.xorLogic(pernyataan1, pernyataan2);
}

void PertemuanKe2(){
    SampleLogic logic;
    
    andLogicInputSiswa(logic);
    orLogicUjian(logic);
    notLogicPengumpulanTugas(logic);
    xorLogicKasusBeasiswa(logic);
}

void choiceModule(int request){

    switch (request)
    {
    case 1:
        Update();
        break;
    
    case 2:
        PertemuanKe2();
        break;
        
    default:
        break;
    }
}

int setRequest(){
    cout << "Pilih Materi yang ingin di pilih" << endl;
    cout << "1. Pertemuan 1" << endl;
    cout << "2. Pertemuan 2" << endl;
    int request;
    cin >> request;
    return request;
}

int main(){

    // choiceModule();
    // Update();
    int setReq = setRequest();
    choiceModule(setReq);
    return 0;
}