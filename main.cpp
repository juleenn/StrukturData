#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Deklarasi struct untuk detail barang
struct DetailBarang {
    string namaBarang;
    string jenisBarang;
    double berat;
    string catatan;
};

// Deklarasi struct untuk data diri pengirim dan penerima
struct DataDiri {
    string nama;
    string nomorTelepon;
};

// Deklarasi struct untuk informasi pengiriman paket
struct PengirimanPaket {
    string jenisLokasi;
    vector<string> hargaPengirimanJawa = {"Same day (Rp5000/kg)", "Next day (Rp6000/kg)", "Reguler (Rp7000/kg)", "Cargo (Rp5000/kg)"};
    vector<string> hargaPengirimanLuarJawa = {"Same day (Rp6000/kg)", "Next day (Rp7000/kg)", "Reguler (Rp8000/kg)", "Cargo (Rp5500/kg)"};
};

// Fungsi untuk menampilkan antrian paket yang belum dikirim
void tampilkanAntrianPaket(const vector<string>& antrian) {
    cout << "====================================" << endl;
    cout << "===== ANTRIAN PENGIRIMAN PAKET =====" << endl;
    for (const auto& paket : antrian) {
        cout << paket << endl;
    }
    cout << "====================================" << endl;
}

// Fungsi untuk antar satu barang dari paling atas antrian
void antarkanBarang(vector<string>& antrian) {
    if (!antrian.empty()) {
        cout << "Barang " << antrian.front() << " berhasil diantarkan." << endl;
        antrian.erase(antrian.begin());
    } else {
        cout << "Antrian kosong." << endl;
    }
}

