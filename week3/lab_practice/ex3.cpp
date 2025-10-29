#include <iostream>
using namespace std ;

class node {
    public :
    string url;
    node *next;
    node *previous;
    node(string s) {
        url = s;
        next = nullptr;
        previous = nullptr;
    }
};

class DoublyLinkedLis {
    private :
    node *head, *tail;
    public:
    DoublyLinkedLis() {
        head = nullptr;
        tail = nullptr;
    }
    void insertEND (string s) {
        node *Add = new node(s);
        if (head == nullptr) {
            head = Add ;
            tail = Add;
        } else {
            tail->next=Add;
            Add->previous= tail;
            tail = Add;

        }
    }
    void display() {
        if( head == nullptr) {
            cout << "list is emty" << endl;
        }
        node* t = head ;
        cout << "list display :";
        while (t != nullptr) {
            cout << t->url << " -> ";
            t = t->next;
        }
        cout << "NULL" <<endl;
    }
    void displayReverse() {
        node *t = tail;
        cout << "Display Reverse :" ;
        while (t != nullptr) {
            cout << t->url << " -> ";
            t = t->previous;
        }
        cout << "NULL" <<endl;
    }
    void insertBegin (string s){
        node *Addnew = new node (s);
        if (head == nullptr) {
            head = Addnew;
            tail = Addnew;
        } else {
            head ->previous = Addnew;
            Addnew->next = head;
            head = Addnew ;
    
        }
    }

};
int main () {
    DoublyLinkedLis s1 ;
    s1.insertBegin("Facebook.com");
    s1.display();
    s1.insertBegin("Youtube.com");
    s1.display();
    s1.insertBegin("Tiktok.com");
    s1.display();
    s1.insertBegin("Github.com");
    s1.display();
    return 0;

}