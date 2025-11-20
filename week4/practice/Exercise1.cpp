#include<iostream>
#include<string>

class Stack {
private:
    struct Node {
        std::string data;
        Node* next;
        Node* prev;
        Node(std::string value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    ~Stack() {
        Node* current = top;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        top = nullptr;
    }
    void push(std::string value) {
        Node* newNode = new Node(value);

        if (top != nullptr) {
            top->prev = newNode;
        }

        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            std::cout << "Stack underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        if (top != nullptr) {
            top->prev = nullptr;
        }
        delete temp;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void displayBackward() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }
        std::cout << "Stack : ";
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};
int main() {
    Stack s;
    std::string word = "HELLO";
    for (int i = 0 ; i < 5; i++) {
        s.push(std::string(1, word[i]));
    }
    s.displayBackward();
    s.pop();
    s.pop();
    s.displayBackward();

    return 0;
}

