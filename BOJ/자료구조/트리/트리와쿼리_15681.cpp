#include <bits/stdc++.h>

using namespace std;

int N, R, Q;
vector<int> query, tree[100001];
bool visited[100001];
int dp[100001];

int dfs(int now){
    visited[now] = true;
    
    for(int i = 0; i < tree[now].size(); i++){
        int next = tree[now][i];
        if(visited[next]) continue;
        dp[now] += dfs(next);
    }
    
    return dp[now];
}

void input(){
    int u, v, q;
    cin >> N >> R >> Q;
    for(int i = 0; i < N-1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i = 0; i < Q; i++){
        cin >> q;
        query.push_back(q);
    }
    for(int i = 0; i <= N; i++){
        dp[i] = 1;
    }
}

int main(){
    input();
    dfs(R);
    
    for(auto w : query){
        cout << dp[w] <<  "\n";
    }
    
    return 0;
}