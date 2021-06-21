#include <iostream>

using namespace std;

template <typename T>
struct TreeNode{
    T label;
    vector<TreeNode*> children;
};

void printLabels(TreeNode* root){

    cout << root->label << endl;

    for(int i = 0; i < root->children.size(); i++){
        printLabels(root->children[i]);
    }
}

int height(TreeNode* root){
    int h = 0;
    for(int i = 0; i < root->children.size(); i++){
        h = max(h, 1 + height(root->children[i]));
    }

    return h;
}

int main(){

    return 0;
}
