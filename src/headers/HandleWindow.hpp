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
        double number;
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
        void handleButton(double& angka1, double& angka2);
        double tambah(const double& angka1, const double& angka2);
        double kurang(const double& angka1, const double& angka2);
        double kali(const double& angka1, const double& angka2);
        double bagi(const double& angka1, const double& angka2);

        double hasil = 0;
        string eksekusi = "";
};