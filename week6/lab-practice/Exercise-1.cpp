#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;
    node (int newData){
        data = newData;
        left = nullptr;
        right = nullptr;
    }
};
class Tree{
    public:
    node *root;
    Tree(){
        root = nullptr;
    }
};
int main() {}