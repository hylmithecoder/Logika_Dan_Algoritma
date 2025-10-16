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
                ImGui::Text("Selamat datang di kursus Logika dan Algoritma!");
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
                ImGui::InputTextMultiline("##MyMultilineText", output, sizeof(output), ImVec2(-FLT_MIN, 0.0f));
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
                if (ImGui::Button("Tambah Siswa")){
                    currentSiswa.push_back(currentName);
                }
                if (currentSiswa.size() == 0){
                        ImGui::Text("Daftar siswa masih kosong");
                } else {
                    if (ImGui::Button("Hapus Siswa")){
                            currentSiswa.pop_back();
                    }                    
                }
                return currentSiswa;
            };
            
            void HandleCariSiswa(char* searchName, vector<string>& siswa, bool& isFound){
                ImGui::Text("Cari siswa:");
                ImGui::SameLine();
                ImGui::InputText("##Teksc_3_2", searchName, IM_ARRAYSIZE(searchName));
                ImGui::SameLine();
                if (ImGui::Button("Cari")){
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
                        ImGui::Text("Siswa tidak ditemukan");
                    }
                }
                if (isFound){
                    ImGui::Text("Siswa ditemukan: %s", searchName);
                }
            }

            void C_soal4();

            float hitungNilaiAkhir(float nilaiTugas, float nilaiUjian){
                return (nilaiTugas * 0.4) + (nilaiUjian * 0.6);
            }

            void tampilkanNilai(float nilai){
                ImGui::Text("Nilai akhir: %f", nilai);
                if (nilai >= 75) {
                    ImGui::Text("Selamat, Anda lulus!");
                } else {
                    ImGui::Text("Maaf, Anda tidak lulus!");
                }
            }

            void C_soal5();

            void showHarga(int pilihan, int jumlah, string namaMakanan = ""){
                float harga = setHarga(pilihan, jumlah);
                ImGui::Text("Makanan yang dipilih: %s", namaMakanan.c_str()); 
                ImGui::Text("Harga: $%f", harga);
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
                ImGui::Text("Masukkan Panjang");
                ImGui::InputFloat("##PanjangSisi", &panjang);
                ImGui::Text("%f x %f = %f", panjang, panjang, luasPersegi(panjang));
            };
            void uiForPersegiPanjang(){
                static float panjang = 0, lebar = 0;
                ImGui::Text("Masukkan Panjang");
                ImGui::InputFloat("##Panjang Sisi", &panjang);
                ImGui::Text("Masukkan Lebar");
                ImGui::InputFloat("##Lebar", &lebar);
                ImGui::Text("%f x %f = %f", panjang, lebar, luasPersegiPanjang(panjang, lebar));
            };
            void uiForLingkaran(){
                static float jari = 0;
                ImGui::Text("Masukkan jari-jari");
                ImGui::InputFloat("##Jari-Jari", &jari);
                ImGui::Text("3.14 x %f x %f = %f", jari, jari, luasLingkaran(jari));
            };

            void renderPDF();

            fz_context* ctx;
            fz_document* doc;
            int currentPage = 0;
            int totalPages;
        };

        pertemuan6 praktikum6;

        struct TableDataSekolah {

            struct baseDataSiswa {
                string namasiswa;
                int NIS;
                string NamaIbu;
                int NIKIbu;
            };

            struct TKTable {
                baseDataSiswa dataSiswa[100];
            };

            struct SDTable {
                baseDataSiswa dataSiswa[100];
                string asalTK;
            };

            struct SMPTable {
                baseDataSiswa dataSiswa[100];
                string asalTK;
                string asalSD;
                int noIjazahSD;
            };

            struct SMATable {
                baseDataSiswa dataSiswa[100];
                string asalTK;
                string asalSD;
                int noIjazahSD;
                string asalSMP;
                int noIjazahSMP;
            };

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