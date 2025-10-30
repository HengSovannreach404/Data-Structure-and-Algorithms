#include<iostream>
using namespace std;
class node {
public:
    string name;
    node * next ;
    node ( string a){
        name = a;
        next = nullptr;
    }
};
class Queue {
private:
    node *front , *back;
    int size;
public:
    Queue () {
        front = nullptr;
        back = nullptr;
        size = 0;
    }
    bool isEmpty(){
        if( back == nullptr ){
            return true;
        } else return false ;
    }
    void enqueue( string a){
        node * newName = new node(a);
        if ( back == nullptr){
            front = newName;
            back = newName;
        } else {
            back->next = newName;
            back = newName;
        }
        size++;
    }
    string dequeue() { 
        if (front == nullptr) {
            back = nullptr;
            cout << "Queue Underflow!\n";
            return " ";
        }

        node* t = front;
        front = front->next;
        string deleteFront = t->name;
        delete t;
        size--;
        return deleteFront;

    }

    void dispaly (){
        node * t = front;
        if (size == 0) {
            cout << "Queue is empty"<< endl;
            return;
        } cout << "Queue (front->back) :";
        while (t) {
            cout << t->name << " " ;
            t = t->next;
        }


    }
};
int main (){
    Queue s;
    s.isEmpty();
    s.enqueue("ss");
    s.enqueue("aa");
    s.enqueue("JJ");
    s.dispaly();
    s.dequeue();
    s.dispaly();
}