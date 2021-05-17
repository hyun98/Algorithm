#include <iostream>

using namespace std;

typedef struct node{
    char top;   //노드에 저장된 값
    node *left = NULL;
    node *right = NULL;
    node(){}
    node(char top) : top(top){}
}node;

class Tree{
    int check = 0;
    void search(node *root, char top, char c1, char c2){
        if(check == 1){
            return;
        }
        if(root == NULL){
            return;
        }
        else if(root->top == top){
            if(c1 != '.'){
                root->left = new node(c1);
            }
            if(c2 != '.'){
                root->right = new node(c2);
            }
            check = 1;
        }
        else{
            search(root->left, top, c1, c2);     //왼쪽 가지 탐색
            search(root->right, top, c1, c2);    //오른쪽 가지 탐색
        }
    }

public:
    node *root;  //1번 노드
    Tree(){
        root = new node;
        root = NULL;
    };

    void insert_node(char top, char c1, char c2){
        if(root == NULL){
            root = new node(top);
            if(c1 != '.'){
                root->left = new node(c1);
            }
            if(c2 != '.'){
                root->right = new node(c2);
            }
        }
        else{
            check = 0;
            search(root, top, c1, c2);
        }
    }

    void preorder(node *root){
        if(root != NULL){
            cout << root->top;
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(node *root){
        if(root != NULL){
            inorder(root->left);
            cout << root->top;
            inorder(root->right);
        }
    }

    void postorder(node *root){
        if(root != NULL){
            postorder(root->left);
            postorder(root->right);
            cout << root->top;
        }
    }

};

int main(){
    int N;
    char top, c1, c2;
    cin >> N;
    Tree my_tree;

    for(int i = 0; i < N; i++){
        cin >> top >> c1 >> c2;
        my_tree.insert_node(top, c1, c2);
    }

    my_tree.preorder(my_tree.root);
    cout << "\n";
    my_tree.inorder(my_tree.root);
    cout << "\n";
    my_tree.postorder(my_tree.root);
    return 0;
}
