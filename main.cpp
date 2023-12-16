#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

struct Barang{
    char noResi[10];
    char pengirim[50];
    char alamatPengirim[50];
    char kodeposPengirim[10];
    char noPengirim[13];
    char penerima[50];
    char alamatPenerima[50];
    char kodeposPenerima[10];
    char noPenerima[13];
    char jenisBarang[100];
    char ekspedisi[30];
    char pulau[5];
    char bank[10];
    int jarak;
    char jenisPengiriman[20];
    double berat;
    double totalHarga;
    double p;
    double l;
    double t;
    double rumus;
    char metodePembayaran[20];
    char noReferensi[15];
    char status[20];
    time_t tanggalKirim;
    time_t tanggalDiterima;
    Barang* next;
};

struct User{
    char username[50];
    char password[6];
    Barang* antrianBarang;
    User* next;
};

struct Ekspedisi {
    char nama[30];
    char username[30];
    char password[30];
    User* daftarUser;
    Ekspedisi* next;
};

void tampilanAwal();
void loadingBar();
void saveData(User* userList);
void loadData(User*& userList);
User* loginUser(User* userList);
void createUser(User*& userList);
void kirimBarang(User* currentUser, Ekspedisi* ekspedisiList);
void tampilkanAntrian(Ekspedisi* currentEkspedisi);
void antarSemuaBarang(const string& namaFile, const string& namaEkspedisi);
void cariBarang(const string& namaFile, const string& namaEkspedisi);
void statusBarang(const string& namaFile);
void displayMenuUser(User* currentUser, Ekspedisi* ekspedisiList);
void displayMenuAdmin(const string& namaEkspedisi);
void hitungBiayaJTExpress(Barang* newBarang);
void hitungBiayaNinjaExpress(Barang* newBarang);
void hitungBiayaWahanaLogistik(Barang* newBarang);
void hitungBiayaGosend(Barang* newBarang);
void biayaJTExpress(Barang* newBarang);
void biayaNinjaExpress(Barang* newBarang);
void biayaWahanaLogistik(Barang* newBarang);
void biayaGosend(Barang* newBarang);
void noRek();
void tampilanHarga(User* currentUser, Ekspedisi* ekspedisiList, Barang* newBarang);
void cekHarga(User* currentUser, Ekspedisi* ekspedisiList);
void waktu(int daysToAdd, int daysToAdd2);
void keluar();

int main(){
    User* userList = nullptr;
    Ekspedisi* ekspedisiList = nullptr;
    loadData(userList);
    tampilanAwal();
    loadingBar();

    while(true){
        cout << "Selamat Datang," << endl;
        cout << "Silahkan pilih peranmu!" << endl;
        cout << "----------    -----------    ------------" << endl;
        cout << "| 1.User |    | 2.Admin |    | 3.Keluar |" << endl;
        cout << "----------    -----------    ------------" << endl;
        cout << "Pilih menu: "; int choice; cin >> choice;
        system("cls");

        switch(choice){
            case 1:{
                cout << "========================" << endl;
                cout << "       Menu User        " << endl;
                cout << "========================" << endl;
                cout << "1. Create Account       " << endl;
                cout << "2. Login                " << endl;
                cout << "3. Kembali ke Menu Utama" << endl;
                cout << "4. Keluar               " << endl;
                cout << "========================" << endl;
                cout << "Pilih menu: "; int userChoice; cin >> userChoice;
                system("cls");

                switch(userChoice){
                    case 1:
                        createUser(userList);
                        saveData(userList);
                        break;
                    case 2:{
                        User* currentUser = loginUser(userList);
                        if(currentUser != nullptr){
                            displayMenuUser(currentUser, ekspedisiList);
                        }
                        break;
                    }
                    case 3:
                        break;
                    case 4:
                        keluar();
                        break;
                    default:
                        cout << "Pilihan tidak valid! Silahkan coba lagi." << endl;
                }
                break;
            }
            case 2:{
                string adminUsername, adminPassword;
                cout << "========================" << endl;
                cout << "      Pilih Admin       " << endl;
                cout << "========================" << endl;
                cout << "1. J&T Express          " << endl;
                cout << "2. Ninja Express        " << endl;
                cout << "3. Wahana Logistik      " << endl;
                cout << "4. Gosend               " << endl;
                cout << "5. Kembali ke Menu Utama" << endl;
                cout << "6. Keluar               " << endl;
                cout << "========================" << endl;
                cout << "Pilih admin: "; int adminChoice; cin >> adminChoice;
                system("cls");

                switch(adminChoice){
                    case 1:{
                        cout << "Masukkan username admin: "; cin >> adminUsername;
                        cout << "Masukkan password admin: "; cin >> adminPassword;
                        system("cls");
                        Ekspedisi* currentEkspedisi = ekspedisiList;
                        if(adminUsername == "jnt" && adminPassword == "123456"){
                                displayMenuAdmin("J&T Express");
                                break;
                        }
                            currentEkspedisi = currentEkspedisi->next;
                        if(adminUsername != "jnt" || adminPassword != "123456"){
                            cout << "Username atau password admin salah." << endl;
                            system("pause");
                            system("cls");
                            break;
                        }}
                        break;
                    case 2:{
                        cout << "Masukkan username admin: "; cin >> adminUsername;
                        cout << "Masukkan password admin: "; cin >> adminPassword;
                        system("cls");
                        Ekspedisi* currentEkspedisi = ekspedisiList;
                        if(adminUsername == "ninja" && adminPassword == "123456"){
                                displayMenuAdmin("Ninja Express");
                                break;
                        }
                            currentEkspedisi = currentEkspedisi->next;
                        if(adminUsername != "ninja" || adminPassword != "123456"){
                            cout << "Username atau password admin salah." << endl;
                            system("pause");
                            system("cls");
                            break;
                        }}
                        break;
                    case 3:{
                        cout << "Masukkan username admin: "; cin >> adminUsername;
                        cout << "Masukkan password admin: "; cin >> adminPassword;
                        system("cls");
                        Ekspedisi* currentEkspedisi = ekspedisiList;
                        if(adminUsername == "wahana" && adminPassword == "123456"){
                                displayMenuAdmin("Wahana Express");
                                break;
                        }
                            currentEkspedisi = currentEkspedisi->next;
                        if(adminUsername != "wahana" || adminPassword != "123456"){
                            cout << "Username atau password admin salah." << endl;
                            system("pause");
                            system("cls");
                            break;
                        }}
                        break;
                    case 4:{
                        cout << "Masukkan username admin: "; cin >> adminUsername;
                        cout << "Masukkan password admin: "; cin >> adminPassword;
                        system("cls");
                        Ekspedisi* currentEkspedisi = ekspedisiList;
                        if(adminUsername == "gosend" && adminPassword == "123456"){
                                displayMenuAdmin("Gosend Instan");
                                break;
                        }
                            currentEkspedisi = currentEkspedisi->next;
                        if(adminUsername != "gosend" || adminPassword != "123456"){
                            cout << "Username atau password admin salah." << endl;
                            system("pause");
                            system("cls");
                            break;
                        }}
                        break;
                    case 5:
                        break;
                    case 6:
                        keluar();
                        break;
                    default:
                        cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
                }
                break;
            }
            case 3:{
                saveData(userList);
                keluar();
                return 0;
            }
            default:
                cout << "Pilihan tidak valid! Silahkan coba lagi." << endl;
        }
    }
    return 0;
}

