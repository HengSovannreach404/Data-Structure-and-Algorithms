#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SLL {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    SLL() {
        head = nullptr;
        tail = nullptr;
    }

    // Add a node at the end
    void addToEnd(int value) {
        Node* mynewNode = new Node(value);

        if (head == nullptr) { // empty list
            head = mynewNode;
            tail = mynewNode;
        } else { // not empty
            tail->next = mynewNode;
            tail = mynewNode;
        }
    }

    // Print all nodes
    void print() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Nullptr" << endl;
    }
};

int main() {
    SLL s1;

    s1.addToEnd(4);
    s1.addToEnd(7);
    s1.addToEnd(9);
    s1.print();

    s1.addToEnd(0);
    s1.print();

    return 0;
}
