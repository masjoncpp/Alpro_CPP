//Title : bermain dua bilangan
//Made by : A11.2024.16048
//Modify : 12 March 2025
#include<iostream>
using namespace std;

//declare(Kamus)
int a, b, tmpt, x, DATA[5];

//describ
int main()
{
    cout << "Sorting 5 bilangan dengan Array" << endl;
    cout << "Dengan Metode Bubble Sort" << endl;

    // Mengisi data ke array
    x = 0; // awalan
    while (x < 5) // tujuan
    {
        cout << "Data Ke : " << x + 1 << " = ";
        cin >> DATA[x]; // yang diulang
        x = x + 1; // counter
    }

    // Menampilkan isi tabel sebelum diurutkan
    cout << "\nData sebelum diurutkan:" << endl;
    x = 0; // awalan
    while (x < 5) // tujuan
    {
        cout << "Data Ke : " << x + 1 << " = " << DATA[x] << endl; // yang diulang
        x = x + 1; // counter
    }

    // Sorting dengan metode Bubble Sort
    a = 0;
    while (a < 5)
    {
        b = a + 1;
        while (b < 5) // Perbaikan: b < 5, bukan b <= 5
        {
            // Pertukaran
            if (DATA[a] > DATA[b])
            {
                tmpt = DATA[a];
                DATA[a] = DATA[b];
                DATA[b] = tmpt;
            }
            b = b + 1;
        }
        a = a + 1;
    }

    // Menampilkan isi tabel setelah diurutkan
    cout << "\nData setelah diurutkan:" << endl;
    x = 0; // awalan
    while (x < 5) // tujuan
    {
        cout << "Data Ke : " << x + 1 << " = " << DATA[x] << endl; // yang diulang
        x = x + 1; // counter
    }

    return 0;
}
