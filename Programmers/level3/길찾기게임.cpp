#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

#define pii pair<int, int>

using namespace std;

struct Info{
    int idx, x, y;
};

struct Node{
    int idx;
    int x = -1, y = -1;
    Node *left;
    Node *right;
};

void insertNode(Node *root, Info info){
    if(root->x == -1 && root->y == -1){
        root->x = info.x;
        root->y = info.y;
        root->idx = info.idx;
        root->left = new Node;
        root->right = new Node;
        return;
    }

    if(root->x > info.x) insertNode(root->left, info);
    else insertNode(root->right, info);
}

void preorder(Node *root, vector<int> &order){
    if(root->x == -1 && root->y == -1) return;
    order.push_back(root->idx);
    preorder(root->left, order);
    preorder(root->right, order);
    
}

void postorder(Node *root, vector<int> &order){
    if(root->x == -1 && root->y == -1) return;
    postorder(root->left, order);
    postorder(root->right, order);
    order.push_back(root->idx);
}

bool cmp(Info &a, Info &b){
    return a.y > b.y;
}

Node *root;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    root = new Node;
    
    vector<Info> temp;
    for(int i = 0; i < nodeinfo.size(); i++){
        temp.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    
    for(int i = 0; i < temp.size(); i++){
        insertNode(root, temp[i]);
    }
    
    vector<int> pre, post;
    preorder(root, pre);
    postorder(root, post);
    
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}