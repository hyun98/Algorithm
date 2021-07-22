#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, D, Leaf;
vector<int> tree[51];
int Node[51];
int Nodeleaf[51];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Node[i];
        if(Node[i] == -1) continue;
        tree[Node[i]].push_back(i);
        Nodeleaf[Node[i]]++;
    }
    cin >> D;
}

void dfs(int now){
    if(Node[now] == -2 ) return;
    
    if(!Nodeleaf[now]){
        Leaf++;
        return;
    }
    
    for(int i = 0; i < tree[now].size(); i++){
        int next = tree[now][i];
        dfs(next);
    }
}

void solve(){
    Nodeleaf[Node[D]]--;
    Node[D] = -2;
    
    for(int i = 0; i < N; i++){
        if(Node[i] == -1){
            dfs(i);
        }
    }
    cout << Leaf;
}

int main(){
    input();
    solve();
    
    return 0;
}
