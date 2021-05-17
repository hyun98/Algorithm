#include <iostream>
#include <vector>

using namespace std;

vector<int>* tree;
int *visit;
int leaf_num = 0, del;

void Search(int node){
    if(visit[node] == 1) return;

    visit[node] = 1;

    auto it = tree[node].begin();

    for(int i = 0; i < tree[node].size(); i++){
        if(tree[node][i] == del){
            tree[node].erase(it+i);
            i--;
        }
        else{
            int next = tree[node][i];
            Search(next);
        }
    }
    if(tree[node].size() == 0 && node != del){
        leaf_num++;
    }
}

int main(){
    int N, p, root;
    cin >> N;
    tree = new vector<int>[N+1];
    visit = new int[N+1] {0, };
    for(int i = 0; i < N; i++){
        cin >> p;
        if(p == -1) {
            root = i;
            continue;
        }
        tree[p].push_back(i);
    }
    cin >> del;
    tree[del].clear();
    Search(root);
    cout << leaf_num;
    return 0;
}
