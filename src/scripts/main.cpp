#include <samplelogic.hpp>
#include <HandleWindow.hpp>
#include <algoritmabensin.hpp>

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
    cout << "Apakah siswa memiliki tugas tambahan? (1 untuk ya, 0 untuk tidak): ";
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


int isValidLiter(AlgoritmaBensin& bensin){
    cout << "Jumlah Liter : ";
    cin >> bensin.jumlahLiter;
    if (!bensin.jumlahLiter){
        cout << "Hanya angka" << endl;
        exit(0);
    }
    return bensin.jumlahLiter;
}

void PertemuanKe3(){
    AlgoritmaBensin bensin;

    cout << "Jenis Kendaraan : ";
    cin >> bensin.jenisKendaraan;
    isValidLiter(bensin);

    bensin.checkJenisKendaraan(bensin.jenisKendaraan);
    int currentHargaJual = bensin.setHargaJual();
    int hargaAkhir = bensin.hargaBeli(currentHargaJual);

    cout << "Jenis Kendaraan: " << bensin.jenisKendaraan << endl;
    if (bensin.jenisSolar == ""){
        cout << "Jenis Bensin: " << bensin.jenisBensin << endl;
    } else {
        cout << "Jenis Solar: " << bensin.jenisSolar << endl;
    }
    cout << "Jumlah Liter: " << bensin.jumlahLiter << " Liter"<< endl;
    cout << "Harga Jual: Rp." << currentHargaJual << endl;
    cout << "Harga Pajak: Rp." << bensin.hargaPajak << endl;
    cout << "Harga Beli: Rp." << hargaAkhir << endl;
}

void PertemuanKe4(){
    SampleLogic logic;

    logic.ifElse();
    logic.switchCase();
    logic.whileCase();
    logic.jenisHari();
    logic.menentukanGajiKaryawanDariJam();
}

void PertemuanKe5(){
    SampleLogic logic;

    // for
    cout << "Studi kasus menggunakan for" << endl;
    logic.pertemuanke5.totalBilanganGenap();
    logic.drawStarTriangle();
    logic.pertemuanke5.deretFibonacci();
    logic.pertemuanke5.matrixIdentitas();
    logic.pertemuanke5.menghitungFaktorial();

    // while
    cout << "Studi kasus menggunakan while" << endl;
    logic.pertemuanke5.menghitungBilanganGanjil();
    logic.pertemuanke5.menebakAngka();
    logic.pertemuanke5.menghitungJumlahDigit();
    logic.pertemuanke5.menampilkanBilanganPrima();
    logic.pertemuanke5.convertToBinary();

    // do while
    cout << "Studi kasus menggunakan do while" << endl;
    logic.pertemuanke5.ratarataNilaiSiswa();
    logic.pertemuanke5.mengvalidasiInput();
    logic.pertemuanke5.menampilkanMenu();
    logic.pertemuanke5.cetakDerekBilangan();
    logic.pertemuanke5.tebakAngkaDoWhile();
}

void PertemuanKe7(){
    SampleLogic logic;
    logic.pertemuanke7.tableArray2Dimensi();
    logic.pertemuanke7.tableArray3Dimensi();
}

void LatihanPertemuanKe5Soal1(){
    SampleLogic::LatihanPertemuan5 logic;
    logic.Soal1();
}

void LatihanPertemuanKe5Soal2(){
    SampleLogic::LatihanPertemuan5 logic;
    logic.Soal2();
}

void Soal1(){
    SampleLogic logic;
    logic.soal1Algoritma();
}

void Soal2(){
    SampleLogic::kalkulator logic;
    logic.soal2Kalkulator();
}

void Soal3(){
    SampleLogic::tebakAngka logic;
    logic.soal3TebakAngka();
}

void loopPertemuanKe5(int jumlahSoal){
    for (int i = 1; i <= jumlahSoal; ++i){
        cout << i << ". Soal " << i << endl;
    }
    int soal;
    cin >> soal;
    switch (soal)
    {
    case 1:
        LatihanPertemuanKe5Soal1();
        break;
    
    case 2:
        LatihanPertemuanKe5Soal2();
        break;

    default:
        break;
    }
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

    case 3:
        PertemuanKe3();
        break;

    case 4:
        PertemuanKe4();
        break;

    case 5:
        PertemuanKe5();
        break;

    case 6:
        PertemuanKe7();
        break;

    case 7:
        Soal1();
        break;

    case 8:
        Soal2();
        break;

    case 9:
        Soal3();
        break;

    case 10:
        loopPertemuanKe5(2);
        break;

    default:
        break;
    }
}

void loopPertemuan(int pertemuan){
    for (int i = 1; i <= pertemuan; ++i){
        cout << i << ". Pertemuan " << i << endl;
    }
}

void loopSoal(int jumlahPertemuan,int jumlahSoal){
    for (int i = 7; i <= jumlahSoal; ++i){
        cout << i << ". Soal " << i << endl;
    }
}

int setRequest(){
    int jumlahPertemuan = 6;
    cout << "Pilih Materi atau soal yang ingin di pilih" << endl;
    loopPertemuan(jumlahPertemuan);
    loopSoal(jumlahPertemuan, 8);
    cout << "9. Latihan Pertemuan ke 5" << endl;
    int request;
    cin >> request;
    return request;
}

void handleChoiceCliOrGui(){
    int req, setReq;
    Window win(1280, 720);
    cout << "Pilih mode: \n"
    "1. CLI\n"
    "2. GUI";
    cin >> req;
    switch (req){
        case 1:
            setReq = setRequest();
            choiceModule(setReq);
            break;
        
        case 2:
            win.Main();
            break;

    }
}

int main(int argv, char *argc[]){

    // choiceModule();
    // Update();
    handleChoiceCliOrGui();
    // int setReq = setRequest();
    // choiceModule(setReq);
    return 0;
}
