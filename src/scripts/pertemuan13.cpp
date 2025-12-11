#include <HandleWindow.hpp>

void Window::Pertemuan13::windowPer13(){
    Begin("Pertemuan 13");
    Window* parent = (Window*)this;
    Text("Latihan Menggunakan Rekursif dan Algoritma Pengurutan");
    parent->renderPDF(currentPageTextures, currentPage, totalPages);
    soal1();
    soal2();
    soal3();
    soal4();
    soal5();
    End();
}

void Window::Pertemuan13::soal1(){
    static int target = 0, banyak = 0, currentDuration = 0, setBanyak = 0, setTarget = 0;
    static int* arr = nullptr;
    static bool search = false, found = false;
    Text("Soal 1 Mengukur Waktu Eksekusi Algoritma Pencarian Linear");
    Text("Masukkan banyak elemen dalam array:");
    SameLine();
    InputInt("##InputBanyakElemen", &banyak);
    if (Button("Buat Array")){
        arr = new int[banyak];
        setBanyak = banyak;
    }
    if (arr != nullptr){
        Text("Masukkan elemen yang ingin dicari:");
        SameLine();
        InputInt("##InputTargetElemen", &target);
        
        if (Button("Cari Elemen")){
            setTarget = target;
            for (int i = 0; i < setBanyak; i++){
                arr[i] = i;
            }
            auto start = chrono::high_resolution_clock::now();
            found = linearSearch(arr, setBanyak, target);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;
            currentDuration = duration.count();
            string isFound = found ? "ditemukan" : "tidak ditemukan";
            cout << "Elemen "<< target << " " << isFound << endl;
            cout << "\nWaktu eksekusi: " << currentDuration << " ms" << endl;
        }
        if (found){
            Text("Elemen %d %s dalam array.", setTarget, found ? "ditemukan" : "tidak ditemukan");
            Text("\nWaktu eksekusi: %i ms", currentDuration);
        }
    }
}

void Window::Pertemuan13::soal2(){
    static int target = 0, banyak = 0, currentDuration = 0, setBanyak = 0, setTarget = 0;
    static int* arr = nullptr;
    static bool search = false, found = false;
    Separator();
    Text("Soal 2 Mengukur Waktu Eksekusi Algoritma Pencarian Linear");
    Text("Masukkan banyak elemen dalam array:");
    SameLine();
    InputInt("##InputBanyakElemen2", &banyak);
    if (Button("Ubah Array")){
        arr = new int[banyak];
        setBanyak = banyak;
    }

    if (arr != nullptr){
        Text("Masukkan elemen yang ingin dicari:");
        SameLine();
        InputInt("##InputTargetElemen2", &target);
        
        if (Button("Cari biner")){
            setTarget = target;
            for (int i = 0; i < setBanyak; i++){
                arr[i] = i;
            }
            auto start = chrono::high_resolution_clock::now();
            found = binarySearch(arr, setBanyak, target);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;
            currentDuration = duration.count();
            Text("Elemen %d %s dalam array.", target, found ? "ditemukan" : "tidak ditemukan");
            Text("\nWaktu eksekusi: %f ms", currentDuration);
            string isFound = found ? "ditemukan" : "tidak ditemukan";
            cout << "Elemen "<< target << " " << isFound;
            cout << "\nWaktu eksekusi: " << currentDuration << " ms";
        }
        if (found){
            Text("Elemen %d %s dalam array.", setTarget, found ? "ditemukan" : "tidak ditemukan");
            Text("\nWaktu eksekusi: %i ms", currentDuration);
        }
    }
}

void Window::Pertemuan13::soal3(){
    static int banyak = 0, currentDuration = 0, setBanyak = 0;
    static bool isClicked = false;
    static int* arr = nullptr;
    Separator();
    Text("Soal 3 Mengukur Waktu Eksekusi Algoritma Pengurutan Bubble Sort");
    Text("Masukkan banyak elemen dalam array:");
    SameLine();
    InputInt("##InputBanyakElemen3", &banyak);
    if (Button("Buat Array Pengurutan")){
        arr = new int[banyak];
        setBanyak = banyak;
    }

    if (arr != nullptr){
        if (Button("Urutkan Array")){
            for (int i = 0; i < setBanyak; i++){
                arr[i] = rand() % setBanyak;
            }
            auto start = chrono::high_resolution_clock::now();
            isClicked = true;
            bubbleSort(arr, setBanyak);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;
            currentDuration = duration.count();
            cout << "\nWaktu eksekusi: " << currentDuration << " ms";
        }
        if (isClicked){
            Text("\nWaktu eksekusi: %i ms", currentDuration);
        }
    }
}

void Window::Pertemuan13::soal4(){
    static int banyak = 0, currentDuration = 0, setBanyak = 0;
    static bool isClicked = false;
    static int* arr = nullptr;
    Separator();
    Text("Soal 4 Selection sort");
    Text("Masukkan banyak elemen dalam array:");
    SameLine();
    InputInt("##InputBanyakElemen4", &banyak);
    if (Button("Buat Array Untuk selection sort")){
        arr = new int[banyak];
        setBanyak = banyak;
    }

    if(arr != nullptr)
    {
        if (Button("Selection Sort")){
            for (int i = 0; i < setBanyak; i++){
                arr[i] = rand() % setBanyak;
            }
            auto start = chrono::high_resolution_clock::now();
            selectionSort(arr, setBanyak);
            isClicked = true;
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;
            currentDuration = duration.count();
            cout << "\nWaktu eksekusi: " << currentDuration << " ms";
        }
        if (isClicked){
            Text("\nWaktu eksekusi: %i ms", currentDuration);
        }
    }
}

void Window::Pertemuan13::soal5(){
    static int banyak = 0, currentDuration = 0, setBanyak = 0;
    static int* arr = nullptr;
    Separator();
    Text("Soal 5 Insertion sort");
    Text("Masukkan banyak elemen dalam array:");
    SameLine();
    InputInt("##InputBanyakElemen5", &banyak);
    if (Button("Buat Array untuk insertion array")){
        arr = new int[banyak];
        setBanyak = banyak;
    }

    if(arr != nullptr)
    {
        if (Button("Insertion Sort")){
            for (int i = 0; i < setBanyak; i++){
                arr[i] = rand() % setBanyak; // Mengisi array dengan bilangan acak
            }
            auto start = chrono::high_resolution_clock::now();
            quickSort(arr, 0, setBanyak - 1);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;
            currentDuration = duration.count();
            cout << "\nWaktu eksekusi: " << currentDuration << " ms";
        }
        Text("\nWaktu eksekusi: %i ms", currentDuration);
    }
}