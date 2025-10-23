#include <iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};
class SinglyLInkedList{
    private:
    Node*head;

    public:
    SinglyLInkedList(){
        head = nullptr;
    }
    void insertAtBegin(int value) {
        Node *myNewNode = new Node(value);
        if (head==nullptr){
            head = myNewNode;
        } else {
            myNewNode->next = this->head;
            this->head = myNewNode;
        }

    }
    void insertAtEnd(int value) {
        Node *Mynew = new Node(value);
        if(head == nullptr){
        head = Mynew;
    } else {
        Node* t = head ;
        while (t->next != nullptr){
            t = t->next;
        }
        t->next = Mynew;

    }
}

     // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL \n";
        }
        void getSize(){
            
        }
};
int main () {
    SinglyLInkedList mylist;
    
    mylist.insertAtBegin(2);
    mylist.display();
    mylist.insertAtBegin(3);
    mylist.display();   
    mylist.insertAtBegin(67);
    mylist.display();
    mylist.insertAtEnd(19);
    mylist.insertAtEnd(90);
    mylist.display();
}

