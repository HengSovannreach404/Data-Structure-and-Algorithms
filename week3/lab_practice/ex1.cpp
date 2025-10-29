#include <iostream>
using namespace std ;
class node {
    public :
    int data ;
    node* next ; 
    node (int value){
        data = value ;
        next = nullptr;
    }
    
};
class CircularLinkedList {
    private:
    node *head , *tail ;
    public :
    CircularLinkedList () {
        head = nullptr;
        tail = nullptr;
    }
    void add(int value) {
        node *Addnew = new node(value);
        if (head == nullptr) {
            head = Addnew;
            tail = Addnew;
            tail->next = head;
        } else {
            tail->next = head;
            Addnew->next = head;
            tail = Addnew;

        }
    }
    void AddBegin(int value) {
        node * newnode  = new node(value);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
            tail -> next = head;
        } else {
            newnode -> next = head;
            head = newnode;
            tail->next = head;
        }
    }
    void display (){
        node *t = head;
        cout << "List diplay : " ;
        do {
            cout << t->data << " --> " ;
            t = t->next;
        }
        while (t != head);
            cout << "back to head" << endl;
        cout << "NULL" << endl;
    }
    void deleteHead(){
        if(head == nullptr){
            cout << "List is empty"<< endl;
            return;
        }
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        node *t = head;
        while (t->next != head){
            t = t->next;
        }
        node* toDelete = head;
        head = head->next;
        t->next = head; 
        delete toDelete;

    }
};
int main () {
    CircularLinkedList s1 ;
    s1.add(23);
    s1.AddBegin(33);
    s1.display();
    s1.deleteHead();
    s1.display();
    return 0 ;
}