void tampilanAwal(){
    system("color 3");
    cout << "\t\t\t\t\t HAI (ganti)" << endl;
    cout << endl;
    cin.get();
	system("cls");
}

void loadingBar(){
    system("color 0F");
    char a = 177, b = 219;

    cout << "\n\n\n\n";
    cout << "\n\n\n\n\t\t\t\t\tTunggu sebentar ya!\n\n";
    cout << "\t\t\t\t\t";

    for(int i = 0; i < 26; i++)
        cout << a;
        cout << "\r";
        cout << "\t\t\t\t\t";

    for(int i = 0; i < 26; i++){
        cout << b;
        Sleep(50);
    }
    system("cls");
}

void keluar(){
    cout << "Terima Kasih!" << endl;
    exit(0);
}

void noRek(){
        cout << "NOMOR REKENING                                          " << endl;
        cout << "============================================================================" << endl;
        cout << "BCA 6236708085 a.n. Tiga Belas Aselole                  " << endl;
        cout << "BRI 13623670 a.n. Tiga Belas Aselole                    " << endl;
        cout << "BNI 138085 a.n. Tiga Belas Aselole                      " << endl;
        cout << "Mandiri 1401106236708085 a.n. Tiga Belas Aselole        " << endl;
        cout << "============================================================================" << endl;
        system("pause");
        system("cls");
}

string noResi(int length, const string& firstChars){
    string chars = "1234567890";
    string ekspedisi = firstChars;

    for (int i = firstChars.length(); i < length; i++) {
        int index = rand() % chars.length();
        ekspedisi += chars[index];
    }
    return ekspedisi;
}

