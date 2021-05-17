#include <iostream>
#include <vector>
using namespace std;

struct T{
    int visit = 0;
    vector<int> country;
};

void DFS(int node, vector<T> &tree, int &cnt){
    if(tree[node].visit == 1){
        cnt--;
        return;
    }

    tree[node].visit = 1;

    for(int i = 0; i < tree[node].country.size(); i++){
        int next = tree[node].country[i];
        cnt++;
        DFS(next, tree, cnt);
    }
}

void input(){
    int N, M, cnt = 0, a, b;
    vector<T> tree;
    T temp;
    tree.resize(1001, temp);
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        tree[a].country.push_back(b);
        tree[b].country.push_back(a);
    }
    DFS(b, tree, cnt);
    cout << cnt <<"\n";
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        input();
    }
    return 0;
}
