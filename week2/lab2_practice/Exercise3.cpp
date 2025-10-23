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
    void count(){
        Node* temp =head;
        int c = 0;
        while (temp != nullptr){
            temp = temp->next_Node;
            c++;
        }
        cout<<"There are " <<c<<" in the list\n"<<endl;
    }
    //use to delete head
    ~SinglyLinkedList(){
        Node* current = head;
        while (current != nullptr){
            Node* next = current->next_Node;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    bool search (int ID) {
        Node* temp = head ;
        while (temp != nullptr){
            if ( temp->ID == ID){
                cout<< "ID : "<<ID<< " exist in list." <<endl;
                return true;
            }
            temp = temp->next_Node;
        }
        cout << "ID : " << ID << " doesn't exist in list." << endl;
        return false;
    }
    bool deleteAtFisrt() {
        if (head == nullptr){
            return false;
        } 
        Node* temp = head;
        head = head->next_Node;
        delete temp;
        return true;
    }
    bool deleteAtEnd() {
        if (head == nullptr) {
            return false;
        }
        Node* temp = head ;
        while (temp != nullptr){
            temp = temp->next_Node;
        }
        delete temp;
        temp = nullptr;
        return true;
    }

};
int main(){
    SinglyLinkedList s1;
    s1.InsertAtBegin(67,"Tho vicheka","AI Researcher");
    s1.InsertAtBegin(68,"Sliden","DS");
    s1.InsertAtBegin(69,"Reach","Data Analyist");
    s1.display();
    s1.count();
    s1.search(69);
    s1.search(12);
    s1.deleteAtEnd();
    s1.display();
    return 0 ;
}
    




