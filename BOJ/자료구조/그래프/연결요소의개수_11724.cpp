#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> Graph[1001];
bool visited[1001];

void dfs(int now){
    visited[now] = true;
    
    for(int i = 0; i < Graph[now].size(); i++){
        int next = Graph[now][i];
        if(visited[next]) continue;
        dfs(next);
    }
}

void solve(){
    int res = 0;
    for(int i = 1; i <= N; i++){
        if(visited[i]) continue;
        dfs(i);
        res++;
    }
    cout << res;
}

void input(){
    int u, v;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    solve();
    
    return 0;
}
