#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Diperlukan untuk fungsi sort
#include <limits>    // Diperlukan untuk std::numeric_limits

// Menggunakan namespace std untuk menghindari penulisan std:: berulang kali
using namespace std;

// Mendefinisikan struktur untuk data Laptop
struct Laptop {
    string merek;
    string model;
    int harga;
};

// Class untuk mengelola operasi toko komputer
class TokoKomputer {
private:
    vector<Laptop> daftarLaptop; // Vector untuk menyimpan daftar laptop

public:
    // Konstruktor (sekarang kosong)
    // Data laptop tidak diisi di awal, program dimulai dengan daftar kosong.
    TokoKomputer() {
    }

    // Fungsi untuk menambahkan laptop baru ke dalam daftar
    void tambahLaptop(const string& merek, const string& model, int harga) {
        daftarLaptop.push_back({merek, model, harga});
    }

    // Fungsi untuk menampilkan semua laptop yang ada di daftar
    void tampilkanSemuaLaptop(const string& judul) {
        cout << "\n--- " << judul << " ---\n";
        // Tambahan: Cek apakah vector kosong atau tidak
        if (daftarLaptop.empty()) {
            cout << "Daftar laptop masih kosong. Silakan tambah data baru." << endl;
        } else {
            for (const auto& laptop : daftarLaptop) {
                cout << "Merek: " << laptop.merek
                     << ", Model: " << laptop.model
                     << ", Harga: Rp" << laptop.harga << endl;
            }
        }
        cout << "------------------------------------\n";
    }
    
    // Fungsi untuk menangani proses input laptop baru dari user
    void menuTambahLaptop() {
        string merek, model;
        int harga;

        cout << "\n--- Tambah Laptop Baru ---\n";
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        cout << "Masukkan Merek: ";
        getline(cin, merek); 

        cout << "Masukkan Model: ";
        getline(cin, model);

        cout << "Masukkan Harga (contoh: 15000000): ";
        cin >> harga;

        tambahLaptop(merek, model, harga);
        cout << "\nLaptop baru berhasil ditambahkan!" << endl;
    }

    // Fungsi untuk mengurutkan laptop berdasarkan merek (A-Z)
    void urutkanBerdasarkanMerek() {
        if (daftarLaptop.empty()){
            cout << "\nTidak ada data untuk diurutkan." << endl;
            return;
        }
        sort(daftarLaptop.begin(), daftarLaptop.end(), [](const Laptop& a, const Laptop& b) {
            return a.merek < b.merek;
        });
        tampilkanSemuaLaptop("Daftar Laptop Berdasarkan Merek (A-Z)");
    }

    // Fungsi untuk mengurutkan laptop berdasarkan harga (Termurah ke Tertinggi)
    void urutkanBerdasarkanHargaTermurah() {
        if (daftarLaptop.empty()){
            cout << "\nTidak ada data untuk diurutkan." << endl;
            return;
        }
        sort(daftarLaptop.begin(), daftarLaptop.end(), [](const Laptop& a, const Laptop& b) {
            return a.harga < b.harga;
        });
        tampilkanSemuaLaptop("Daftar Laptop Berdasarkan Harga (Termurah - Termahal)");
    }

    // Fungsi untuk mengurutkan laptop berdasarkan harga (Tertinggi ke Termurah)
    void urutkanBerdasarkanHargaTermahal() {
        if (daftarLaptop.empty()){
            cout << "\nTidak ada data untuk diurutkan." << endl;
            return;
        }
        sort(daftarLaptop.begin(), daftarLaptop.end(), [](const Laptop& a, const Laptop& b) {
            return a.harga > b.harga;
        });
        tampilkanSemuaLaptop("Daftar Laptop Berdasarkan Harga (Termahal - Termurah)");
    }

    // Fungsi untuk menjalankan menu utama program
    void jalankanMenu() {
        int pilihan;
        do {
            cout << "\n===== MENU TOKO KOMPUTER =====\n";
            cout << "1. Tampilkan Semua Laptop\n";
            cout << "2. Tambah Laptop Baru\n";
            cout << "3. Urutkan Berdasarkan Merek (A-Z)\n";
            cout << "4. Urutkan Berdasarkan Harga (Termurah-Termahal)\n";
            cout << "5. Urutkan Berdasarkan Harga (Termahal-Termurah)\n";
            cout << "0. Keluar\n";
            cout << "==============================\n";
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tampilkanSemuaLaptop("Daftar Semua Laptop");
                    break;
                case 2:
                    menuTambahLaptop();
                    break;
                case 3:
                    urutkanBerdasarkanMerek();
                    break;
                case 4:
                    urutkanBerdasarkanHargaTermurah();
                    break;
                case 5:
                    urutkanBerdasarkanHargaTermahal();
                    break;
                case 0:
                    cout << "Terima kasih telah menggunakan program ini!\n";
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            }
        } while (pilihan != 0);
    }
};

int main() {
    TokoKomputer toko;
    toko.jalankanMenu();
    return 0;
}