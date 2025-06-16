#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <stack> // Untuk struktur data stack

using namespace std;

struct Laptop {
    string merek;
    string model;
    int harga;
};

class TokoKomputer {
private:
    vector<Laptop> daftarLaptop;
    stack<Laptop> stackLaptop; // Stack untuk operasi LIFO

public:
    TokoKomputer() {}

    // Fungsi dasar
    void tambahLaptop(const string& merek, const string& model, int harga) {
        Laptop laptop = {merek, model, harga};
        daftarLaptop.push_back(laptop);
        stackLaptop.push(laptop); // Otomatis ditambahkan ke stack
    }

    // Fungsi untuk menampilkan semua laptop
    void tampilkanSemuaLaptop(const string& judul) {
        cout << "\n--- " << judul << " ---\n";
        if (daftarLaptop.empty()) {
            cout << "Daftar laptop masih kosong." << endl;
        } else {
            for (size_t i = 0; i < daftarLaptop.size(); i++) {
                cout << "[" << i + 1 << "] Merek: " << daftarLaptop[i].merek
                     << ", Model: " << daftarLaptop[i].model
                     << ", Harga: Rp" << daftarLaptop[i].harga << endl;
            }
        }
        cout << "------------------------------------\n";
    }

    // Fungsi untuk input laptop baru
    void menuTambahLaptop() {
        string merek, model;
        int harga;

        cout << "\n--- Tambah Laptop Baru ---\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Masukkan Merek: ";
        getline(cin, merek);

        cout << "Masukkan Model: ";
        getline(cin, model);

        cout << "Masukkan Harga: ";
        cin >> harga;

        tambahLaptop(merek, model, harga);
        cout << "Laptop berhasil ditambahkan!" << endl;
    }

    // Fungsi untuk menambahkan laptop di depan
    void tambahDepan() {
        string merek, model;
        int harga;

        cout << "\n--- Tambah Laptop di Depan ---\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Masukkan Merek: ";
        getline(cin, merek);

        cout << "Masukkan Model: ";
        getline(cin, model);

        cout << "Masukkan Harga: ";
        cin >> harga;

        Laptop laptop = {merek, model, harga};
        daftarLaptop.insert(daftarLaptop.begin(), laptop);
        stackLaptop.push(laptop);
        cout << "Laptop berhasil ditambahkan di depan!" << endl;
    }

    // Fungsi untuk menambahkan laptop di belakang
    void tambahBelakang() {
        string merek, model;
        int harga;

        cout << "\n--- Tambah Laptop di Belakang ---\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Masukkan Merek: ";
        getline(cin, merek);

        cout << "Masukkan Model: ";
        getline(cin, model);

        cout << "Masukkan Harga: ";
        cin >> harga;

        Laptop laptop = {merek, model, harga};
        daftarLaptop.push_back(laptop);
        stackLaptop.push(laptop);
        cout << "Laptop berhasil ditambahkan di belakang!" << endl;
    }

    // Fungsi untuk menambahkan laptop di tengah
    void tambahTengah() {
        if (daftarLaptop.empty()) {
            cout << "\nDaftar kosong, tambahkan di posisi pertama." << endl;
            menuTambahLaptop();
            return;
        }

        string merek, model;
        int harga, posisi;

        cout << "\n--- Tambah Laptop di Tengah ---\n";
        tampilkanSemuaLaptop("Pilih Posisi");

        cout << "Masukkan posisi (1-" << daftarLaptop.size() << "): ";
        cin >> posisi;

        if (posisi < 1 || posisi > daftarLaptop.size()) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan Merek: ";
        getline(cin, merek);

        cout << "Masukkan Model: ";
        getline(cin, model);

        cout << "Masukkan Harga: ";
        cin >> harga;

        Laptop laptop = {merek, model, harga};
        daftarLaptop.insert(daftarLaptop.begin() + posisi - 1, laptop);
        stackLaptop.push(laptop);
        cout << "Laptop berhasil ditambahkan di posisi " << posisi << "!" << endl;
    }

    // Fungsi untuk menghapus laptop di depan
    void hapusDepan() {
        if (daftarLaptop.empty()) {
            cout << "\nDaftar kosong, tidak ada yang dihapus." << endl;
            return;
        }

        cout << "\n--- Hapus Laptop di Depan ---\n";
        cout << "Laptop \"" << daftarLaptop.front().merek << "\" dihapus." << endl;
        daftarLaptop.erase(daftarLaptop.begin());
        
        if (!stackLaptop.empty()) {
            stackLaptop.pop();
        }
    }

