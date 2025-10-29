#include <iostream>
using namespace std;

class Node {
public:
    string url;
    Node* next;
    Node* prev;

    Node(string u) {
        url = u;
        next = nullptr;
        prev = nullptr;
    }
};
class BrowserHistory { 
    private:
    Node* current;
    public:
    BrowserHistory() {
        current = nullptr;
    }
    ~BrowserHistory() {
        if (current == nullptr) {
            return;
        }
        Node* temp = current;
        while (temp->prev) {
            temp = temp->prev;
        }
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        current = nullptr;
    }
    void visit(string url) {
        Node* newPage = new Node(url);
        if (current != nullptr) {
            Node* temp = current->next;
            current->next = nullptr;
            while (temp != nullptr) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            current->next = newPage;
            newPage->prev = current;
        }
        current = newPage;
        cout << "Visited: " << url << endl;
    }
    void back() {
        if (current == nullptr || current->prev == nullptr) {
            cout << "No previous history!" << endl;
            return;
        }
        current = current->prev;
        cout << "Go back to: " << current->url << endl;
    }
    void forward() {
        if (current == nullptr || current->next == nullptr) {
            cout << "No forward history!" << endl;
            return;
        }
        current = current->next;
        cout << "Go forward to: " << current->url << endl;
    }
    void showHistory() {
        if (current == nullptr) {
            cout << "No history available!" << endl;
            return;
        }
        Node* temp = current;
        while (temp->prev != nullptr)
            temp = temp->prev;
        cout << "Browser History: ";
        while (temp != nullptr) {
            if (temp == current)
                cout << "[" << temp->url << "] "; //marked the current page
            else
                cout << temp->url << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    BrowserHistory browser;

    browser.visit("google.com");
    browser.visit("youtube.com");
    browser.visit("wikipedia.org");

    browser.showHistory();
    browser.back();
     browser.showHistory();
    browser.back();
     browser.showHistory();
    browser.forward();
    browser.showHistory();
    browser.visit("github.com");
    browser.showHistory();

    return 0;
}