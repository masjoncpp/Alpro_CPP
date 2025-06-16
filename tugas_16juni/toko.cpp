#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// Struct untuk node barang dalam stack
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

class GudangTokoStack {
private:
    Barang* top;  // Pointer ke elemen teratas stack
    int size;     // Jumlah elemen dalam stack
    
    // Method private untuk validasi input
    bool isValidKode(string kode) {
        Barang* temp = top;
        while (temp != nullptr) {
            if (temp->kode == kode) {
                return false; // Kode sudah ada
            }
            temp = temp->next;
        }
        return true; // Kode belum ada
    }
    
    // Method untuk mendapatkan barang berdasarkan posisi dari atas
    Barang* getBarangAtPosition(int pos) {
        if (pos < 1 || pos > size) return nullptr;
        
        Barang* temp = top;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        return temp;
    }

public:
    // Constructor
    GudangTokoStack() {
        top = nullptr;
        size = 0;
    }
    
    // Destructor untuk membersihkan memori
    ~GudangTokoStack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    // Method untuk mengecek apakah stack kosong
    bool isEmpty() {
        return top == nullptr;
    }
    
    // Method untuk mendapatkan ukuran stack
    int getSize() {
        return size;
    }
    
    // OPERASI STACK DASAR
    
    // Push - Menambah elemen ke atas stack
    void push(string kode, string nama, string kategori, int stok, double harga) {
        if (!isValidKode(kode)) {
            cout << "Error: Kode barang sudah ada!" << endl;
            return;
        }
        
        Barang* newBarang = new Barang(kode, nama, kategori, stok, harga);
        newBarang->next = top;
        top = newBarang;
        size++;
        cout << "Data berhasil ditambahkan ke atas stack!" << endl;
    }
    
