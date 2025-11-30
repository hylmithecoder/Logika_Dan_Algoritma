#include <HandleWindow.hpp>

void Window::StudyCase::windowStudyCase(){
    Begin("Menyelesaikan Study Case dari teman");
    case1.handleCase1();
    case2.handleCase2();
    case3.handleCase3();
    End();
}

void Window::StudyCase::Case1PunyaFauzanFadhil::handleCase1(){
    static int beratBadan = 0, tinggiBadan = 0, ideal = 0, angka1 = 0, angka2 = 0, angka3 = 0, angka4 = 0, angka5 = 0, angkaKecil = 0, angkaBesar = 0;
    static vector<int> listAngka;
    static double idealDouble = 0;
    static bool clicked = false;
    Text("Study case dari Fauzan fadhil \nBuatlah Program mencari angka terbesar dan terkecil dari 5 input.");
    Text("Masukkan angka pertama: ");
    SameLine();
    InputInt("##angka1", &angka1);
    Text("Masukkan angka kedua: ");
    SameLine();
    InputInt("##angka2", &angka2);
    Text("Masukkan angka ketiga: ");
    SameLine();
    InputInt("##angka3", &angka3);
    Text("Masukkan angka keempat: ");
    SameLine();
    InputInt("##angka4", &angka4);
    Text("Masukkan angka kelima: ");
    SameLine();
    InputInt("##angka5", &angka5);
    if (Button("Hitung angka terbesar dan terkecil")){
        listAngka.clear();
        clicked = true;
        listAngka.push_back(angka1);
        listAngka.push_back(angka2);
        listAngka.push_back(angka3);
        listAngka.push_back(angka4);
        listAngka.push_back(angka5);
        angkaBesar = angkaTerbesar(listAngka);
        angkaKecil = angkaTerkecil(listAngka);
    }
    if (angkaBesar != 0 && angkaKecil != 0){
        Text("From method");
        Text("Angka terbesar: %d", angkaBesar);
        Text("Angka terkecil: %d", angkaKecil);
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
    static int setJumlahUser = 0, jumlahUser = 0, totalUser = 0;
    static char username[256] = "", password[256] = "";
    static bool login = false, readFile = false;
    static string response = "";
    Separator();
    if (!readFile){
        readDb();
        readFile = true;
    }
    Text("Study case 3 dari Septian\nLogin Sederhana");
    if (setJumlahUser != 0){
        Text("1. Nama");
        SameLine();
        InputText("##username", username, IM_ARRAYSIZE(username));
        Text("2. Password");
        SameLine();
        InputText("##password", password, IM_ARRAYSIZE(password));
        if (totalUser != setJumlahUser){
            if (Button("Input user")){
                string convertedUsername = username;
                string convertedPassword = password;
                tambahUser(convertedUsername, convertedPassword, user);
                addToJson(convertedUsername, convertedPassword);
                totalUser++;
            }
        } else {
            if (Button("Login")){
                for (int i = 0; i < user.size(); i++){
                    if (user[i].username == username && user[i].password == password){
                        response = "Login Berhasil";
                        break;
                    } else if (user[i].username != username){
                        response = "Username Tidak Terdaftar";
                    } else if (user[i].password != password){
                        response = "Password Salah";
                    } else {
                        response = "User tidak ditemukan";
                    }
                }
            }
            Text(response.c_str());
        }
            
    } else {
        Text("Jumlah berapa orang sebagai admin");
        SameLine();
        InputInt("##jumlahoranguser", &jumlahUser);
        if (Button("Masukkan Jumlah orang")){
            setJumlahUser = jumlahUser;
        }
    }

}

void Window::StudyCase::Case3PunyaSeptian::tambahUser(string username, string password, vector<users>& currentUser){
    users user;
    user.username = username;
    user.password = password;
    currentUser.push_back(user);
}

void Window::StudyCase::Case3PunyaSeptian::readDb(){
    if (!fs::exists("database")){
        fs::create_directory("database");
    }

    ifstream f(nameFile);
    if (!f.is_open()) {
        cout << "File JSON tidak ada" << endl;
    }

    json data;
    try {
        f >> data; // Directly read into a json object
    } catch (const json::parse_error& e) {
        cout << "JSON parse error: " << e.what() << endl;
    }

    // Ensure the parsed data is indeed a JSON array
    if (!data.is_array()) {
        cerr << "JSON data is not an array!" << endl;
    }

    // Iterate through the array elements
    for (const auto& person : data) {
        // Access elements of each object in the array
        cout << "username: " << person["username"].get<string>() << endl;
        cout << "password: " << person["password"].get<string>() << endl;
        cout << "--------------------" << endl;
    }

    users currentUser;
    for (int i = 0; i < data.size(); i++){
        currentUser.username = data[i]["username"].get<string>();
        currentUser.password = data[i]["password"].get<string>();
        user.push_back(currentUser);
    }

    f.close();
}

void Window::StudyCase::Case3PunyaSeptian::addToJson(string username, string password){
    json data = {
        {"username", username},
        {"password", password}
    };
    ofstream f("database/db.json");
    f << data << endl;
}