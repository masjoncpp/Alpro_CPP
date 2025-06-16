#include <iostream>
#include <string>
#include <iomanip>
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
    Barang* top;      // Pointer ke elemen teratas stack
    int size;         // Jumlah elemen dalam stack
    int maxSize;      // Batas maksimal elemen dalam stack

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

public:
    // Constructor
    GudangTokoStack(int max = 100) {  // Default maxSize = 100
        top = nullptr;
        size = 0;
        maxSize = max;
    }

    // Destructor untuk membersihkan memori
    ~GudangTokoStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Method untuk mengatur batas maksimal stack
    void setMaxSize(int max) {
        maxSize = max;
    }

    // Method untuk mendapatkan batas maksimal stack
    int getMaxSize() {
        return maxSize;
    }

    // OPERASI STACK MURNI - HANYA LIFO

    // Method untuk mengecek apakah stack kosong
    bool isEmpty() {
        return top == nullptr;
    }

    // Method untuk mendapatkan ukuran stack
    int getSize() {
        return size;
    }

    // PUSH - Menambah elemen ke atas stack (satu-satunya cara menambah data)
    bool push(string kode, string nama, string kategori, int stok, double harga) {
        if (!isValidKode(kode)) {
            cout << "Error: Kode barang sudah ada!" << endl;
            return false;
        }

        if (size >= maxSize) {
            cout << "Error: Stack penuh! Maksimal " << maxSize << " barang." << endl;
            return false;
        }

        Barang* newBarang = new Barang(kode, nama, kategori, stok, harga);
        newBarang->next = top;
        top = newBarang;
        size++;
        cout << "Data berhasil ditambahkan ke stack (PUSH)!" << endl;
        return true;
    }

    // POP - Menghapus elemen teratas stack (satu-satunya cara menghapus data)
    bool pop() {
        if (isEmpty()) {
            cout << "Stack kosong! Tidak ada data untuk dihapus." << endl;
            return false;
        }

        Barang* temp = top;
        cout << "Menghapus barang dari stack (POP): " << temp->kode << " - " << temp->nama << endl;
        top = top->next;
        delete temp;
        size--;
        cout << "Data berhasil dihapus dari stack!" << endl;
        return true;
    }

    // PEEK/TOP - Melihat elemen teratas tanpa menghapus
    void peek() {
        if (isEmpty()) {
            cout << "\nStack kosong! Tidak ada data untuk dilihat." << endl;
            return;
        }

        cout << "\n=== DATA TERATAS STACK (PEEK) ===" << endl;
        cout << "Kode: " << top->kode << endl;
        cout << "Nama: " << top->nama << endl;
        cout << "Kategori: " << top->kategori << endl;
        cout << "Stok: " << top->stok << endl;
        cout << "Harga: Rp " << fixed << setprecision(0) << top->harga << endl;
        cout << "=================================" << endl;
    }

    // DISPLAY - Menampilkan seluruh isi stack (dari atas ke bawah)
    void display() {
        if (isEmpty()) {
            cout << "\nStack kosong! Tidak ada data untuk ditampilkan." << endl;
            return;
        }

        cout << "\n=== ISI STACK (TOP -> BOTTOM) ===" << endl;
        cout << "Total barang dalam stack: " << size << " (Maksimal: " << maxSize << ")" << endl;
        cout << string(80, '=') << endl;
        cout << left << setw(4) << "Pos" << setw(8) << "Kode"
             << setw(20) << "Nama Barang"
             << setw(12) << "Kategori"
             << setw(6) << "Stok"
             << setw(15) << "Harga" << endl;
        cout << string(80, '-') << endl;

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
        cout << string(80, '=') << endl;
        cout << "Catatan: Posisi 1 = TOP (teratas), Posisi " << size << " = BOTTOM (terbawah)" << endl;
        cout << "Prinsip LIFO: Yang masuk terakhir, keluar pertama!" << endl;
    }

    // Method untuk input data baru (menggunakan PUSH)
    void inputDataBaru() {
        string kode, nama, kategori;
        int stok;
        double harga;

        cout << "\n=== TAMBAH DATA BARU KE STACK ===" << endl;
        cout << "Data akan ditambahkan ke TOP stack (prinsip LIFO)" << endl;
        cout << "Kapasitas stack: " << size << "/" << maxSize << endl;
        cout << "-------------------------------------------------" << endl;

        cout << "Masukkan Kode Barang: ";
        cin >> kode;

        if (!isValidKode(kode)) {
            cout << "Error: Kode barang sudah ada dalam stack!" << endl;
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

    // Method untuk menampilkan informasi stack
    void infoStack() {
        cout << "\n=== INFORMASI STACK ===" << endl;
        cout << "Jumlah data: " << size << endl;
        cout << "Batas maksimal: " << maxSize << endl;
        cout << "Kapasitas tersisa: " << (maxSize - size) << endl;
        cout << "Status: " << (isEmpty() ? "Kosong" : "Berisi") << endl;
        cout << "Struktur: LIFO (Last In, First Out)" << endl;

        if (!isEmpty()) {
            cout << "Data TOP: " << top->kode << " - " << top->nama << endl;
            cout << "Harga TOP: Rp " << fixed << setprecision(0) << top->harga << endl;
        }
        cout << "=======================" << endl;
    }

    // Method untuk menampilkan menu
    void tampilkanMenu() {
        cout << "\n" << string(50, '=') << endl;
        cout << "       GUDANG TOKO KOMPUTER - STACK MURNI" << endl;
        cout << "              (LIFO Implementation)" << endl;
        cout << "Kapasitas: " << size << "/" << maxSize << endl;
        cout << string(50, '=') << endl;
        cout << "1. PUSH - Tambah Data Baru (ke TOP)" << endl;
        cout << "2. POP  - Hapus Data (dari TOP)" << endl;
        cout << "3. PEEK - Lihat Data TOP" << endl;
        cout << "4. DISPLAY - Tampilkan Semua Data" << endl;
        cout << "5. INFO - Informasi Stack" << endl;
        cout << "6. EXIT - Keluar Program" << endl;
        cout << string(50, '=') << endl;
        cout << "Pilih operasi (1-6): ";
    }
};

int main() {
    int maxStack;
    cout << string(60, '=') << endl;
    cout << "  SELAMAT DATANG DI SISTEM GUDANG TOKO KOMPUTER" << endl;
    cout << "            IMPLEMENTASI STACK MURNI" << endl;
    cout << string(60, '=') << endl;
    cout << "Masukkan batas maksimal stack: ";
    cin >> maxStack;

    GudangTokoStack gudang(maxStack);
    int pilihan;

    do {
        gudang.tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                gudang.inputDataBaru();
                break;
            case 2:
                gudang.pop();
                break;
            case 3:
                gudang.peek();
                break;
            case 4:
                gudang.display();
                break;
            case 5:
                gudang.infoStack();
                break;
            case 6:
                cout << "\n" << string(40, '=') << endl;
                cout << "Terima kasih telah menggunakan program!" << endl;
                cout << "Stack LIFO - Computer Store Management" << endl;
                cout << string(40, '=') << endl;
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih 1-6." << endl;
        }

        if (pilihan != 6) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 6);

    return 0;
}
