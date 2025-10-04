#pragma once
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"
using namespace std;

class Window{
    public:
        GLFWwindow* window;
        ImGuiIO g_io;
        Window(int currentHeight, int currentWidth){
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
};