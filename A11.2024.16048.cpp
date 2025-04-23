#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int umur;
    Node* next;
};

// menghitung total isi
int sumLinkedList(Node* head) {
    int sum = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->umur;
        current = current->next;
    }
    return sum;
}

int main() {
    // Buat 5 node
    Node* n1 = new Node{11, nullptr};
    Node* n2 = new Node{16, nullptr};
    Node* n3 = new Node{40, nullptr};
    Node* n4 = new Node{9, nullptr};
    Node* n5 = new Node{78, nullptr};

    // menghubungkan node
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Cetak isi linked list
    cout << "Isi Linked List:" << endl;
    Node* current_print = n1;
    while (current_print != nullptr) {
        cout << "Umur: " << current_print->umur << endl;
        current_print = current_print->next;
    }
    cout << endl;

    // Hitung dan mencetak total isi node dari linked list
    int total = sumLinkedList(n1);
    cout << "Total isi (umur) node dari linked list adalah : " << total << endl;


    Node* current_delete = n1;
    Node* next_node = nullptr;
    while (current_delete != nullptr) {
        next_node = current_delete->next;
        delete current_delete;
        current_delete = next_node;
    }

    return 0;
}
