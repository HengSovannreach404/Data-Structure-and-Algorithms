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
    node *insert(node *root, int data ){
        if(root == nullptr){
            return new node(data);
        } else if (data < root->data){
            root->left = insert(root->left , data);
        } else if (data > root->data){
            root->right = insert(root->right ,data);
        }
        return root;
    }
    void inOrder(node *root){
        if(root!=nullptr){
            inOrder(root->left);
            cout<<root->data<< " ";
            inOrder(root->right);
        }

    }
    void preOrder(node *root){
        if(root !=nullptr){
            cout<<root->data<< " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void PostOrder(node *root){
        if(root !=nullptr){
            PostOrder(root->left);
            PostOrder(root->right);
            cout<<root->data<< " ";
        }
    }
    void add(int val){
        root = insert(root , val);
    }
    void displayInOrder(){
        cout<<"InOrder:";
        inOrder(root);
        cout<<endl;
    }
    void displayPreOrder(){
        cout<<"PreOrder :";
        preOrder(root);
        cout<<endl;
    }
    void displayPostOrder(){
        cout<<"Post-Order:";
        PostOrder(root);
        cout<<endl;
    }
};
int main () {
    Tree tree ;
    tree.add(50);
    tree.add(17);
    tree.add(72);
    tree.add(12);
    tree.add(23);
    tree.add(54);
    tree.add(76);
    tree.add(9);
    tree.add(14);
    tree.add(19);
    tree.add(67);
    tree.displayInOrder();
    tree.displayPreOrder();
    tree.displayPostOrder();
}