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

class DLL {
    private :
    node *head, *tail;
    public:
    DLL() {
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
    void displayforward() {
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
    

};
int main () {
    DLL s1 ;
    s1.insertEND("FaceBook.com");
    s1.insertEND("F");
    s1.displayforward();
    s1.insertBegin("B");
    s1.insertEND("K");  
    s1.displayforward();
    s1.displayReverse();
    return 0;

}