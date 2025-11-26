#include<iostream>
using namespace std;
struct Customer
{
    int id;
    string name;

};
class node{
public:
    Customer* data;
    node* right;
    node* left;
    node(int id, string name){
        data = new Customer();
        data->name = name;
        data->id = id;
        right = left = nullptr;
    }
};
class Tree{
private:
    node* root;
public:
    Tree(){
        root = nullptr;
    }
    node* insertNode(node* root, Customer s){
        if (root == nullptr) {
            return new node(s.id, s.name);
        }
        if(s.id<root->data->id){
            root->left = insertNode(root->left,s);
        }
        if(s.id > root->data->id){
            root->right = insertNode(root->right, s);
        }
        return root;
    }
    void insert(Customer a){
        root = insertNode(root,a);
    }
    void inOrder(node* root){
        if(root==nullptr) return;
        inOrder(root->left);
        cout<<"id "<<root->data->id <<" Name: "<< root->data->name<<endl;
        inOrder(root->right);
    }
    void preOrder(node* root){
        if(root==nullptr) return;
        cout<<"id "<<root->data->id <<" Name: "<< root->data->name<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(node* root){
        if(root==nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<"id "<<root->data->id <<" Name: "<< root->data->name<<endl;
    }
    void displayPreOrder(){
        preOrder(root);
    }
    void displayInOrder(){
        inOrder(root);
    }
    void displayPostOrder(){
        postOrder(root);
    }
    node* searchNode(node* root, int id){
    if(root==nullptr){
        return nullptr;   
    }
    if (id == root->data->id) {
        return root;     
    }
    else if (id < root->data->id) {
        return searchNode(root->left, id);
    }
    else {
        return searchNode(root->right, id);
    }
}

node* search(int id) {
    return searchNode(root, id);
} 
};

int main(){
    Tree tree;
    Customer c1 = {3, "Reach"};
    Customer c2 = {1, "Seth"};
    Customer c3 = {4, "Pheaktra"};
    Customer c4 = {2, "Omra"};
    Customer c5 = {5, "Chesda"};

    tree.insert(c1);
    tree.insert(c2);
    tree.insert(c3);
    tree.insert(c4);
    tree.insert(c5);
    cout << "InOrder: ";
    cout<<endl;
    tree.displayInOrder();
    cout << "PreOrder: ";
    cout<<endl;
    tree.displayPreOrder();
    cout << "PostOrder: ";
    cout<<endl;
    tree.displayPostOrder();
    cout<<"Search "<< tree.search(2)->data->name<<endl;
    return 0;
}