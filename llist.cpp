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

    int hitungNode() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void midKeHead(int size) {
        if (!head || !head->next) return;

        int midIndex = size / 2;
        Node* prev = nullptr;
        Node* curr = head;

        for (int i = 0; i < midIndex; ++i) {
            prev = curr;
            curr = curr->next;
        }

        if (prev && curr) {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << "[" << temp->data << "|0x" << temp << "] --> ";
            temp = temp->next;
        }
        cout << "[14|0]" << endl;
    }
};

int main() {
    SinglyLinkedList sll;

    // Tes awal
    sll.insertBelakang(100);
    sll.insertBelakang(1);
    sll.insertBelakang(84);
    sll.insertBelakang(14);

    sll.print();

    sll.insertBelakang(26);
    sll.print();

    sll.midKeHead(sll.hitungNode());
    sll.print();

    sll.insertBelakang(19);
    sll.print();

    sll.midKeHead(sll.hitungNode());
    sll.print();

    return 0;
}