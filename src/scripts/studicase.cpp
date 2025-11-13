#include <HandleWindow.hpp>

void Window::StudyCase::windowStudyCase(){
    Begin("Menyelesaikan Study Case dari teman");
    case1.handleCase1();
    case2.handleCase2();
    End();
}

void Window::StudyCase::Case1PunyaDaniel::handleCase1(){
    static int beratBadan = 0, tinggiBadan = 0, ideal = 0;
    static double idealDouble = 0;
    static bool clicked = false;
    Text("Study case 1 dari Daniel\nMasukkan Berat badan: ");
    InputInt("##beratbadan", &beratBadan);
    Text("Tinggi badan: ");
    SameLine();
    InputInt("##tinggibadan", &tinggiBadan);
    if (Button("Hitung keidealan")){
        clicked = true;
        idealDouble = BMI(beratBadan, tinggiBadan);
        cout << idealDouble << endl;
        ideal = BMI(beratBadan, tinggiBadan);
    }

    if (clicked){
        Text("Berat badan ideal: %d", ideal);
        setKeidealan(idealDouble);
    }
}

void Window::StudyCase::Case2PunyaWalady::handleCase2(){
    static int jumlah = 0, settedJumlahSiswa = 0, totalOrang = 0, gachaIndex = 1, getIndex = 0;
    static char name[256] = "";
    Separator();
    Text("Study case 2 dari Walady");
    if (settedJumlahSiswa != 0){
        Text("1. Nama Siswa: ");
        SameLine();
        InputText("##name", name, IM_ARRAYSIZE(name));
        if (totalOrang != settedJumlahSiswa){
            if (Button("Input Nama")){
                string convertedName = name;
                addName(listName, convertedName);
                totalOrang++;
            }
        } else {
            Text("Pilih nama dari list yang berjumlah %i", settedJumlahSiswa);
            showListName(listName);
            Text("Masukkan nomor: ");
            SameLine();
            InputInt("##gachaIndex", &gachaIndex);
            if (Button("Gacha")){
                getIndex = gacha(gachaIndex);
            }
            // if (getIndex != -1){
                Text("Siswa yang dipilih: %s", listName[getIndex].c_str());
            // }
        }
    } else {
        Text("Jumlah berapa orang yang ingin di spin");
        SameLine();
        InputInt("##jumlahorang", &jumlah);
        if (Button("Set jumlah orang")){
            settedJumlahSiswa = jumlah;
        }
    }
}

void Window::StudyCase::Case2PunyaWalady::addName(vector<string>& listName, string name){
    listName.push_back(name);
    cout << "Jumlah: " << listName.size() << endl;
}

void Window::StudyCase::Case2PunyaWalady::showListName(vector<string>& listName){
    if (BeginTable("List Nama", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        // Setup columns
        TableSetupColumn("No");
        TableSetupColumn("Nama");

        // Display headers
        TableHeadersRow();

        for (int i = 0; i < listName.size(); ++i){
            // Text("Kolom ke %i", i);
            TableNextRow(); // Start a new row

            TableSetColumnIndex(0); // Go to the first column
            Text("%i", i + 1);

            TableSetColumnIndex(1); // Go to the first column
            Text("%s", listName[i].c_str());
        }

        EndTable();
    }
}

int Window::StudyCase::Case2PunyaWalady::gacha(int index){
    index -= 1;
    int jumlah = listName.size() - 1;
    if (index > jumlah){
        index = listName.size();
    }
    int randomNumInRange = index + rand() % listName.size();
    if (randomNumInRange > jumlah){
        randomNumInRange = jumlah;
    }
    cout << randomNumInRange << endl;
    return randomNumInRange;
}

void Window::StudyCase::Case3PunyaSeptian::handleCase3(){
    Separator();
    Text("Study case 3 dari Septian\nLogin Sederhana");
    

}

void Window::StudyCase::Case3PunyaSeptian::readDb(){
    if (!fs::exists("database")){
        fs::create_directory("database");
    }

    ifstream f("example.json");
    if (!f.is_open()) {
        cout << "File JSON tidak ada" << endl;
    }

    json data = json::parse(f);
}