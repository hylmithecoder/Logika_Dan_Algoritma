#include <algoritmabensin.hpp>

void AlgoritmaBensin::checkJenisKendaraan(string& currentJenisKendaraan){
    if (currentJenisKendaraan == "Solar" || currentJenisKendaraan == "solar"){
        cout << "Jenis solar: ";
        cin >> jenisSolar;
        cout << jenisSolar;
        if (jenisSolar == "Dexlite" || jenisSolar == "dexlite"){
            setHarga = hargaDexlite;
            cout << 'Jenis solar dexlite' << endl;
        } else {
            setHarga = hargaBiosolar;
            cout << 'Jenis solar biosolar' << endl;
        }
    } else if (currentJenisKendaraan == "Bensin" || currentJenisKendaraan == "bensin"){
        cout << "Jenis bensin: " ;
        cin >> jenisBensin;
        if (jenisBensin == "Pertalite" || jenisBensin == "pertalite"){
            setHarga = hargaPertalite;
            cout << "Jenis Bensin pertalite" << endl;
        } else {
            setHarga = hargaDexlite;
            cout << "Jenis Bensin pertamax" << endl;
        }
    } else {
        cout << "Jenis Kendaraan tidak valid" << endl;
        exit(0);
    }
}

int AlgoritmaBensin::setHargaJual(){
    int totalHargaJual = setHarga * jumlahLiter;
    return totalHargaJual;
}

// Global class
AlgoritmaBensin bensinClass;

int isValidLiter(){
    cout << "Jumlah Liter : ";
    cin >> bensinClass.jumlahLiter;
    if (!bensinClass.jumlahLiter){
        cout << "Hanya angka" << endl;
        exit(0);
    }
    return bensinClass.jumlahLiter;
}

int main(){
    // bensinClass.initHargaBensin();

    cout << "Jenis Kendaraan : ";
    cin >> bensinClass.jenisKendaraan;
    isValidLiter();

    bensinClass.checkJenisKendaraan(bensinClass.jenisKendaraan);
    int currentHargaJual = bensinClass.setHargaJual();
    int hargaAkhir = bensinClass.hargaBeli(currentHargaJual);

    cout << "Jenis Kendaraan: " << bensinClass.jenisKendaraan << endl;
    if (bensinClass.jenisSolar == ""){
        cout << "Jenis Bensin: " << bensinClass.jenisBensin << endl;
    } else {
        cout << "Jenis Solar: " << bensinClass.jenisSolar << endl;
    }
    cout << "Jumlah Liter: " << bensinClass.jumlahLiter << " Liter"<< endl;
    cout << "Harga Jual: Rp." << currentHargaJual << endl;
    cout << "Harga Pajak: Rp." << bensinClass.hargaPajak << endl;
    cout << "Harga Beli: Rp." << hargaAkhir << endl;
    return 0;
}