#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertBelakang(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void reverseNode() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;   // Simpan next
            curr->next = prev;   // Balikkan pointer
            prev = curr;         // Geser prev ke curr
            curr = next;         // Geser curr ke next
        }
        head = prev;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << "[" << temp->data << "|0x" << temp << "] --> ";
            temp = temp->next;
        }
        cout << "[0]" << endl;
    }
};

int main() {
    SinglyLinkedList sll;

    // Masukkan data seperti contoh
    sll.insertBelakang(1);
    sll.insertBelakang(84);
    sll.insertBelakang(100);
    sll.insertBelakang(14);
    sll.insertBelakang(26);
    sll.insertBelakang(19);

    cout << "Sebelum reverse:" << endl;
    sll.print();

    sll.reverseNode();

    cout << "Setelah reverse:" << endl;
    sll.print();

    return 0;
}