    // Pop - Menghapus elemen teratas stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong! Tidak ada data untuk dihapus." << endl;
            return;
        }
        
        Barang* temp = top;
        cout << "Menghapus barang dari atas: " << temp->kode << " - " << temp->nama << endl;
        top = top->next;
        delete temp;
        size--;
        cout << "Data berhasil dihapus dari atas stack!" << endl;
    }
    
    // Peek - Melihat elemen teratas tanpa menghapus
    void peek() {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return;
        }
        
        cout << "\n=== DATA TERATAS STACK ===" << endl;
        cout << "Kode: " << top->kode << endl;
        cout << "Nama: " << top->nama << endl;
        cout << "Kategori: " << top->kategori << endl;
        cout << "Stok: " << top->stok << endl;
        cout << "Harga: Rp " << fixed << setprecision(0) << top->harga << endl;
    }
    
    // MENU OPERASI SESUAI PERMINTAAN
    
    // 1. Tambah Data (menggunakan push)
    void tambahData() {
        string kode, nama, kategori;
        int stok;
        double harga;
        
        cout << "\n=== TAMBAH DATA BARANG (PUSH) ===" << endl;
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
        
        push(kode, nama, kategori, stok, harga);
    }
    
    // 2. Lihat Data (menampilkan seluruh stack)
    void lihatData() {
        if (isEmpty()) {
            cout << "\nGudang kosong!" << endl;
            return;
        }
        
        cout << "\n=== DATA BARANG GUDANG (STACK) ===" << endl;
        cout << "Total barang: " << size << endl;
        cout << string(85, '=') << endl;
        cout << left << setw(4) << "Pos" << setw(8) << "Kode" 
             << setw(20) << "Nama Barang" 
             << setw(12) << "Kategori" 
             << setw(6) << "Stok" 
             << setw(12) << "Harga" << endl;
        cout << string(85, '-') << endl;
        
        Barang* temp = top;
        int posisi = 1;
        while (temp != nullptr) {
            cout << left << setw(4) << posisi << setw(8) << temp->kode 
                 << setw(20) << temp->nama 
                 << setw(12) << temp->kategori 
                 << setw(6) << temp->stok 
                 << "Rp " << fixed << setprecision(0) << temp->harga << endl;
            temp = temp->next;
            posisi++;
        }
        cout << string(85, '=') << endl;
        cout << "Catatan: Posisi 1 = Teratas (Top), Posisi " << size << " = Terbawah (Bottom)" << endl;
    }
    
    // 3. Hapus Data Depan (Pop - hapus dari atas)
    void hapusDataDepan() {
        pop();
    }
    
    // 4. Hapus Data Belakang (hapus dari bawah stack)
    void hapusDataBelakang() {
        if (isEmpty()) {
            cout << "\nStack kosong! Tidak ada data untuk dihapus." << endl;
            return;
        }
        
        if (size == 1) {
            pop();
            return;
        }
        
        // Mencari node sebelum node terakhir
        Barang* temp = top;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        cout << "\nMenghapus barang dari bawah: " << temp->next->kode << " - " << temp->next->nama << endl;
        delete temp->next;
        temp->next = nullptr;
        size--;
        cout << "Data berhasil dihapus dari bawah stack!" << endl;
    }
    
    // 5. Hapus Data Tengah
    void hapusDataTengah() {
        if (isEmpty()) {
            cout << "\nStack kosong! Tidak ada data untuk dihapus." << endl;
            return;
        }
        
        if (size <= 2) {
            cout << "\nTidak ada data di tengah untuk dihapus!" << endl;
            return;
        }
        
        cout << "\nPilih posisi data yang akan dihapus (2-" << size-1 << "): ";
        int posisi;
        cin >> posisi;
        
        if (posisi < 2 || posisi >= size) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }
        
        Barang* temp = top;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        
        Barang* nodeHapus = temp->next;
        cout << "\nMenghapus barang posisi " << posisi << ": " << nodeHapus->kode << " - " << nodeHapus->nama << endl;
        temp->next = nodeHapus->next;
        delete nodeHapus;
        size--;
        cout << "Data berhasil dihapus!" << endl;
    }
    
    // 6. Tambah Data Depan (Push - standar stack operation)
    void tambahDataDepan() {
        tambahData(); // Sama dengan operasi push standar
    }
    
    // 7. Tambah Data Belakang (insert di bawah stack)
    void tambahDataBelakang() {
        string kode, nama, kategori;
        int stok;
        double harga;
        
        cout << "\n=== TAMBAH DATA DI BAWAH STACK ===" << endl;
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
        
        if (isEmpty()) {
            top = newBarang;
        } else {
            Barang* temp = top;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBarang;
        }
        size++;
        cout << "Data berhasil ditambahkan di bawah stack!" << endl;
    }
    
    // 8. Tambah Data Tengah
    void tambahDataTengah() {
        if (isEmpty()) {
            cout << "\nStack kosong! Tambahkan data pertama terlebih dahulu." << endl;
            return;
        }
        
        cout << "\nJumlah data saat ini: " << size << endl;
        cout << "Pilih posisi untuk menambah data (2-" << size << "): ";
        int posisi;
        cin >> posisi;
        
        if (posisi < 2 || posisi > size) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }
        
        string kode, nama, kategori;
        int stok;
        double harga;
        
        cout << "\n=== TAMBAH DATA DI TENGAH STACK ===" << endl;
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
        
        Barang* temp = top;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        
        newBarang->next = temp->next;
        temp->next = newBarang;
        size++;
        
        cout << "Data berhasil ditambahkan di posisi " << posisi << "!" << endl;
    }
    
    // Method tambahan untuk operasi stack
    void lihatDataTeratas() {
        peek();
    }
    
    void infoStack() {
        cout << "\n=== INFORMASI STACK ===" << endl;
        cout << "Jumlah data: " << size << endl;
        cout << "Status: " << (isEmpty() ? "Kosong" : "Berisi") << endl;
        if (!isEmpty()) {
            cout << "Data teratas: " << top->kode << " - " << top->nama << endl;
        }
    }
    
    // Method untuk menampilkan menu
    void tampilkanMenu() {
        cout << "\n" << string(55, '=') << endl;
        cout << "    SISTEM MANAJEMEN GUDANG TOKO KOMPUTER (STACK)" << endl;
        cout << string(55, '=') << endl;
        cout << "1. Tambah Data (Push)" << endl;
        cout << "2. Lihat Data (Display Stack)" << endl;
        cout << "3. Hapus Data Depan (Pop)" << endl;
        cout << "4. Hapus Data Belakang" << endl;
        cout << "5. Hapus Data Tengah" << endl;
        cout << "6. Tambah Data Depan (Push)" << endl;
        cout << "7. Tambah Data Belakang" << endl;
        cout << "8. Tambah Data Tengah" << endl;
        cout << "9. Keluar" << endl;
        cout << string(25, '-') << " MENU STACK " << string(25, '-') << endl;
        cout << "10. Lihat Data Teratas (Peek)" << endl;
        cout << "11. Info Stack" << endl;
        cout << string(55, '=') << endl;
        cout << "Pilih menu (1-11): ";
    }
};

int main() {
    GudangTokoStack gudang;
    int pilihan;
    
    cout << "Selamat datang di Sistem Manajemen Gudang Toko Komputer (Stack Implementation)!" << endl;
    cout << "Stack menggunakan prinsip LIFO (Last In First Out)" << endl;
    
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
            case 10:
                gudang.lihatDataTeratas();
                break;
            case 11:
                gudang.infoStack();
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih 1-11." << endl;
        }
        
        if (pilihan != 9) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 9);
    
    return 0;
}
