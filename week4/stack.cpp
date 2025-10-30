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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* mynewNode = new Node(value);
        mynewNode->next = top;
        top = mynewNode;
    }

    void pop() {
        if (!top) {
            cout << "Stack Underflow!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() {
        if (top == nullptr)
            return true;
        else
            return false;
    }

    bool search(int a) {
        if (top == nullptr) {
            cout << "stack is empty" << endl;
            return false;
        }

        Node* t = top;
        while (t != nullptr) {
            if (t->data == a) {
                cout << "N :" << a << " Exit in list" << endl;
                return true;
            }
            t = t->next;
        }

        cout << "N :" << a << " not found in stack" << endl;
        return false;
    }

    void display() {
        Node* temp = top;
        cout << "Stack (top→bottom): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.search(10);
    s.search(90);
    return 0;
}
