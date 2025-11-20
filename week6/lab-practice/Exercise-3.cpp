#include <iostream>
#include <string.h>
using namespace std;
class node {
    public:
    string data;
    node *left;
    node *right;
    node (string Newdata ){
        data = Newdata;
        left = nullptr;
        right = nullptr;
     }
};
class Tree {
    public:
    node *root;
    Tree () {
        root = nullptr;
    }
    node *insert(node *root , string data){
        if(root==nullptr){
            return new node(data);
        } else if(data < root->data){
            root->left = insert(root->left,data);
        }
    }
};