// Fungsi untuk mencari barang berdasarkan nama
void cariBarang(const vector<string>& antrian) {
    string namaBarang;
    cout << "Ketik nama barangnya : ";
    cin.ignore(); // Membersihkan buffer
    getline(cin, namaBarang);

    bool found = false;
    for (const auto& paket : antrian) {
        if (paket.find(namaBarang) != string::npos) {
            cout << "====================================" << endl;
            cout << "========== DETAIL PAKET ==========" << endl;
            cout << paket << endl;
            cout << "==================================" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Barang tidak ditemukan." << endl;
    }
}

// Fungsi untuk mengantar semua barang dalam antrian
void antarSemuaBarang(vector<string>& antrian) {
    if (!antrian.empty()) {
        cout << "Semua barang berhasil diantarkan." << endl;
        antrian.clear();
    } else {
        cout << "Antrian kosong." << endl;
    }
}

// Fungsi untuk menampilkan menu pengguna
void menuPengguna() {
    cout << "================================" << endl;
    cout << "====== PROGRAM ANTAR PAKET =====" << endl;
    cout << "================================" << endl;
    cout << "Menu pengguna :" << endl;
    cout << "1. Cek Harga" << endl;
    cout << "2. Kirim Barang" << endl;
    cout << "3. Kembali" << endl;
    cout << "4. Keluar" << endl;
    cout << "================================" << endl;
}

// Fungsi untuk menampilkan harga pengiriman
void tampilkanHargaPengiriman(PengirimanPaket &paket) {
    // Menampilkan harga pengiriman pulau Jawa
    cout << "==================================" << endl;
    cout << "===== HARGA PENGIRIMAN PAKET =====" << endl;
    cout << "==================================" << endl;
    cout << "Jenis pengiriman :" << endl;
    cout << "Harga pengiriman pulau Jawa : " << endl;
    for (const auto &harga : paket.hargaPengirimanJawa) {
        cout << "- " << harga << endl;
    }
    // Menampilkan harga pengiriman luar pulau Jawa
    cout << "Harga pengiriman luar pulau Jawa : " << endl;
    for (const auto &harga : paket.hargaPengirimanLuarJawa) {
        cout << "- " << harga << endl;
    }
}

// Fungsi untuk memasukkan data diri
void inputDataDiri(DataDiri &dataDiri, const string &role) {
    cout << "Isi data diri " << role << " dibawah." << endl;
    cout << "Masukkan Nama : ";
    getline(cin >> ws, dataDiri.nama);
    cout << "Masukkan Nomor Telepon : ";
    getline(cin >> ws, dataDiri.nomorTelepon);
    cout << "================================" << endl;
}

// Fungsi untuk mengirim barang
void kirimBarang(PengirimanPaket &paket, DataDiri &pengirim, DataDiri &penerima, DetailBarang &detailBarang) {
    inputDataDiri(pengirim, "pengirim");
    inputDataDiri(penerima, "penerima");

    cout << "Pilih lokasi pengantaran (1: Dalam Jawa, 2: Luar Jawa)" << endl;
    cout << "Lokasi (1/2) : ";
    int lokasi;
    cin >> lokasi;

    // Memasukkan detail barang
    cout << "Isi detail barang dibawah." << endl;
    cout << "Nama Barang : ";
    getline(cin >> ws, detailBarang.namaBarang);
    cout << "Jenis Barang : ";
    getline(cin >> ws, detailBarang.jenisBarang);
    cout << "Berat (kg) : ";
    cin >> detailBarang.berat;
    cout << "Catatan : ";
    getline(cin >> ws, detailBarang.catatan);

    // Menampilkan pilihan pengiriman
    if (lokasi == 1) {
        tampilkanHargaPengiriman(paket);
        int pilihan;
        cout << "Pilih jenis pengiriman (1-" << paket.hargaPengirimanJawa.size() << "): ";
        cin >> pilihan;
        
        if (pilihan >= 1 && pilihan <= paket.hargaPengirimanJawa.size()) {
            double hargaPerKg = 0.0;
            switch (pilihan) {
                case 1:
                    hargaPerKg = 5000.0; // Misalnya, atur harga per kilogram untuk pilihan pertama
                    break;
                case 2:
                    hargaPerKg = 6000.0; // Atur harga per kilogram untuk pilihan kedua
                    break;
                case 3:
                    hargaPerKg = 7000.0; // Atur harga per kilogram untuk pilihan ketiga
                    break;
                case 4:
                    hargaPerKg = 5000.0; // Atur harga per kilogram untuk pilihan keempat
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    return;
            }
            
            double totalHarga = detailBarang.berat * hargaPerKg;
            cout << "Total harga: Rp" << totalHarga << endl;
            
            // Lanjutkan dengan proses pengiriman
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    } else if (lokasi == 2) {
        tampilkanHargaPengiriman(paket);
        int pilihan;
        cout << "Pilih jenis pengiriman (1-" << paket.hargaPengirimanJawa.size() << "): ";
        cin >> pilihan;
        
        if (pilihan >= 2 && pilihan <= paket.hargaPengirimanJawa.size()) {
            double hargaPerKg = 0.0;
            switch (pilihan) {
                case 1:
                    hargaPerKg = 5000.0; // Misalnya, atur harga per kilogram untuk pilihan pertama
                    break;
                case 2:
                    hargaPerKg = 6000.0; // Atur harga per kilogram untuk pilihan kedua
                    break;
                case 3:
                    hargaPerKg = 7000.0; // Atur harga per kilogram untuk pilihan ketiga
                    break;
                case 4:
                    hargaPerKg = 5000.0; // Atur harga per kilogram untuk pilihan keempat
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    return;
            }
            
            double totalHarga = detailBarang.berat * hargaPerKg;
            cout << "Total harga: Rp" << totalHarga << endl;
        }
    }
}

void cekHarga(PengirimanPaket &paket) {
    int lokasi;
    cout << "Pilih lokasi pengantaran (1: Dalam Jawa, 2: Luar Jawa)" << endl;
    cout << "Lokasi (1/2) : ";
    cin >> lokasi;

    if (lokasi == 1) {
        tampilkanHargaPengiriman(paket);
    } else if (lokasi == 2) {
        tampilkanHargaPengiriman(paket);
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

// Fungsi utama
int main() {

    PengirimanPaket paket;
    DataDiri pengirim, penerima;
    DetailBarang detailBarang;
    vector<string> antrianPaket;

    int role;
    do {
        cout << "================================" << endl;
        cout << "====== PROGRAM ANTAR PAKET =====" << endl;
        cout << "================================" << endl;
        cout << "Login sebagai" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Pengguna" << endl;
        cout << "================================" << endl;
        cout << "Pilihan: ";
        cin >> role;

        switch (role) {
            case 1: {
            string username, password;
            cout << "Masukkan username : ";
            cin >> username;
            cout << "Masukkan password : ";
            cin >> password;

            if (username == "admin" && password == "admin123") {
                bool selesaiMenuAdmin = false;
                int menuAdmin;
                do {
                    cout << "================================" << endl;
                    cout << "====== PROGRAM ANTAR PAKET =====" << endl;
                    cout << "================================" << endl;
                    cout << "Menu admin :" << endl;
                    cout << "1. Tampilkan Antrian" << endl;
                    cout << "2. Antarkan Barang" << endl;
                    cout << "3. Cari Barang" << endl;
                    cout << "4. Antar Semua Barang" << endl;
                    cout << "5. Kembali" << endl;
                    cout << "Pilihan: ";
                    cin >> menuAdmin;

                    switch (menuAdmin) {
                        case 1:
                            tampilkanAntrianPaket(antrianPaket);
                            break;
                        case 2:
                            antarkanBarang(antrianPaket);
                            break;
                        case 3:
                            cariBarang(antrianPaket);
                            break;
                        case 4:
                            antarSemuaBarang(antrianPaket);
                            break;
                        case 5:
                            selesaiMenuAdmin = true;
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            break;
                    }
                } while (!selesaiMenuAdmin);
            } else {
                cout << "Username atau password salah. Silakan coba lagi." << endl;
            }
            break;
        }
        case 2: {
            int menu;
            do {
                menuPengguna();
                cout << "Pilihan: ";
                cin >> menu;

                switch (menu) {
                    case 1:
                        cekHarga(paket);
                        break;
                    case 2:
                        kirimBarang(paket, pengirim, penerima, detailBarang);
                        break;
                    case 3:
                        break;
                    case 4:
                        cout << "Terima kasih telah menggunakan layanan kami." << endl;
                        return 0;
                    default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            break;
                    }

                    if (menu == 3) {
                        break; // Keluar dari loop menu pengguna
                    }
                } while (true);

                break; // Kembali ke menu login setelah keluar dari loop menu pengguna
            }
        }
    } while (true);

    return 0;
}