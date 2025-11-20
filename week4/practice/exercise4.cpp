#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    void enqueue(const string& item) {
        Node* newNode = new Node{item, nullptr};
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string dequeue() {
        if (isEmpty()) {
            return "";
        }
        string data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    string peek() const {
        if (isEmpty()) {
            return "Queue is empty.";
        }
        return front->data;
    }
};

int main() {
    Queue bankQueue;

    bankQueue.enqueue("Customer A (Deposit)");
    cout << "Added: Customer A" << endl;
    cout << "Next to be served: " << bankQueue.peek() << endl;

    bankQueue.enqueue("Customer B (Withdrawal)");
    cout << "Added: Customer B" << endl;

    bankQueue.enqueue("Customer C (Loan Inquiry)");
    cout << "Added: Customer C" << endl;
    cout << "Next to be served: " << bankQueue.peek() << endl;

    cout << "\n--- Serving Customers ---" << endl;
    cout << "Served: " << bankQueue.dequeue() << endl;
    cout << "Served: " << bankQueue.dequeue() << endl;
    cout << "Next to be served: " << bankQueue.peek() << endl;

    bankQueue.enqueue("Customer D (New Account)");
    cout << "Added: Customer D" << endl;
    cout << "Served: " << bankQueue.dequeue() << endl;

    cout << "Is the queue empty? " << (bankQueue.isEmpty() ? "Yes" : "No") << endl;

    cout << "Served: " << bankQueue.dequeue() << endl;
    cout << "Is the queue empty? " << (bankQueue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
