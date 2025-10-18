#pragma once
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "backends/imgui_impl_glfw.h"
#include <mupdf/fitz.h>
#include "backends/imgui_impl_opengl3.h"
#include <vector>
#include "imgui.h"
using namespace std;
using namespace ImGui;

class Window{
    public:
        GLFWwindow* window;
        ImGuiIO g_io;
        Window(int currentHeight, int currentWidth ): ctx(nullptr), doc(nullptr), pdfLoaded(false), window(nullptr){
            this->height = currentHeight;
            this->width = currentWidth;
        }

        void init();

        int height, width;
        void error_callback(int error, const char* description);
        void Update(ImGuiIO& io);
        void Events();
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        void Clean();

        // Handle main ui
        void Main();

        vector<GLuint> readPDFFile(const char* filePath);
        // Ui nya
        void kalkulatorWindow();
        void handleButton(float& angka1, float& angka2);
        float tambah(const float& angka1, const float& angka2);
        float kurang(const float& angka1, const float& angka2);
        float kali(const float& angka1, const float& angka2);
        float bagi(const float& angka1, const float& angka2);

        float hasil = 0;
        string eksekusi = "";

        // choice module
        void choiceModule();
        void handleChoice();

        struct pertemuan2 {
            vector<GLuint> currentPageTextures;
            int currentPage = 0;
            int totalPages;
            void uipertemuan2();
            void soal1();
            void soal2();
            void renderPDF();
        };
        pertemuan2 praktikum2;

        struct pertemuan4 {
            vector<GLuint> currentPageTextures;
            int currentPage = 0;
            int totalPages;
            void uipertemuan4();
            void renderPDF();
        };
        pertemuan4 praktikum4;

        struct pertemuan6 {
            vector<GLuint> currentPageTextures;
            void uipertemuan6();
            void handleStudyKasus(int currentStudyKasus){
                switch (currentStudyKasus) {
                    case 0 :
                        A_soal1();
                        A_soal2();
                        A_soal3();
                        A_soal4();
                        A_soal5();
                        break;
                    
                    case 1:
                        B_soal1();
                        B_soal2();
                        B_soal3();
                        B_soal4();
                        B_soal5();
                        break;
                    
                    case 2:
                        C_soal1();
                        C_soal2();
                        C_soal3();
                        C_soal4();
                        C_soal5();
                        break;

                    default:
                        break;
                }
            }
            void A_soal1();
            int tambah(int a, int b){
                return a + b;
            }

            void tampilkanPesan() {
                Text("Selamat datang di kursus Logika dan Algoritma!");
            }

            float luasPersegiPanjang(float panjang, float lebar) {
                return panjang * lebar;
            }

            int panjangString(string str) {
                return str.length();
            }

            float luasPersegi(float sisi) {
                return sisi * sisi;
            }

            float luasLingkaran(float radius) {
                return 3.14 * radius * radius;
            }

            void A_soal2();
            void A_soal3();
            void A_soal4();

            int faktorial(int n){
                if (n == 0) return 1;
                return n * faktorial(n - 1);
            }

            void A_soal5();

            void cetakGenap(int n){
                static char output[256] = "";
                int offset = 0;
                output[0] = '\0';
                for (int i = 2; i <= n; i += 2){
                    int chars_written = snprintf(output + offset, sizeof(output) - offset, "%d ", i);
                    if (chars_written > 0 && (offset + chars_written) < sizeof(output)) {
                        offset += chars_written;
                    } else {
                        break;
                    }
                }
                InputTextMultiline("##MyMultilineText", output, sizeof(output), ImVec2(-FLT_MIN, 0.0f));
            }

            void B_soal1();

            int kuadrat(int n){
                return n * n;
            }

            void B_soal2();

            float hitungRataRata(float  a, float b, float c){
                return (a + b + c) / 3;
            }

            void B_soal3();

            void B_soal4();

            int tukarNilai(int& a, int& b){
                a = b;
                return a;
            }

            void B_soal5();

            int maximum(int a, int b){
                return (a > b) ? a : b;
            }

            float hasilKalkulator = 0;
            void C_soal1();
            void C_soal2();
            void C_soal3();
            vector<string> handleButtonCSoal3(vector<string> currentSiswa, string& currentName){
                if (Button("Tambah Siswa")){
                    currentSiswa.push_back(currentName);
                }
                if (currentSiswa.size() == 0){
                        Text("Daftar siswa masih kosong");
                } else {
                    if (Button("Hapus Siswa")){
                            currentSiswa.pop_back();
                    }                    
                }
                return currentSiswa;
            };
            
