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
            void B_soal3();
            void C_soal2();
            void uiForPersegi(){
                static float panjang = 0;
                ImGui::Text("Masukkan Panjang");
                ImGui::InputFloat("Panjang Sisi", &panjang);
                ImGui::Text("%f x %f = %f", panjang, panjang, luasPersegi(panjang));
            };
            void uiForPersegiPanjang(){
                static float panjang = 0, lebar = 0;
                ImGui::Text("Masukkan Panjang");
                ImGui::InputFloat("Panjang Sisi", &panjang);
                ImGui::Text("Masukkan Lebar");
                ImGui::InputFloat("Lebar", &lebar);
                ImGui::Text("%f x %f = %f", panjang, lebar, luasPersegiPanjang(panjang, lebar));
            };
            void uiForLingkaran(){
                static float jari = 0;
                ImGui::Text("Masukkan jari-jari");
                ImGui::InputFloat("Jari-Jari", &jari);
                ImGui::Text("3.14 x %f x %f = %f", jari, jari, luasLingkaran(jari));
            };

            void renderPDF();

            fz_context* ctx;
            fz_document* doc;
            int currentPage = 0;
            int totalPages;
        };

        pertemuan6 praktikum6;
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