#include <iostream>
class Node{
public:
    int id;
    Node* next;
    Node(int i):id(i),next(nullptr){}
};
class Queue{
private:
    Node* front;
    Node* rear;
public:
    // Constructor for front and rear
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    ~Queue(){
        Node* temp = front;
        if(!front){
            std::cout<<"Empty list \n";
            return;
        }
        while (temp != nullptr){
            Node* next_node  = temp->next;
            delete temp;
            temp = next_node;
        }
        front = nullptr;
        std::cout<<"Everything is cleared yeppiiiiiii";
    }
    void display(){
        if(!front){
            std::cout<<"Empty list \n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr){
            std::cout<<temp->id<<" ";
            temp = temp->next;
        }
        std::cout<<"\n";
    }
    void enqueue(int i){
        Node* new_Node = new Node(i);
        if(!front){
            front = rear = new_Node;
            return;
        }
        // Use rear to point to new node
        rear->next  = new_Node;
        // Make rear point to new node that is just created
        rear = new_Node;
    }
    void dequeue(){
        if(!front){
            std::cout<<"List is empty \n";
            return;
        }
        Node* temp = front->next;
        Node* current = front;
        delete current;
        front = temp;
    }
};
int main(){
    Queue q ;
    for (int i  = 0 ; i < 5; i ++){
        q.enqueue(i*i);
    }
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    return 0;
}

