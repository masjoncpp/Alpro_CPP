#include <iostream>
using namespace std;

struct Node {
    int umur;
    Node* next;
};

// Tambah node di akhir
void tambahNode(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Tampilkan isi linked list
void tampilkan(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->umur << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// ?????(head)



int main() {
    Node* head = nullptr;

    // Masukkan data umur secara manual
    tambahNode(head, 21);
    tambahNode(head, 35);
    tambahNode(head, 18);
    tambahNode(head, 28);
    tambahNode(head, 25);

    cout << "Sebelum diurutkan:\n";
    tampilkan(head);

    // _______(head);

    cout << "????????:\n";
    tampilkan(head);

    return 0;
}
