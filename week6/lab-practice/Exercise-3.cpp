#include <iostream>
#include <string.h>
using namespace std;
class node {
    public:
    string name;
    node *left;
    node *right;
    node (string s){
        name = s;
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
    node *insert(node *root , string name){
        if(root==nullptr){
            return new node(name);
        } else if(name < root->name){
            root->left = insert(root->left, name);
        } else if (name > root->name) {
            root->right = insert(root->right, name);
        }
        return root;
    }
    void add (string s) {
        root = insert(root, s);
    }
    void inorder(node* root){
        if(root != nullptr){
            inorder(root->left);
            cout<< root->name << "  " ;
            inorder(root->right);
        }
        
    }
    void showStudents() {
        cout << "Students In A-Z order :";
        inorder(root);
    }
};
int main() {
    Tree student;

    // Testing BST with student names
    student.add("Reach");
    student.add("Chesda");
    student.add("Vichka");
    student.add("Aob");

    student.showStudents();

    return 0;
}