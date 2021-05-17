#include <iostream>
using namespace std;

struct node{
    int data = 0;
    node *left;
    node *right;
};

node *root;
void insert_node(node* root, int x){
    if(root->data == 0){
        root->data = x;
        root->left = new node;
        root->right = new node;
        return;
    }

    if(root->data > x){
        insert_node(root->left, x);
    }
    else{
        insert_node(root->right, x);
    }
}

void postorder(node* root){
    if(root->data != 0){
        postorder(root->left);
        postorder(root->right);
        cout << root->data <<"\n";
    }
}

int main(){
    int x;
    root = new node;
    while(cin >> x){
        insert_node(root, x);
    }
    postorder(root);
    return 0;
}
