#include <HandleWindow.hpp>

void Window::pertemuan2::soal1(){
    static int nilaiSiswa, nilaiKehadiran;
    ImGui::Separator();
    ImGui::Text("1. Program untuk operator AND\nMasukkan nilai siswa: ");
    ImGui::InputInt("##soal1", &nilaiSiswa);
    ImGui::Text("Masukkan persentasi kehadiran siswa: ");
    ImGui::InputInt("##soal2", &nilaiKehadiran);
    bool lulus = (nilaiSiswa >= 75) && (nilaiKehadiran >= 75);
    if (lulus){
        ImGui::Text("Selamat, Anda lulus!");
    } else if (nilaiSiswa == 0 || nilaiKehadiran == 0){
        ImGui::Text("Isi ke dua nilai terlebih dahulu");
    } else {
        ImGui::Text("Maaf, Anda tidak lulus!");
    }
}

void Window::pertemuan2::soal2(){
    static bool ikutSeminar;
    static int selectedOption1 = 0, selectedOption2 = 0;
    ImGui::Separator();
    ImGui::Text("2. Program untuk operator Or\nApakah siswa mengikuti seminar: ");
    ImGui::SameLine();
    ImGui::RadioButton("##Ya1", &selectedOption1, 1);
    ImGui::SameLine();
    ImGui::RadioButton("##Tidak1", &selectedOption1, 2);
    ImGui::Text("Apakah siswa memiliki tugas tambahan: ");
    ImGui::SameLine();
    ImGui::RadioButton("##Ya2", &selectedOption2, 1);
    ImGui::SameLine();
    ImGui::RadioButton("##Tidak2", &selectedOption2, 2);
    if (selectedOption1 == 0 && selectedOption2 == 0){
    } else {
        ikutSeminar = (selectedOption1 == 1) || (selectedOption2 == 1);
        if (ikutSeminar){
            ImGui::Text("Siswa dibebaskan dari ujian");
        } else {
            ImGui::Text("Siswa harus mengikuti ujian");
        }            
    }
}