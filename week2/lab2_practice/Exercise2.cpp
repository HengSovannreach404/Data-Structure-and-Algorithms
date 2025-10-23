#include <iostream>
#include <cstring>
using namespace std;
class Node {
    public:
    char* name = nullptr;
    char* major = nullptr;
    int ID;
    Node* next_Node ;
    Node (int id ,const char* n , const char* m ) {
        ID = id ;
        name = new char[strlen(n) + 1];
        strcpy(name , n);
        major = new char[strlen(m) + 1];
        strcpy(major , m);
        next_Node = nullptr;
    }
    ~Node (){
        delete [] name;
        delete [] major;

    }
};
class SinglyLinkedList{
    private:
    Node*head;
    public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void InsertAtBegin (int id ,const char* n , const char* m){
        Node *Mynew = new Node(id , n , m);
        if(head == nullptr){
            head = Mynew;
            return ;
        } else {
            Mynew->next_Node = head;
            head = Mynew;
        }
    }
    void display() {
        Node* temp = head;
        while(temp != nullptr){
            cout<<"(Student name: "<<temp->name<<" Student major )"<<temp->major <<endl;
            temp = temp->next_Node;
        }
        cout<<"Null"<<endl;
    }
};
int main(){
    SinglyLinkedList s1;
    s1.InsertAtBegin(67,"Tho vicheka","AI Researcher");
    s1.display();
    s1.InsertAtBegin(68,"Sliden","DS");
    s1.display();
    s1.InsertAtBegin(69,"Reach","Data Analyist");
    s1.display();
    return 0 ;
}
    