void waktu(int daysToAdd, int daysToAdd2){
    time_t t = time(0);
    tm* start_date = localtime(&t);
    tm* end_date = localtime(&t);

    start_date->tm_mday += daysToAdd;
    mktime(start_date);

    tm end_date_copy = *start_date;
    end_date_copy.tm_mday += daysToAdd2;
    mktime(&end_date_copy);

    const char* monthNames[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

    cout << start_date->tm_mday << "-" << end_date_copy.tm_mday << " " << monthNames[end_date_copy.tm_mon] << " " << (end_date_copy.tm_year + 1900) << endl;
}

string getHiddenPassword(){
    string password = "";
    char ch;
    while((ch = _getch()) != '\r'){
        if(ch == '\b'){
            if(!password.empty()){
                password.pop_back();
                cout << "\b \b";
            }
        }
        else{
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

User* loginUser(User* userList){
    string username, password;
    cout << "Masukkan username: "; cin >> username;
    cout << "Masukkan password: "; password = getHiddenPassword();
    system("cls");

    User* currentUser = userList;
    while (currentUser != nullptr){
        if (username == currentUser->username && password == currentUser->password){
            return currentUser;
        }
        currentUser = currentUser->next;
    }

    cout << "Username atau password salah." << endl;
    system("cls");
    return nullptr;
}

void createUser(User*& userList){
    string username, password;
    cout << "Masukkan username baru: "; cin >> username;
    User* checkUser = userList;
    while(checkUser != nullptr){
        if (username == checkUser->username){
            cout << "Username sudah digunakan. Pilih username lain." << endl;
            return;
        }
        checkUser = checkUser->next;
    }

    do{
        cout << "Masukkan password baru (6 digit): "; cin >> password;
        if (password.length() != 6){
            system("cls");
            cout << "Password harus terdiri dari 6 digit. Silahkan coba lagi." << endl;
        }
    }
    while (password.length() != 6);
    User* newUser = new User;
    strcpy(newUser->username, username.c_str());
    strcpy(newUser->password, password.c_str());
    newUser->next = userList;
    newUser->antrianBarang = nullptr;
    userList = newUser;

    cout << "Akun berhasil dibuat!" << endl;
    system("cls");
}

void saveData(User* userList){
    ofstream userFile("User.txt");
    if (!userFile.is_open()){
        return;
    }
    User* currentUser = userList;
    while(currentUser != nullptr){
        userFile << currentUser->username<< " " << currentUser->password << endl;
        currentUser = currentUser->next;
    }
    userFile.close();
}

void loadData(User*& userList) {
    ifstream userFile("User.txt");
    if (!userFile.is_open()){
        return;
    }
    while(!userFile.eof()){
        User* newUser = new User;
        userFile >> newUser->username >> newUser->password;
        newUser->next = userList;
        newUser->antrianBarang = nullptr;
        userList = newUser;
    }
    userFile.close();
}

void kirimBarang(User* currentUser, Ekspedisi* ekspedisiList){
    double a;
    int pil;
    Barang* newBarang = new Barang;
    cout << "==================================================" << endl;
    cout << "                  Data Pengirim                   " << endl;
    cout << "==================================================" << endl;
    cout << "Nama Pengirim  : "; cin.ignore(); cin.getline(newBarang->pengirim, sizeof(newBarang->pengirim));
    cout << "Nomor Telepon  : "; cin.getline(newBarang->noPengirim, sizeof(newBarang->noPengirim));
    cout << "Alamat         : "; cin.getline(newBarang->alamatPengirim, sizeof(newBarang->alamatPengirim));
    cout << "Kode Pos       : "; cin.getline(newBarang->kodeposPengirim, sizeof(newBarang->kodeposPengirim));
    cout << endl;
    cout << "==================================================" << endl;
    cout << "                  Data Penerima                   " << endl;
    cout << "==================================================" << endl;
    cout << "Nama Penerima  : "; cin.getline(newBarang->penerima, sizeof(newBarang->penerima));
    cout << "Nomor Telepon  : "; cin.getline(newBarang->noPenerima, sizeof(newBarang->noPenerima));
    cout << "Alamat         : "; cin.getline(newBarang->alamatPenerima, sizeof(newBarang->alamatPenerima));
    cout << "Kode Pos       : "; cin.getline(newBarang->kodeposPenerima, sizeof(newBarang->kodeposPenerima));
    cout << endl;
    cout << "==================================================" << endl;
    cout << "                Informasi Barang                  " << endl;
    cout << "==================================================" << endl;
    cout << "Nama Barang        : "; cin.getline(newBarang->jenisBarang, sizeof(newBarang->jenisBarang));
    cout << "Berat Barang (kg)  : "; cin >> newBarang->berat;
    cout << "Volume Barang        " << endl;
    cout << "Panjang (cm)       : "; cin >> newBarang->p;
    cout << "Lebar (cm)         : "; cin >> newBarang->l;
    cout << "Tinggi (cm)        : "; cin >> newBarang->t;
    newBarang->rumus = (newBarang->p*newBarang->l*newBarang->t)/6000;
    if(newBarang->rumus >= newBarang->berat){
        newBarang->berat = newBarang->rumus;
    }

    do{
        cout << "Pengiriman luar/dalam pulau Jawa? : "; cin >> newBarang->pulau;
        if (strcmp(strlwr(newBarang->pulau), "luar") != 0 && strcmp(strlwr(newBarang->pulau), "dalam") != 0){
            cout << "Masukkan pilihan luar/dalam!!" << endl;
        }
    }
    while(strcmp(strlwr(newBarang->pulau), "luar") != 0 && strcmp(strlwr(newBarang->pulau), "dalam") != 0);

    do{
        cout << "Jarak Pengiriman (dalam km) : "; cin >> newBarang->jarak;
        if(newBarang->jarak > 2000){
            cout << "Masukkan jarak maksimal 2000!" << endl;
        }
    }
    while(newBarang->jarak > 2000);
    system("cls");
                cout << "Pilih Ekspedisi" << endl;
                cout << "-------------------" << endl;
                cout << "1. J&T Express     " << endl;
                cout << "2. Ninja Express   " << endl;
                cout << "3. Wahana Logistik " << endl;
                cout << "4. Instant         " << endl;
                cout << "-------------------" << endl;
                cout << "Masukkan pilihan: "; cin >> pil;
                system("cls");
                switch(pil){
                    case 1:
                        cout << "J&T Express" << endl;
                        biayaJTExpress(newBarang);
                        system("PAUSE");
                        system("cls");
                        break;
                    case 2:
                        cout << "Ninja Express" << endl;
                        biayaNinjaExpress(newBarang);
                        system("PAUSE");
                        system("cls");
                        break;
                    case 3:
                        cout << "Wahana Logistik" << endl;
                        biayaWahanaLogistik(newBarang);
                        system("PAUSE");
                        system("cls");
                        break;
                    case 4:
                        cout << "Gosend" << endl;
                        biayaGosend(newBarang);
                        system("PAUSE");
                        system("cls");
                        break;
                    default:
                        cout << "Pilihan tidak tersedia. Silahkan masukkan angka yang tersedia." << endl;
                        system("PAUSE");
                        system("cls");
                        return;
                }

}

void cekHarga(User* currentUser, Ekspedisi* ekspedisiList){
    double a;
    char ceklagi;
    Barang* newBarang = new Barang;
    do{
        cout << "=====================================" << endl;
        cout << "              Cek Biaya              " << endl;
        cout << "=====================================" << endl;
        cout << "Berat Barang (kg)  : "; cin >> newBarang->berat;
        cout << "Volume Barang        " << endl;
        cout << "Panjang (cm)       : "; cin >> newBarang->p;
        cout << "Lebar (cm)         : "; cin >> newBarang->l;
        cout << "Tinggi (cm)        : "; cin >> newBarang->t;
        newBarang->rumus = (newBarang->p*newBarang->l*newBarang->t)/6000;
        if(newBarang->rumus >= newBarang->berat){
            newBarang->berat = newBarang->rumus;
        }
        do{
            cout << "Pengiriman luar/dalam Jawa? : "; cin >> newBarang->pulau;
            if (strcmp(strlwr(newBarang->pulau), "luar") != 0 && strcmp(strlwr(newBarang->pulau), "dalam") != 0){
                cout << "Pilihan tidak sesuai!" << endl;
                cout << "Pengiriman luar/dalam Jawa? : " << endl;
            }
        }
        while(strcmp(strlwr(newBarang->pulau), "luar") != 0 && strcmp(strlwr(newBarang->pulau), "dalam") != 0);
            cout << "Jarak Pengiriman (dalam km) : "; cin >> newBarang->jarak;
        cout << "=====================================" << endl;
        tampilanHarga(currentUser, ekspedisiList, newBarang);
        cout << "\nIngin mengecek biaya pengiriman lagi? (Y/T): "; cin >> ceklagi;
        system("cls");
    }
    while(ceklagi != 'T' && ceklagi != 't');
        displayMenuUser(currentUser, ekspedisiList);
}
void saveToEkspedisiFile(const string& Ekspedisi, const string& noResi) {
    ofstream file("Ekspedisi.txt", ios::app);

    if (file.is_open()) {
        file << "Ekspedisi: " << Ekspedisi << endl;
        file << "No Resi: " << noResi << endl;
        file << "----------------------------------------" << endl;
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void saveToBarangFile(const Barang& newBarang, const string& noResi, const string& pilihEkspedisi) {
    ofstream file("Barang.txt", ios::app);

    if (file.is_open()) {
        file << "No Resi: " << noResi << endl;
        file << "Ekspedisi: " << pilihEkspedisi << endl;
        file << "No Resi: " << noResi << endl;
        file << "Status: Menunggu Pengiriman" << endl;
        file << "\nData Pengirim" << endl;
        file << "Nama Pengirim: " << newBarang.pengirim << endl;
        file << "Telepon Pengirim: " << newBarang.noPengirim << endl;
        file << "Alamat Pengirim: " << newBarang.alamatPengirim << endl;
        file << "Kode Pos Pengirim: " << newBarang.kodeposPengirim << endl;
        file << "\nData Penerima" << endl;
        file << "Nama Penerima: " << newBarang.penerima << endl;
        file << "Telepon Penerima: " << newBarang.noPenerima << endl;
        file << "Alamat Penerima: " << newBarang.alamatPenerima << endl;
        file << "Kode Pos Penerima: " << newBarang.kodeposPenerima << endl;
        file << "\nData Barang" << endl;
        file << "Nama Barang: " << newBarang.jenisBarang << endl;
        file << "Berat Barang: " << newBarang.berat << "kg" << endl;
        file << "\nVolume Barang" << endl;
        file << "Panjang Barang: " << newBarang.p << endl;
        file << "Lebar Barang: " << newBarang.l << endl;
        file << "Tinggi Barang: " << newBarang.t << endl;
        file << "Jarak Pengiriman: " << newBarang.jarak << " km" << endl;
        file << "Lokasi: " << newBarang.pulau << " Jawa" << endl;
        file << "Metode Pembayaran: " << newBarang.metodePembayaran << endl;
        file << "----------------------------------------" << endl;

        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}
void biayaJTExpress(Barang* newBarang){
    int pil;
    int biaya1 = 0; int biaya2 = 0; int biaya3 = 0; int biaya4 = 0;
    int biaya5 = 0; int biaya6 = 0; int biaya7 = 0; int biaya8 = 0;

    if (strcmp(strlwr(newBarang->pulau), "dalam") == 0) {
        if (newBarang->berat < 10){
            if (newBarang->jarak <= 200){
                biaya1 = (15000 + 40 * (newBarang->jarak - 50))*newBarang->berat;
                biaya2 = (11000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (8000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Same Day   Rp" << biaya1 << endl;
                cout << "              Akan diterima pada tanggal "; waktu(0,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "2. Next Day   Rp" << biaya2 << endl;
                cout << "              Akan diterima pada tanggal "; waktu(1,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "3. Reguler    Rp" << biaya3 << endl;
                cout << "              Akan diterima pada tanggal "; waktu(2,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){
                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya1 << endl;
                            noRek();
                            break;
                        case 2:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya2 << endl;
                            noRek();
                            break;
                        case 3:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya3 << endl;
                            noRek();
                            break;
                        default:
                            break;
                    }
                    cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                    cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                    cout << "Pembayaran kamu berhasil! Silahkan mengirimkan barang ke ekspedisi" << endl;
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                    system("PAUSE");
                    system("cls");
                    return;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya1 << endl;
                            break;
                        case 2:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya2 << endl;
                            break;
                        case 3:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya3 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if (newBarang->jarak > 200 && newBarang->jarak <= 400){
                biaya2 = (11000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (8000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Next Day   Rp" << biaya2 << endl;
                cout << "              Akan diterima pada tanggal "; waktu(1,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "2. Reguler    Rp" << biaya3 << endl;
                cout << "              Akan diterima pada tanggal "; waktu(2,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya2 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        case 2:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya3 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya2 << endl;
                            break;
                        case 2:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya3 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
                }
            else if (newBarang->jarak > 400 && newBarang->jarak <= 2000){
                biaya3 = (8000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Reguler    Rp" << biaya3 << endl;
                cout << "              Akan diterima pada tanggal "; waktu(2,1);
                cout << "--------------------------------------------------------------" << endl;
                 cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya3 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya3 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
                }
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya4 = 50000 + ((newBarang->berat - 10) * 5000);
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo      Rp" << biaya4 << endl;
                cout << "              Akan diterima pada tanggal "; waktu(3,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya4 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)
                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya4 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if(newBarang->jarak > 50){
                biaya4 = 50000 + ((newBarang->berat - 10) * 5000) + (100 * (newBarang->jarak - 50));
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo      Rp" << biaya4 << endl;
                cout << "              Akan diterima pada tanggal "; waktu(3,2);
                cout << "--------------------------------------------------------------" << endl;
                 cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya4 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya4 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
    }
    else if (strcmp(strlwr(newBarang->pulau), "luar") == 0){
        if (newBarang->berat < 10){
            if (newBarang->jarak <= 250){
                biaya6 = (50000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya7 = (40000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Next Day    Rp" << biaya6 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(1,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "2. Reguler     Rp" << biaya7 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(2,2);
                cout << "--------------------------------------------------------------" << endl;
                 cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya6 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        case 2:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya7 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya6 << endl;
                            break;
                        case 2:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya7 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if (newBarang->jarak > 250 && newBarang->jarak <= 2000){
                biaya7 = (40000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Reguler     Rp" << biaya7 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(2,2);
                cout << "--------------------------------------------------------------" << endl;
                 cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya7 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya7 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya8 = 150000 + ((newBarang->berat - 10) * 15000);
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo       Rp" << biaya8 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(4,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya8 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya8 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if(newBarang->jarak > 50){
                biaya8 = 150000 + ((newBarang->berat - 10) * 15000) + (100 * (newBarang->jarak - 50));
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo       Rp" << biaya8 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(4,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya8 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya8 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiJNT = noResi(12, "JNT");
                    cout << "No Resi: " << noResiJNT << "\n";
                    saveToBarangFile(*newBarang, noResiJNT, "J&T Express");
                    saveToEkspedisiFile("J&T Express", noResiJNT);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
    }
}

void biayaNinjaExpress(Barang* newBarang){
    int pil;
    int biaya1 = 0; int biaya2 = 0; int biaya3 = 0; int biaya4 = 0;
    int biaya5 = 0; int biaya6 = 0; int biaya7 = 0; int biaya8 = 0;

    if (strcmp(strlwr(newBarang->pulau), "dalam") == 0) {
        if (newBarang->berat < 10){
            if (newBarang->jarak <= 200){
                biaya1 = (14000 + 40 * (newBarang->jarak - 50))*newBarang->berat;
                biaya2 = (10000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (7000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Same Day    Rp" << biaya1 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(0,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "2. Next Day    Rp" << biaya2 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(1,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "3. Reguler     Rp" << biaya3 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(2,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya1 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        case 2:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya2 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        case 3:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya3 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya1 << endl;
                            break;
                        case 2:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya2 << endl;
                            break;
                        case 3:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya3 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if (newBarang->jarak > 200 && newBarang->jarak <= 400){
                biaya2 = (10000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (7000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Next Day    Rp" << biaya2 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(1,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "2. Reguler     Rp" << biaya3 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(2,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya2 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        case 2:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya3 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya2 << endl;
                            break;
                        case 2:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya3 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if (newBarang->jarak > 400 && newBarang->jarak <= 2000){
                biaya3 = (7000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Reguler     Rp" << biaya3 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(2,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya3 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya3 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya4 = 40000 + ((newBarang->berat - 10) * 4000);
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Reguler     Rp" << biaya4 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(3,3);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya4 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya4 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if(newBarang->jarak > 50){
                biaya4 = 40000 + ((newBarang->berat - 10) * 4000) + (100 * (newBarang->jarak - 50));
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Reguler     Rp" << biaya4 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(3,3);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya4 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya4 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
    }
    else if (strcmp(strlwr(newBarang->pulau), "luar") == 0){
        if (newBarang->berat < 10 && newBarang->jarak <= 2000){
                biaya7 = (30000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Reguler     Rp" << biaya7 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(3,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya7 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya7 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya8 = 130000 + ((newBarang->berat - 10) * 13000);
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo       Rp" << biaya8 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(4,3);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya8 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya8 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if(newBarang->jarak > 50){
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo       Rp" << biaya8 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(4,3);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya8 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya8 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiNinja = noResi(12, "NINJA");
                    cout << "No Resi: " << noResiNinja << "\n";
                    saveToBarangFile(*newBarang, noResiNinja, "Ninja Express");
                    saveToEkspedisiFile("Ninja Express", noResiNinja);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
    }
}

void biayaWahanaLogistik(Barang* newBarang){
    int pil;
    int biaya1 = 0; int biaya2 = 0; int biaya3 = 0; int biaya4 = 0;
    int biaya5 = 0; int biaya6 = 0; int biaya7 = 0; int biaya8 = 0;

    if (strcmp(strlwr(newBarang->pulau), "dalam") == 0) {
        if (newBarang->berat < 10){
            if (newBarang->jarak <= 400){
                biaya2 = (9000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (5000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Next Day    Rp" << biaya2 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(1,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "2. Reguler     Rp" << biaya3 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(3,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya2 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        case 2:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya3 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya2 << endl;
                            break;
                        case 2:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya3 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if (newBarang->jarak > 400 && newBarang->jarak <= 2000){
                biaya3 = (5000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Reguler     Rp" << biaya3 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(3,1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya3 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya3 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya4 = 30000 + ((newBarang->berat - 10) * 3000);
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo       Rp" << biaya4 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(5,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya4 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya4 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if(newBarang->jarak > 50){
                biaya4 = 30000 + ((newBarang->berat - 10) * 3000) + (100 * (newBarang->jarak - 50));
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo       Rp" << biaya4 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(5,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya4 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya4 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
    }
    else if (strcmp(strlwr(newBarang->pulau), "luar") == 0){
        if (newBarang->berat < 10 && newBarang->jarak <= 2000){
            biaya7 = (20000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Reguler     Rp" << biaya7 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(4,2);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya7 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya7 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
           if(newBarang->jarak <= 50){
                biaya8 = 110000 + ((newBarang->berat - 10) * 11000);
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo       Rp" << biaya8 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(6,4);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya8 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya8 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if(newBarang->jarak > 50){
                biaya8 = 110000 + ((newBarang->berat - 10) * 11000) + (100 * (newBarang->jarak - 50));
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Kargo       Rp" << biaya8 << endl;
                cout << "               Akan diterima pada tanggal "; waktu(6,4);
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya8 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya8 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiWahana = noResi(12, "WAHANA");
                    cout << "No Resi: " << noResiWahana << "\n";
                    saveToBarangFile(*newBarang, noResiWahana, "Wahana Express");
                    saveToEkspedisiFile("Wahana Express", noResiWahana);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
    }
}

void biayaGosend(Barang* newBarang){
    int pil;
    int biaya1 = 0;

    if (strcmp(strlwr(newBarang->pulau), "dalam") == 0){
        if (newBarang->berat <= 20){
            if (newBarang->jarak >= 1 && newBarang->jarak < 16){
                biaya1 = 10000 + 2000 * (newBarang->jarak - 1);
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Gosend      Rp" << biaya1 << endl;
                cout << "               Estimasi barang akan sampai kurang dari 1 jam" << endl;
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya1 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiGosend = noResi(12, "GOSEND");
                    cout << "No Resi: " << noResiGosend << "\n";
                    saveToBarangFile(*newBarang, noResiGosend, "Gosend Instan");
                    saveToEkspedisiFile("Gosend Instan", noResiGosend);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya1 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiGosend = noResi(12, "GOSEND");
                    cout << "No Resi: " << noResiGosend << "\n";
                    saveToBarangFile(*newBarang, noResiGosend, "Gosend Instan");
                    saveToEkspedisiFile("Gosend Instan", noResiGosend);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if (newBarang->jarak >= 16 && newBarang->jarak < 25){
                biaya1 = 10000 + (2000 * 14) + (2500 * (newBarang->jarak - 15));
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Gosend      Rp" << biaya1 << endl;
                cout << "               Estimasi barang akan sampai kurang dari 2 jam" << endl;
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya1 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiGosend = noResi(12, "GOSEND");
                    cout << "No Resi: " << noResiGosend << "\n";
                    saveToBarangFile(*newBarang, noResiGosend, "Gosend Instan");
                    saveToEkspedisiFile("Gosend Instan", noResiGosend);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya1 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiGosend = noResi(12, "GOSEND");
                    cout << "No Resi: " << noResiGosend << "\n";
                    saveToBarangFile(*newBarang, noResiGosend, "Gosend Instan");
                    saveToEkspedisiFile("Gosend Instan", noResiGosend);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
            else if (newBarang->jarak >= 25 && newBarang->jarak <= 50){
                biaya1 = 10000 + (2000 * 14) + (2500 * 10) + (3000 * (newBarang->jarak - 25));
                cout << "--------------------------------------------------------------" << endl;
                cout << "1. Gosend      Rp" << biaya1 << endl;
                cout << "               Estimasi barang akan sampai kurang dari 2 jam" << endl;
                cout << "--------------------------------------------------------------" << endl;
                cout << "Pilih Jenis Pengiriman: "; cin >> pil;
                cout << "Pilih metode pembayaran (cash/transfer): "; cin >> newBarang->metodePembayaran;
                if (strcmp(newBarang->metodePembayaran, "transfer") == 0){




                    switch(pil){
                        case 1:
                            cout << "Lakukan transfer dengan total pembayaran sebesar Rp" << biaya1 << endl;
                            system("PAUSE");
                            system("cls");
                            break;
                        default:
                            break;
                    }

                    string noResiGosend = noResi(12, "GOSEND");
                    cout << "No Resi: " << noResiGosend << "\n";
                    saveToBarangFile(*newBarang, noResiGosend, "Gosend Instan");
                    saveToEkspedisiFile("Gosend Instan", noResiGosend);
                    system("PAUSE");
                    system("cls");
                    return;
                    for (int i = 100; ; i = i + 50)

                        cout << "Transfer menuju bank: "; cin >> newBarang->bank;
                        cout << "Masukkan nomor referensi/transaksi pembayaran yang tertera dalam bukti transfer: "; cin >> newBarang->noReferensi;
                }
                else if (strcmp(newBarang->metodePembayaran, "cash") == 0){
                    switch(pil){
                        case 1:
                            cout << "Jumlah yang harus di bayar pada saat memberikan barang ke ekspedisi adalah sebesar Rp" << biaya1 << endl;
                            break;
                        default:
                            break;
                    }
                    string noResiGosend = noResi(12, "GOSEND");
                    cout << "No Resi: " << noResiGosend << "\n";
                    saveToBarangFile(*newBarang, noResiGosend, "Gosend Instan");
                    saveToEkspedisiFile("Gosend Instan", noResiGosend);
                }
                else if (strcmp(newBarang->metodePembayaran, "transfer") != 0){
                    return;
                }
            }
        }
    }
}

void hitungBiayaJTExpress(Barang* newBarang){
    int biaya1 = 0; int biaya2 = 0; int biaya3 = 0; int biaya4 = 0;
    int biaya5 = 0; int biaya6 = 0; int biaya7 = 0; int biaya8 = 0;

    if (strcmp(strlwr(newBarang->pulau), "dalam") == 0) {
        if (newBarang->berat < 10){
            if (newBarang->jarak <= 200){
                biaya1 = (15000 + 40 * (newBarang->jarak - 50))*newBarang->berat;
                biaya2 = (11000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (8000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "|  J&T Express  | Rp" << setw(8) << biaya1 <<  " | 0-1 hari | Rp" << setw(8) << biaya2 << " | 1-2 hari | Rp" << setw(8) << biaya3 << " | 2-3 hari | Rp" << setw(8) << biaya4 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if (newBarang->jarak > 200 && newBarang->jarak <= 400){
                biaya2 = (11000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (8000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "|  J&T Express  | Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " | 1-2 hari | Rp" << setw(8) << biaya3 << " | 2-3 hari | Rp" << setw(8) << biaya4 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if (newBarang->jarak > 400 && newBarang->jarak <= 2000){
                biaya3 = (8000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "|  J&T Express  | Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " |         0| Rp" << setw(8) << biaya3 << " | 2-3 hari | Rp" << setw(8) << biaya4 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya4 = 50000 + ((newBarang->berat - 10) * 5000);
                cout << "|  J&T Express  | Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " |         0| Rp" << setw(8) << biaya3 << " |         0| Rp" << setw(8) << biaya4 << " | 3-5 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if(newBarang->jarak > 50){
                biaya4 = 50000 + ((newBarang->berat - 10) * 5000) + (100 * (newBarang->jarak - 50));
                cout << "|  J&T Express  | Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " |         0| Rp" << setw(8) << biaya3 << " |         0| Rp" << setw(8) << biaya4 << " | 3-5 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }
    else if (strcmp(strlwr(newBarang->pulau), "luar") == 0){
        if (newBarang->berat < 10){
            if (newBarang->jarak <= 250){
                biaya6 = (50000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya7 = (40000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "|  J&T Express  | Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " | 1-3 hari | Rp" << setw(8) << biaya7 << " | 2-4 hari | Rp" << setw(8) << biaya8 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if (newBarang->jarak > 250 && newBarang->jarak <= 2000){
                biaya7 = (40000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "|  J&T Express  | Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " |         0| Rp" << setw(8) << biaya7 << " | 2-4 hari | Rp" << setw(8) << biaya8 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya8 = 150000 + ((newBarang->berat - 10) * 15000);
                cout << "|  J&T Express  | Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " |         0| Rp" << setw(8) << biaya7 << " |         0| Rp" << setw(8) << biaya8 << " | 4-6 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if(newBarang->jarak > 50){
                biaya8 = 150000 + ((newBarang->berat - 10) * 15000) + (100 * (newBarang->jarak - 50));
                cout << "|  J&T Express  | Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " |         0| Rp" << setw(8) << biaya7 << " |         0| Rp" << setw(8) << biaya8 << " | 4-6 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }
}

void hitungBiayaNinjaExpress(Barang* newBarang){
    int biaya1 = 0; int biaya2 = 0; int biaya3 = 0; int biaya4 = 0;
    int biaya5 = 0; int biaya6 = 0; int biaya7 = 0; int biaya8 = 0;

    if (strcmp(strlwr(newBarang->pulau), "dalam") == 0) {
        if (newBarang->berat < 10){
            if (newBarang->jarak <= 200){
                biaya1 = (14000 + 40 * (newBarang->jarak - 50))*newBarang->berat;
                biaya2 = (10000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (7000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "| Ninja Express | Rp" << setw(8) << biaya1 <<  " | 0-1 hari | Rp" << setw(8) << biaya2 << " | 1-2 hari | Rp" << setw(8) << biaya3 << " | 2-4 hari | Rp" << setw(8) << biaya4 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if (newBarang->jarak > 200 && newBarang->jarak <= 400){
                biaya2 = (10000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (7000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "| Ninja Express | Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " | 1-2 hari | Rp" << setw(8) << biaya3 << " | 2-4 hari | Rp" << setw(8) << biaya4 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if (newBarang->jarak > 400 && newBarang->jarak <= 2000){
                biaya3 = (7000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "| Ninja Express | Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " |         0| Rp" << setw(8) << biaya3 << " | 2-4 hari | Rp" << setw(8) << biaya4 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya4 = 40000 + ((newBarang->berat - 10) * 4000);
                cout << "| Ninja Express | Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " |         0| Rp" << setw(8) << biaya3 << " |         0| Rp" << setw(8) << biaya4 << " | 3-6 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if(newBarang->jarak > 50){
                biaya4 = 40000 + ((newBarang->berat - 10) * 4000) + (100 * (newBarang->jarak - 50));
                cout << "| Ninja Express | Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " |         0| Rp" << setw(8) << biaya3 << " |         0| Rp" << setw(8) << biaya4 << " | 3-6 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }
    else if (strcmp(strlwr(newBarang->pulau), "luar") == 0){
        if (newBarang->berat < 10 && newBarang->jarak <= 2000){
                biaya7 = (30000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "| Ninja Express | Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " |         0| Rp" << setw(8) << biaya7 << " | 3-5 hari | Rp" << setw(8) << biaya8 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya8 = 130000 + ((newBarang->berat - 10) * 13000);
                cout << "| Ninja Express | Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " |         0| Rp" << setw(8) << biaya7 << " |         0| Rp" << setw(8) << biaya8 << " | 4-7 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if(newBarang->jarak > 50){
                biaya8 = 130000 + ((newBarang->berat - 10) * 13000) + (100 * (newBarang->jarak - 50));
                cout << "| Ninja Express | Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " |         0| Rp" << setw(8) << biaya7 << " |         0| Rp" << setw(8) << biaya8 << " | 4-7 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }
}

void hitungBiayaWahanaLogistik(Barang* newBarang){
    int biaya1 = 0; int biaya2 = 0; int biaya3 = 0; int biaya4 = 0;
    int biaya5 = 0; int biaya6 = 0; int biaya7 = 0; int biaya8 = 0;

    if (strcmp(strlwr(newBarang->pulau), "dalam") == 0) {
        if (newBarang->berat < 10){
            if (newBarang->jarak <= 400){
                biaya2 = (9000 + 30 * (newBarang->jarak - 50))*newBarang->berat;
                biaya3 = (5000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "|Wahana Logistik| Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " | 1-3 hari | Rp" << setw(8) << biaya3 << " | 3-4 hari | Rp" << setw(8) << biaya4 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if (newBarang->jarak > 400 && newBarang->jarak <= 2000){
                biaya3 = (5000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
                cout << "|Wahana Logistik| Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " |         0| Rp" << setw(8) << biaya3 << " | 3-4 hari | Rp" << setw(8) << biaya4 << " |         0| Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
            if(newBarang->jarak <= 50){
                biaya4 = 30000 + ((newBarang->berat - 10) * 3000);
                cout << "|Wahana Logistik| Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " |         0| Rp" << setw(8) << biaya3 << " |         0| Rp" << setw(8) << biaya4 << " | 5-7 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if(newBarang->jarak > 50){
                biaya4 = 30000 + ((newBarang->berat - 10) * 3000) + (100 * (newBarang->jarak - 50));
                cout << "|Wahana Logistik| Rp" << setw(8) << biaya1 <<  " |         0| Rp" << setw(8) << biaya2 << " |         0| Rp" << setw(8) << biaya3 << " |         0| Rp" << setw(8) << biaya4 << " | 5-7 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }
    else if (strcmp(strlwr(newBarang->pulau), "luar") == 0){
        if (newBarang->berat < 10 && newBarang->jarak <= 2000){
            biaya7 = (20000 + 20 * (newBarang->jarak - 50))*newBarang->berat;
            cout << "|Wahana Logistik| Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " |         0| Rp" << setw(8) << biaya7 << " | 4-6 hari | Rp" << setw(8) << biaya8 << " |         0| Rp       0 |         0|" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        else if (newBarang->berat >= 10 && newBarang->berat <= 100 && newBarang->jarak <= 2000){
           if(newBarang->jarak <= 50){
                biaya8 = 110000 + ((newBarang->berat - 10) * 11000);
                cout << "|Wahana Logistik| Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " |         0| Rp" << setw(8) << biaya7 << " |         0| Rp" << setw(8) << biaya8 << " |6-10 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if(newBarang->jarak > 50){
                biaya8 = 110000 + ((newBarang->berat - 10) * 11000) + (100 * (newBarang->jarak - 50));
                cout << "|Wahana Logistik| Rp" << setw(8) << biaya5 <<  " |         0| Rp" << setw(8) << biaya6 << " |         0| Rp" << setw(8) << biaya7 << " |         0| Rp" << setw(8) << biaya8 << " |6-10 hari | Rp       0 |         0|" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }
}

void hitungBiayaGosend(Barang* newBarang){
    int biaya1 = 0;

    if (strcmp(strlwr(newBarang->pulau), "dalam") == 0){
        if (newBarang->berat <= 20){
            if (newBarang->jarak >= 1 && newBarang->jarak < 16){
                biaya1 = 10000 + 2000 * (newBarang->jarak - 1);
                cout << "|    Gosend     | Rp       0 |         0| Rp       0 |         0| Rp       0 |         0| Rp       0 |         0| Rp"  << setw(8) << biaya1 << " | < 1 jam  |" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if (newBarang->jarak >= 16 && newBarang->jarak < 25){
                biaya1 = 10000 + (2000 * 14) + (2500 * (newBarang->jarak - 15));
                cout << "|    Gosend     | Rp       0 |         0| Rp       0 |         0| Rp       0 |         0| Rp       0 |         0| Rp"  << setw(8) << biaya1 << " | < 2 jam  |" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if (newBarang->jarak >= 25 && newBarang->jarak <= 50){
                biaya1 = 10000 + (2000 * 14) + (2500 * 10) + (3000 * (newBarang->jarak - 25));
                cout << "|    Gosend     | Rp       0 |         0| Rp       0 |         0| Rp       0 |         0| Rp       0 |         0| Rp"  << setw(8) << biaya1 << " | < 2 jam  |" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }
}

void tampilanHarga(User* currentUser, Ekspedisi* ekspedisiList, Barang* newBarang){
    if(newBarang->jarak <= 2000){
        cout << "\n                                              BIAYA KIRIM TIAP EKSPEDISI DAN JENIS LAYANAN                                             " << endl;
        cout << "                -------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "                |       Same Day        |       Next Day        |        Reguler        |         Kargo         |        Instant        |" << endl;
        cout << "                -------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "                |   Biaya    | Estimasi |   Biaya    | Estimasi |   Biaya    | Estimasi |   Biaya    | Estimasi |   Biaya    | Estimasi |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        hitungBiayaJTExpress(newBarang);
        hitungBiayaNinjaExpress(newBarang);
        hitungBiayaWahanaLogistik(newBarang);
        hitungBiayaGosend(newBarang);
        cout << "0 = Jasa pengiriman tidak tersedia" << endl;
    }
    else{
        system("cls");
        cout << "Masukkan jarak maksimal 2.000 km!" << endl << endl;
        cekHarga(currentUser, ekspedisiList);
    }
}

void tampilkanSemuaBarang(const string& namaFile, const string& namaEkspedisi) {
    ifstream fileBarang(namaFile);

    if (!fileBarang.is_open()) {
        cerr << "Gagal membuka file: " << namaFile << endl;
        return;
    }
    string baris;
    bool isBarangSesuai = false;

    while (getline(fileBarang, baris)) {
        if (baris.find("Ekspedisi: ") != string::npos) {
            size_t pos = baris.find("Ekspedisi: ") + 11;
            string ekspedisiDitemukan = baris.substr(pos);
            ekspedisiDitemukan.erase(ekspedisiDitemukan.find_last_not_of(" \n\r\t")+1);

            if (ekspedisiDitemukan == namaEkspedisi) {
                isBarangSesuai = true;
            } else {
                isBarangSesuai = false;
            }
        }
        if (isBarangSesuai) {
            cout << baris << endl;
        } else if (baris.find("No Resi: ") != string::npos) {
            isBarangSesuai = false;
        }
    }

    fileBarang.close();
}

void updateStatusBarang(const string& namaFile, const string& namaEkspedisi) {
    ifstream fileBarang(namaFile);

    if (!fileBarang.is_open()) {
        cerr << "Gagal membuka file: " << namaFile << endl;
        return;
    }

    string nomorResi;
    cout << "Masukkan Resi yang ingin diupdate: ";
    cin >> nomorResi;

    string baris;
    bool ditemukan = false;
    bool isAdminEkspedisi = false;
    ofstream fileBarangBaru("BarangBaru.txt");  // File sementara untuk menyimpan perubahan

    while (getline(fileBarang, baris)) {
        // Salin baris langsung ke file sementara
        fileBarangBaru << baris << endl;

        // Jika menemukan baris "No Resi:" yang sesuai, baca baris berikutnya
        if (baris.find("No Resi: " + nomorResi) != string::npos) {
            // Baca dan salin baris Ekspedisi
            getline(fileBarang, baris);
            fileBarangBaru << baris << endl;

            // Cek apakah admin pengiriman untuk Ekspedisi ini
            if (baris.find("Ekspedisi: " + namaEkspedisi) != string::npos) {
                isAdminEkspedisi = true;

                // Baca baris Status dan ganti nilainya
                getline(fileBarang, baris);
                cout << "Masukkan Status Pengantaran baru: ";
                string statusPengantaran;
                cin.ignore();  // Membersihkan buffer agar getline berfungsi dengan benar setelah cin
                getline(cin, statusPengantaran);

                fileBarangBaru << "Status: " << statusPengantaran << endl;
                ditemukan = true;
            }
        }
    }

    fileBarang.close();
    fileBarangBaru.close();

    if (isAdminEkspedisi) {
        if (ditemukan) {
            // Hapus file lama
            remove(namaFile.c_str());

            // Ganti file lama dengan file sementara yang sudah diperbarui
            rename("BarangBaru.txt", namaFile.c_str());

            cout << "Status pengiriman barang dengan nomor resi " << nomorResi << " telah diperbarui." << endl;
        } else {
            // Hapus file sementara yang tidak terpakai
            remove("BarangBaru.txt");

            cout << "Barang dengan nomor resi " << nomorResi << " tidak ditemukan." << endl;
        }
    } else {
        cout << "Anda bukan admin pengiriman untuk Ekspedisi ini." << endl;
    }
}

void antarSemuaBarang(const string& namaFile, const string& namaEkspedisi) {
    ifstream fileBarang(namaFile);
    ofstream fileBarangBaru("BarangBaru.txt");
    if (!fileBarang.is_open()) {
        cerr << "Gagal membuka file: " << namaFile << endl;
        return;
    }
    if (!fileBarangBaru.is_open()) {
        cerr << "Gagal membuat file baru untuk menyimpan pembaruan." << endl;
        return;
    }
    string baris;
    bool updateStatus = false;
    bool ekspedisiSesuai = false;

    while (getline(fileBarang, baris)) {
        if (baris.find("Ekspedisi: ") != string::npos) {
            size_t pos = baris.find("Ekspedisi: ") + 11;
            string ekspedisiDitemukan = baris.substr(pos);
            ekspedisiDitemukan.erase(ekspedisiDitemukan.find_last_not_of(" \n\r\t")+1);
            ekspedisiSesuai = (ekspedisiDitemukan == namaEkspedisi);
        }

        if (ekspedisiSesuai && baris.find("Status:") != string::npos) {
            fileBarangBaru << "Status: Paket sedang diantar" << endl;
            updateStatus = true;
        }
        else {
            fileBarangBaru << baris << endl;
        }
    }

    fileBarang.close();
    fileBarangBaru.close();

    if (updateStatus) {
        remove(namaFile.c_str());
        rename("BarangBaru.txt", namaFile.c_str());

        cout << "Status pengiriman telah diperbarui untuk ekspedisi " << namaEkspedisi << "." << endl;
    }
    else {
        remove("BarangBaru.txt");

        cout << "Tidak ada pembaruan pada status pengiriman untuk ekspedisi " << namaEkspedisi << "." << endl;
    }
}

void antarSemuaBarang(Ekspedisi* currentEkspedisi) {
    User* currentUser = currentEkspedisi->daftarUser;

    while (currentUser != nullptr) {
        Barang* currentBarang = currentUser->antrianBarang;

        while (currentBarang != nullptr) {
            if (strcmp(currentBarang->status, "Dalam proses") == 0) {
                cout << "Mengantarkan barang dengan nomor resi " << currentBarang->noResi << "..." << endl;
                strcpy(currentBarang->status, "Dikirim");
            }
            currentBarang = currentBarang->next;
        }
        currentUser = currentUser->next;
    }

    cout << "Semua barang dalam antrian pengiriman telah dikirim." << endl;
}

void cariBarang(const string& namaFile, const string& namaEkspedisi) {
    ifstream fileBarang(namaFile);

    if (!fileBarang.is_open()) {
        cerr << "Gagal membuka file: " << namaFile << endl;
        return;
    }

    string nomorResi;
    cout << "Masukkan nomor resi untuk mencari barang: ";
    cin >> nomorResi;

    string baris;
    bool ditemukan = false;
    bool isAdminEkspedisi = false;

    while (getline(fileBarang, baris)) {
        if (baris.find("No Resi: " + nomorResi) != string::npos) {
            // Baca dan salin baris Ekspedisi
            getline(fileBarang, baris);

            // Cek apakah admin pengiriman untuk Ekspedisi ini
            if (baris.find("Ekspedisi: " + namaEkspedisi) != string::npos) {
                isAdminEkspedisi = true;

                ditemukan = true;
                cout << baris << endl;

                // Tampilkan detail barang sampai batas
                while (getline(fileBarang, baris) && baris != "----------------------------------------") {
                    cout << baris << endl;
                }
                break;
            } else {
                cout << "Anda bukan admin pengiriman untuk Ekspedisi ini." << endl;
                return;
            }
        }
    }

    fileBarang.close();

    if (!ditemukan) {
        cout << "Barang dengan nomor resi tersebut tidak ditemukan." << endl;
    }
}

void statusBarang(const string& namaFile) {
    ifstream fileBarang(namaFile);

    if (!fileBarang.is_open()) {
        cerr << "Gagal membuka file: " << namaFile << endl;
        return;
    }

    string nomorResi;
    cout << "Masukkan nomor resi: ";
    cin >> nomorResi;

    string baris;
    bool ditemukan = false;

    while (getline(fileBarang, baris)) {
        if (baris.find("No Resi: " + nomorResi) != string::npos) {
            ditemukan = true;
            cout << baris << endl;
            while (getline(fileBarang, baris) && baris != "----------------------------------------") {
                cout << baris << endl;
            }
            break;
        }
    }
    fileBarang.close();
    if (!ditemukan) {
        cout << "Barang dengan nomor resi tersebut tidak ditemukan." << endl;
    }
}

void displayMenuUser(User* currentUser, Ekspedisi* ekspedisiList){
    while (true) {
        cout << "========================" << endl;
        cout << "       Menu User        " << endl;
        cout << "========================" << endl;
        cout << "1. Cek Biaya            " << endl;
        cout << "2. Kirim Barang         " << endl;
        cout << "3. Update Barang        " << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "5. Keluar               " << endl;
        cout << "========================" << endl;
        cout << "Pilih menu: "; int choice; cin >> choice;
        system("cls");

        switch (choice){
            case 1:
                cekHarga(currentUser, ekspedisiList);
                break;
            case 2:
                kirimBarang(currentUser, ekspedisiList);
                break;
            case 3:
                statusBarang("Barang.txt");
                system("pause");
                system("cls");
                break;
            case 4:
                return;
            case 5:
                keluar();
                break;
            default:
                cout << "Pilihan tidak valid! Silhkan coba lagi." << endl;
        }
    }
}

void displayMenuAdmin(const string& namaEkspedisi){
    while(true){
        int choice;
        cout << "========================" << endl;
        cout << " Admin " << namaEkspedisi << " " << endl;
        cout << "========================" << endl;
        cout << "1. Tampilkan Antrian    " << endl;
        cout << "2. Antar Semua Barang   " << endl;
        cout << "3. Update Pengiriman    " << endl;
        cout << "4. Cari Barang          " << endl;
        cout << "5. Kembali ke Menu Utama" << endl;
        cout << "6. Keluar               " << endl;
        cout << "========================" << endl;
        cout << "Pilih menu: "; cin >> choice;
        system("cls");

        switch (choice){
            case 1:
                tampilkanSemuaBarang("Barang.txt", namaEkspedisi);
                system("pause");
                system("cls");
                break;
            case 2:
                antarSemuaBarang("Barang.txt", namaEkspedisi);
                system("pause");
                system("cls");
                break;
                return;
            case 3:
                updateStatusBarang("Barang.txt", namaEkspedisi);
                system("pause");
                system("cls");
                break;
                return;
            case 4:
                cariBarang("Barang.txt", namaEkspedisi);
                system("pause");
                system("cls");
                break;
            case 5:
                return;
            case 6:
                keluar();
                return;
            default:
                cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
        }
    }
}
