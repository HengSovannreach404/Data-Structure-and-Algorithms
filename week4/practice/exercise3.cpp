#include <iostream>
#include <string>
using namespace std ;
struct Node {
    std::string data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    void push(const string& item) {
        Node* newNode = new Node{item, top};
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        std::string data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    string peek() const {
        if (isEmpty()) {
            return "";
        }
        return top->data;
    }
};

class BrowserHistory {
private:
    Stack backStack;
    Stack forwardStack;
    std::string currentUrl;

public:
    BrowserHistory() : currentUrl("home") {}

    void visit(const string& url) {
        if (currentUrl != "home") {
            backStack.push(currentUrl);
        }
        currentUrl = url;
        while (!forwardStack.isEmpty()) {
            forwardStack.pop();
        }
    }

    string back() {
        if (backStack.isEmpty()) {
            return "Cannot go back. Current: " + currentUrl;
        }
        forwardStack.push(currentUrl);
        currentUrl = backStack.pop();
        return "Current URL: " + currentUrl;
    }

    string forward() {
        if (forwardStack.isEmpty()) {
            return "Cannot go forward. Current: " + currentUrl;
        }
        backStack.push(currentUrl);
        currentUrl = forwardStack.pop();
        return "Current URL: " + currentUrl;
    }

    std::string getCurrentUrl() const {
        return "Current URL: " + currentUrl;
    }
};

int main() {
    BrowserHistory browser;

    browser.visit("www.google.com");
    browser.visit("www.youtube.com");
    browser.visit("www.wikipedia.org");

    cout << browser.getCurrentUrl() <<endl;

    cout << browser.back() <<endl;
    cout << browser.back() <<endl;

    cout << browser.forward() <<endl;

    browser.visit("www.gemini.com");
    cout << browser.getCurrentUrl() <<endl;

    cout << browser.forward() <<endl;

    cout << browser.back() <<endl;

    return 0;
}
