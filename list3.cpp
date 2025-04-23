
#include <iostream>
using namespace std;

struct Node {
    int umur;
    Node* next;
};

int main() {
    // Buat 5 node
    Node* n1 = new Node{21, nullptr};
    Node* n2 = new Node{18, nullptr};
    Node* n3 = new Node{35, nullptr};
    Node* n4 = new Node{28, nullptr};
    Node* n5 = new Node{25, nullptr};

    // Hubungkan node satu per satu
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Cetak isi linked list
    Node* current = n1;
    while (current != nullptr) {
        cout << "Umur: " << current->umur << endl;
        current = current->next;
    }

    return 0;
}