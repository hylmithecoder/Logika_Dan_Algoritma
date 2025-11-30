#include <HandleWindow.hpp>

void Window::Pertemuan12::windowPer12(){
    Begin("Pertemuan 12");

    Text("Latihan Menggunakan Struktur Data Stack dan Queue");
    soal1();
    soal2();
    soal3();
    soal4();
    End();
}

void Window::Pertemuan12::soal1(){
    static int stackValue = 0;
    Text("Latihan Stack dengan C++");
    Text("1. Push Nilai ke Stack");
    SameLine();
    InputInt("##InputPushStack", &stackValue);
    if (Button("Push")){
        stak.push(stackValue);
    }
    Text("2. Pop Nilai dari Stack");
    if (Button("Pop")){
        stak.pop();
    }
    stak.peek();
}

void Window::Pertemuan12::soal2(){
    static int queueValue = 0;
    Separator();
    Text("Latihan Queue dengan C++");

    Text("1. Tambah Nilai ke Queue");
    SameLine();
    InputInt("##InputPushQueue", &queueValue);
    if (Button("Enqueue")){
        queueClass.enqueue(queueValue);
    }
    Text("2. Hapus Nilai dari Queue");
    if (Button("Dequeue")){
        queueClass.dequeue();
    }
    queueClass.peek();
}

void Window::Pertemuan12::soal3(){
    static int arr[MAX], count = 0, input = 0;
    Separator();
    
    Text("Menyusun angka menggunakan Stack");
    if (count < MAX){
        Text("Masukkan angka ke-%i: ", count + 1);
        SameLine();
        InputInt("##InputAngkaStack", &input);
        if (Button("Tambah Angka")){
            arr[count++] = input;
        }
    } else {
        Text("Array penuh! Tidak bisa menambahkan angka lagi.");
        Text("Urutan angka: ");
        for (int i = 0; i < count; i++){
            Text(" %d ", arr[i]);
        }
        reverseNumbers(arr, count);
        Text("Hapus nilai dari stack");
    }
    if (count > 1){
        if (Button("Hapus Stack")){
            stak.pop();
            count -= 1;
        }
    }
}

void Window::Pertemuan12::soal4(){
    bankQueueSimulation();
}

void Window::Pertemuan12::bankQueueSimulation() {
    static char buffer[256];
    static string name;
    static queue<string> q;
    static vector<string> saveQueue;
    Separator();
    Text("Simulasi Antrian Bank");
    Text("Masukkan nama pelanggan:");
    InputText("##NamaPelanggan", buffer, 256);
    SameLine();
    if (Button("Tambah Pelanggan")) {
        name = buffer;
        q.push(name);
    }

    if (!q.empty()) {
        Text("Semua pelanggan dalam antrian:");
        string currentPelanggan = q.front();
        Text("Pelanggan yang ingin dilayani: %s", q.front().c_str());
        if (Button("Layani Pelanggan")){
            q.pop();
            saveQueue.push_back(currentPelanggan);
        }
    } else {
        Text("Antrian kosong.");
    }
    Text("Histori antrian:");
    for (int i = 0; i < saveQueue.size(); i++) {
        Text("%s", saveQueue[i].c_str());
    }
}