            void HandleCariSiswa(char* searchName, vector<string>& siswa, bool& isFound){
                Text("Cari siswa:");
                SameLine();
                InputText("##Teksc_3_2", searchName, IM_ARRAYSIZE(searchName));
                SameLine();
                if (Button("Cari")){
                    isFound = false;
                    cout << "Search name: " << searchName << endl;
                    for (const string& name : siswa){
                        if (name == searchName){
                            cout << "Siswa ditemukan: " << name << endl;
                            isFound = true;
                            break;
                        }
                    }
                    if (!isFound){
                        Text("Siswa tidak ditemukan");
                    }
                }
                if (isFound){
                    Text("Siswa ditemukan: %s", searchName);
                }
            }

            void C_soal4();

            float hitungNilaiAkhir(float nilaiTugas, float nilaiUjian){
                return (nilaiTugas * 0.4) + (nilaiUjian * 0.6);
            }

            void tampilkanNilai(float nilai){
                Text("Nilai akhir: %f", nilai);
                if (nilai >= 75) {
                    Text("Selamat, Anda lulus!");
                } else {
                    Text("Maaf, Anda tidak lulus!");
                }
            }

            void C_soal5();

            void showHarga(int pilihan, int jumlah, string namaMakanan = ""){
                float harga = setHarga(pilihan, jumlah);
                Text("Makanan yang dipilih: %s", namaMakanan.c_str()); 
                Text("Harga: $%f", harga);
            }

            float setHarga(int pilihan, int jumlah){
                switch (pilihan){
                    case 0:
                        return 10 * jumlah;
                    case 1:
                        return 8 * jumlah;
                    case 2:
                        return 12 * jumlah;
                    default:
                        return 0;
                }
            }

            void uiForPersegi(){
                static float panjang = 0;
                Text("Masukkan Panjang");
                InputFloat("##PanjangSisi", &panjang);
                Text("%f x %f = %f", panjang, panjang, luasPersegi(panjang));
            };
            void uiForPersegiPanjang(){
                static float panjang = 0, lebar = 0;
                Text("Masukkan Panjang");
                InputFloat("##Panjang Sisi", &panjang);
                Text("Masukkan Lebar");
                InputFloat("##Lebar", &lebar);
                Text("%f x %f = %f", panjang, lebar, luasPersegiPanjang(panjang, lebar));
            };
            void uiForLingkaran(){
                static float jari = 0;
                Text("Masukkan jari-jari");
                InputFloat("##Jari-Jari", &jari);
                Text("3.14 x %f x %f = %f", jari, jari, luasLingkaran(jari));
            };

            void renderPDF();

            fz_context* ctx;
            fz_document* doc;
            int currentPage = 0;
            int totalPages;
        };

        pertemuan6 praktikum6;

        struct pertemuan7 {
            struct Barang {
                string nama;
                int jumlah;
                double harga;
            };

            struct Buku {
                string judul;
                string penulis;
                int tahunTerbit;
            };

            struct Kamar {
                string nomorKamar;
                string tipe;
                double harga;
            };
            struct Reservasi {
                string namaPelanggan;
                string tanggalMasuk;
                string tanggalKeluar;
            };

            struct Jabatan {
                string namaJabatan;
            };
            struct Karyawan {
                string nama;
                double gaji;
                Jabatan jabatan;
            };

