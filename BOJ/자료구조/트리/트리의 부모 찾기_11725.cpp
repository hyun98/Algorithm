#include <iostream>
#include <vector>
using namespace std;

vector<int> *tree;
vector<int> visited, result;
int N, x, y;

void DFS(int tag){
    if(visited[tag] == 1){
        return;
    }

    visited[tag] = 1;
    for(int i = 0; i < tree[tag].size(); i++){
        int next = tree[tag][i];

        if(visited[next] == 0){
            result[next] = tag;
            DFS(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    tree = new vector<int> [N+1];
    visited.resize(N+1, 0);
    result.resize(N+1, 0);

    for(int i = 1; i < N; i++){
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    DFS(1);

    for(int i = 2; i < N+1; i++){
        cout << result[i] <<"\n";
    }
    delete[] tree;
    return 0;
}