    // Fungsi untuk menghapus laptop di belakang
    void hapusBelakang() {
        if (daftarLaptop.empty()) {
            cout << "\nDaftar kosong, tidak ada yang dihapus." << endl;
            return;
        }

        cout << "\n--- Hapus Laptop di Belakang ---\n";
        cout << "Laptop \"" << daftarLaptop.back().merek << "\" dihapus." << endl;
        daftarLaptop.pop_back();
        
        // Stack tidak bisa langsung menghapus elemen belakang, jadi perlu dibersihkan jika diperlukan
        // (Implementasi stack hanya mendukung LIFO, sehingga tidak bisa langsung menghapus belakang)
    }

    // Fungsi untuk menghapus laptop di tengah
    void hapusTengah() {
        if (daftarLaptop.empty()) {
            cout << "\nDaftar kosong, tidak ada yang dihapus." << endl;
            return;
        }

        int posisi;
        cout << "\n--- Hapus Laptop di Tengah ---\n";
        tampilkanSemuaLaptop("Pilih Posisi yang Akan Dihapus");

        cout << "Masukkan posisi (1-" << daftarLaptop.size() << "): ";
        cin >> posisi;

        if (posisi < 1 || posisi > daftarLaptop.size()) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        cout << "Laptop \"" << daftarLaptop[posisi - 1].merek << "\" dihapus." << endl;
        daftarLaptop.erase(daftarLaptop.begin() + posisi - 1);
    }

    // Fungsi untuk mengurutkan laptop
    void urutkanBerdasarkanMerek() {
        if (daftarLaptop.empty()) {
            cout << "\nTidak ada data untuk diurutkan." << endl;
            return;
        }
        sort(daftarLaptop.begin(), daftarLaptop.end(), [](const Laptop& a, const Laptop& b) {
            return a.merek < b.merek;
        });
        tampilkanSemuaLaptop("Daftar Laptop Berdasarkan Merek (A-Z)");
    }

    void urutkanBerdasarkanHargaTermurah() {
        if (daftarLaptop.empty()) {
            cout << "\nTidak ada data untuk diurutkan." << endl;
            return;
        }
        sort(daftarLaptop.begin(), daftarLaptop.end(), [](const Laptop& a, const Laptop& b) {
            return a.harga < b.harga;
        });
        tampilkanSemuaLaptop("Daftar Laptop Berdasarkan Harga (Termurah-Termahal)");
    }

    void urutkanBerdasarkanHargaTermahal() {
        if (daftarLaptop.empty()) {
            cout << "\nTidak ada data untuk diurutkan." << endl;
            return;
        }
        sort(daftarLaptop.begin(), daftarLaptop.end(), [](const Laptop& a, const Laptop& b) {
            return a.harga > b.harga;
        });
        tampilkanSemuaLaptop("Daftar Laptop Berdasarkan Harga (Termahal-Termurah)");
    }

    // Fungsi untuk menampilkan menu utama
    void jalankanMenu() {
        int pilihan;
        do {
            cout << "\n===== MENU TOKO KOMPUTER (STACK) =====";
            cout << "\n1. Tampilkan Semua Laptop";
            cout << "\n2. Tambah Laptop Baru";
            cout << "\n3. Tambah Laptop di Depan";
            cout << "\n4. Tambah Laptop di Belakang";
            cout << "\n5. Tambah Laptop di Tengah";
            cout << "\n6. Hapus Laptop di Depan";
            cout << "\n7. Hapus Laptop di Belakang";
            cout << "\n8. Hapus Laptop di Tengah";
            cout << "\n9. Urutkan Berdasarkan Merek (A-Z)";
            cout << "\n10. Urutkan Berdasarkan Harga (Termurah-Termahal)";
            cout << "\n11. Urutkan Berdasarkan Harga (Termahal-Termurah)";
            cout << "\n12. Keluar";
            cout << "\n======================================";
            cout << "\nMasukkan pilihan Anda: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1: tampilkanSemuaLaptop("Daftar Semua Laptop"); break;
                case 2: menuTambahLaptop(); break;
                case 3: tambahDepan(); break;
                case 4: tambahBelakang(); break;
                case 5: tambahTengah(); break;
                case 6: hapusDepan(); break;
                case 7: hapusBelakang(); break;
                case 8: hapusTengah(); break;
                case 9: urutkanBerdasarkanMerek(); break;
                case 10: urutkanBerdasarkanHargaTermurah(); break;
                case 11: urutkanBerdasarkanHargaTermahal(); break;
                case 12: cout << "Terima kasih!" << endl; break;
                default: cout << "Pilihan tidak valid!" << endl;
            }
        } while (pilihan != 0);
    }
};

int main() {
    TokoKomputer toko;
    toko.jalankanMenu();
    return 0;
}