            void baseTable(char* label, auto tableData, int baris, int kolom, auto namaKolom){
                 if (BeginTable(label, kolom, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
                    // Setup columns
                    TableSetupColumn("Nama Siswa");
                    TableSetupColumn("NIS");
                    TableSetupColumn("Nama Ibu");
                    TableSetupColumn("NIK Ibu");
                    // Display headers
                    TableHeadersRow();

                    for (int i = 1; i <= baris ; ++i){
                        // Text("Kolom ke %i", i);
                        TableNextRow(); // Start a new row

                        TableSetColumnIndex(0); // Go to the first column
                        Text("%s", tableData[i].namasiswa.c_str());
                        
                        TableSetColumnIndex(1); // Go to the first column
                        Text("%i", tableData[i].NIS);
                        
                        TableSetColumnIndex(2); // Go to the first column
                        Text("%s", tableData[i].NamaIbu.c_str());
                        
                        TableSetColumnIndex(3); // Go to the first column
                        Text("%i", tableData[i].NIKIbu);

                        TableSetColumnIndex(4); // Go to the first column
                    }

                    EndTable();
                }    
            }

            void ui(){
                Begin("Pertemuan 7");
                Text("Pertemuan 7 Array");
                contohPenggunaanArray();
                studyKasus1();
                studyKasus2();
                studyKasus3();
                studyKasus4();
                studyKasus5();
                contohTableArray2Dimensi();
                contohTableArray3Dimensi();
                End();
            }

            void contohPenggunaanArray();
            void studyKasus1();
            void studyKasus2();
            void studyKasus3();
            void studyKasus4();
            void studyKasus5();

            void contohTableArray2Dimensi();
            void contohTableArray3Dimensi();
        };

        pertemuan7 praktikum7;

        struct TableDataSekolah {

            struct baseDataSiswa {
                string namasiswa;
                int NIS;
                string NamaIbu;
                int NIKIbu;
            };

            struct TKTable : baseDataSiswa {
            };

            struct SDTable : TKTable {
                string asalTK;
            };

            struct SMPTable : SDTable {
                string asalSD;
                int noIjazahSD;
            };

            struct SMATable : SMPTable {
                string asalSMP;
                int noIjazahSMP;
            };

            char* inputText(const char* label){
                static char buffer[256];
                SameLine();
                InputText(label, buffer, 256);
                return buffer;
            }

            int inputInt(const char* label){
                static int value = 0;
                SameLine();
                InputInt(label, &value);
                return value;
            }

            void uidataSekolah();
            void submitToTKTable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu);
            void submitToSDTable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu, string& asalTK); 
            void submitToSMPTable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu, string& asalTK, string& asalSd, int& noIjazahSD);
            void submitToSMATable(string& namasiswa, string& namaIbu, int& NIS, int& NIKIbu, string& asalTK, string& asalSd, int& noIjazahSD, string& asalSMP, int& noIjazahSmp);
           
            void showTableTK(TKTable tableData[]);
            void showTableSD(SDTable tableData[]);
            void showTableSMP(SMPTable tableData[]);
            void showTableSMA(SMATable tableData[]);
            int currentBarisTk = 0;
            int currentBarisSd = 0;
            int currentBarisSmp = 0;
            int currentBarisSma = 0;
            TKTable tableDataTK[100];
            SDTable tableDataSD[100];
            SMPTable tableDataSMP[100];
            SMATable tableDataSMA[100];

            void uiTypeTk();
            void uiTypeSd();
            void uiTypeSmp();
            void uiTypeSma();
            void deleteDataSiswaTypeTk(TKTable tableData[], int& currentBarisTk);
            void deleteDataSiswaTypeSd(SDTable tableData[], int& currentBarisSd);
            void deleteDataSiswaTypeSmp(SMPTable tableData[], int& currentBarisSmp);
            void deleteDataSiswaTypeSma(SMATable tableData[], int& currentBarisSma);
            void editDataSiswaTypeTk(TKTable tableData[], int& currentBarisTk);
            void editDataSiswaTypeSd(SDTable tableData[], int& currentBarisSd);
            void editDataSiswaTypeSmp(SMPTable tableData[], int& currentBarisSmp);
            void editDataSiswaTypeSma(SMATable tableData[], int& currentBarisSma);
        };

        TableDataSekolah dataSekolah;

        vector<GLuint> pageTextures;

    private:
        fz_context* ctx;
        fz_document* doc;
        bool pdfLoaded;
        
        GLuint createTextureFromPixmap(fz_pixmap* pix);
        void cleanup();
        void renderPDF(const vector<GLuint>& currentPageTextures, int& currentPage, const int& totalPages);
        void initMuPDF();
        int totalPages;
        int getPagePDF(const char* filePath);

        char* filePaths[6] = {
            "/home/hylmi/Downloads/Praktikum 2e-h - LOGIKA MATEMATIKA DALAM C++.docx.pdf",
            "/home/hylmi/Downloads/Praktikum 4 - Percabangan dalam Pemrograman.docx.pdf",
            "/home/hylmi/Downloads/praktikum6.pdf"
        };
};