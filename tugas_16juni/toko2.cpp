#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struct untuk node barang
struct Barang {
    string kode;
    string nama;
    string kategori;
    int stok;
    double harga;
    Barang* next;
    
    // Constructor
    Barang(string k, string n, string kat, int s, double h) {
        kode = k;
        nama = n;
        kategori = kat;
        stok = s;
        harga = h;
        next = nullptr;
    }
};

class GudangToko {
private:
    Barang* head;
    
    // Method private untuk validasi input
    bool isValidKode(string kode) {
        Barang* temp = head;
        while (temp != nullptr) {
            if (temp->kode == kode) {
                return false; // Kode sudah ada
            }
            temp = temp->next;
        }
        return true; // Kode belum ada
    }
    
    // Method untuk menghitung jumlah node
    int hitungNode() {
        int count = 0;
        Barang* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    // Constructor
    GudangToko() {
        head = nullptr;
    }
    
    // Destructor untuk membersihkan memori
    ~GudangToko() {
        while (head != nullptr) {
            Barang* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // 1. Tambah Data (di belakang)
    void tambahData() {
        string kode, nama, kategori;
        int stok;
        double harga;
        
        cout << "\n=== TAMBAH DATA BARANG ===" << endl;
        cout << "Masukkan Kode Barang: ";
        cin >> kode;
        
        if (!isValidKode(kode)) {
            cout << "Error: Kode barang sudah ada!" << endl;
            return;
        }
        
        cin.ignore();
        cout << "Masukkan Nama Barang: ";
        getline(cin, nama);
        cout << "Masukkan Kategori (Laptop/Desktop/Aksesoris): ";
        getline(cin, kategori);
        cout << "Masukkan Stok: ";
        cin >> stok;
        cout << "Masukkan Harga: Rp ";
        cin >> harga;
        
        Barang* newBarang = new Barang(kode, nama, kategori, stok, harga);
        
        if (head == nullptr) {
            head = newBarang;
        } else {
            Barang* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBarang;
        }
        
        cout << "Data berhasil ditambahkan!" << endl;
    }
    
    // 2. Lihat Data
    void lihatData() {
        if (head == nullptr) {
            cout << "\nGudang kosong!" << endl;
            return;
        }
        
        cout << "\n=== DATA BARANG GUDANG ===" << endl;
        cout << string(80, '=') << endl;
        cout << left << setw(8) << "Kode" 
             << setw(20) << "Nama Barang" 
             << setw(12) << "Kategori" 
             << setw(6) << "Stok" 
             << setw(12) << "Harga" << endl;
        cout << string(80, '-') << endl;
        
        Barang* temp = head;
        while (temp != nullptr) {
            cout << left << setw(8) << temp->kode 
                 << setw(20) << temp->nama 
                 << setw(12) << temp->kategori 
                 << setw(6) << temp->stok 
                 << "Rp " << fixed << setprecision(0) << temp->harga << endl;
            temp = temp->next;
        }
        cout << string(80, '=') << endl;
    }
    
    // 3. Hapus Data Depan
    void hapusDataDepan() {
        if (head == nullptr) {
            cout << "\nGudang kosong! Tidak ada data untuk dihapus." << endl;
            return;
        }
        
        Barang* temp = head;
        cout << "\nMenghapus barang: " << temp->kode << " - " << temp->nama << endl;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus!" << endl;
    }
    
    // 4. Hapus Data Belakang
    void hapusDataBelakang() {
        if (head == nullptr) {
            cout << "\nGudang kosong! Tidak ada data untuk dihapus." << endl;
            return;
        }
        
        if (head->next == nullptr) {
            cout << "\nMenghapus barang: " << head->kode << " - " << head->nama << endl;
            delete head;
            head = nullptr;
            cout << "Data berhasil dihapus!" << endl;
            return;
        }
        
        Barang* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        cout << "\nMenghapus barang: " << temp->next->kode << " - " << temp->next->nama << endl;
        delete temp->next;
        temp->next = nullptr;
        cout << "Data berhasil dihapus!" << endl;
    }
    
    // 5. Hapus Data Tengah
    void hapusDataTengah() {
        if (head == nullptr) {
            cout << "\nGudang kosong! Tidak ada data untuk dihapus." << endl;
            return;
        }
        
        int jumlah = hitungNode();
        if (jumlah <= 2) {
            cout << "\nTidak ada data di tengah untuk dihapus!" << endl;
            return;
        }
        
        cout << "\nPilih posisi data yang akan dihapus (2-" << jumlah-1 << "): ";
        int posisi;
        cin >> posisi;
        
        if (posisi < 2 || posisi >= jumlah) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }
        
        Barang* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        
        Barang* nodeHapus = temp->next;
        cout << "\nMenghapus barang: " << nodeHapus->kode << " - " << nodeHapus->nama << endl;
        temp->next = nodeHapus->next;
        delete nodeHapus;
        cout << "Data berhasil dihapus!" << endl;
    }
    
    // 6. Tambah Data Depan
    void tambahDataDepan() {
        string kode, nama, kategori;
        int stok;
        double harga;
        
        cout << "\n=== TAMBAH DATA DI DEPAN ===" << endl;
        cout << "Masukkan Kode Barang: ";
        cin >> kode;
        
        if (!isValidKode(kode)) {
            cout << "Error: Kode barang sudah ada!" << endl;
            return;
        }
        
        cin.ignore();
        cout << "Masukkan Nama Barang: ";
        getline(cin, nama);
        cout << "Masukkan Kategori (Laptop/Desktop/Aksesoris): ";
        getline(cin, kategori);
        cout << "Masukkan Stok: ";
        cin >> stok;
        cout << "Masukkan Harga: Rp ";
        cin >> harga;
        
        Barang* newBarang = new Barang(kode, nama, kategori, stok, harga);
        newBarang->next = head;
        head = newBarang;
        
        cout << "Data berhasil ditambahkan di depan!" << endl;
    }
    
    // 7. Tambah Data Belakang
    void tambahDataBelakang() {
        tambahData(); // Sama dengan tambah data biasa
    }
    
    // 8. Tambah Data Tengah
    void tambahDataTengah() {
        if (head == nullptr) {
            cout << "\nGudang kosong! Tambahkan data pertama terlebih dahulu." << endl;
            return;
        }
        
        int jumlah = hitungNode();
        cout << "\nJumlah data saat ini: " << jumlah << endl;
        cout << "Pilih posisi untuk menambah data (2-" << jumlah << "): ";
        int posisi;
        cin >> posisi;
        
        if (posisi < 2 || posisi > jumlah) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }
        
        string kode, nama, kategori;
        int stok;
        double harga;
        
        cout << "\n=== TAMBAH DATA DI TENGAH ===" << endl;
        cout << "Masukkan Kode Barang: ";
        cin >> kode;
        
        if (!isValidKode(kode)) {
            cout << "Error: Kode barang sudah ada!" << endl;
            return;
        }
        
        cin.ignore();
        cout << "Masukkan Nama Barang: ";
        getline(cin, nama);
        cout << "Masukkan Kategori (Laptop/Desktop/Aksesoris): ";
        getline(cin, kategori);
        cout << "Masukkan Stok: ";
        cin >> stok;
        cout << "Masukkan Harga: Rp ";
        cin >> harga;
        
        Barang* newBarang = new Barang(kode, nama, kategori, stok, harga);
        
        Barang* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        
        newBarang->next = temp->next;
        temp->next = newBarang;
        
        cout << "Data berhasil ditambahkan di posisi " << posisi << "!" << endl;
    }
    
    // Method untuk menampilkan menu
    void tampilkanMenu() {
        cout << "\n" << string(50, '=') << endl;
        cout << "    SISTEM MANAJEMEN GUDANG TOKO KOMPUTER" << endl;
        cout << string(50, '=') << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Lihat Data" << endl;
        cout << "3. Hapus Data Depan" << endl;
        cout << "4. Hapus Data Belakang" << endl;
        cout << "5. Hapus Data Tengah" << endl;
        cout << "6. Tambah Data Depan" << endl;
        cout << "7. Tambah Data Belakang" << endl;
        cout << "8. Tambah Data Tengah" << endl;
        cout << "9. Keluar" << endl;
        cout << string(50, '=') << endl;
        cout << "Pilih menu (1-9): ";
    }
};

int main() {
    GudangToko gudang;
    int pilihan;
    
    cout << "Selamat datang di Sistem Manajemen Gudang Toko Komputer!" << endl;
    
    do {
        gudang.tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                gudang.tambahData();
                break;
            case 2:
                gudang.lihatData();
                break;
            case 3:
                gudang.hapusDataDepan();
                break;
            case 4:
                gudang.hapusDataBelakang();
                break;
            case 5:
                gudang.hapusDataTengah();
                break;
            case 6:
                gudang.tambahDataDepan();
                break;
            case 7:
                gudang.tambahDataBelakang();
                break;
            case 8:
                gudang.tambahDataTengah();
                break;
            case 9:
                cout << "\nTerima kasih telah menggunakan sistem ini!" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih 1-9." << endl;
        }
        
        if (pilihan != 9) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 9);
    
    return 0;
}
