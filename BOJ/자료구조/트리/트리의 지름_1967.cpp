#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int weight = 0;
    vector<node*> child;
};

vector<node*> tree;
vector<int> result {0, };
int N, p, c, w;

int find_diameter(node* root){
    if(root->child.empty()) return root->weight;

    vector<int> dist;

    for(int i = 0; i < root->child.size(); i++){
        dist.push_back(find_diameter(root->child[i]));
    }

    sort(dist.begin(), dist.end());

    if(dist.size() >= 2){
        result.push_back(dist[dist.size()-2] + dist[dist.size()-1]);
    }
    else{
        result.push_back(dist.back() + root->weight);
    }

    return dist.back() + root->weight;
}

void make_tree(){
    cin >> N;
    node* temp;
    tree.resize(N+1, temp);
    for(int i = 0; i < N+1; i++){
        tree[i] = new node;
    }

    for(int i = 1; i < N; i++){
        cin >> p >> c >> w;
        tree[c]->weight = w;
        tree[p]->child.push_back(tree[c]);
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    make_tree();
    N = find_diameter(tree[1]);
    sort(result.begin(), result.end());
    cout << result.back();

    return 0;
}
