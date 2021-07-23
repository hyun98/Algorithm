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

int N, M;
vector<int> tree[100001];
int depth[100001];
int parent[100001][20];

vector<pii > Query;
bool visited[100001];

void input(){
    cin >> N;
    int a, b;
    for(int i = 0; i < N-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        Query.push_back({a, b});
    }
}

void tree_dfs(int now, int d){
    visited[now] = true;
    depth[now] = d;
    
    for(int i = 0; i < tree[now].size(); i++){
        int next = tree[now][i];
        if(visited[next]) continue;
        parent[next][0] = now;
        tree_dfs(next, d+1);
    }
}

void mkparent(){
    parent[1][0] = 0;
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= N; j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}

int LCA(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    
    // 더 깊이 있는 b를 최대한 a근처로 끌어올림.
    for(int i = 19; i >= 0; i--){
        if(depth[b] - depth[a] >= (1 << i)){
            b = parent[b][i];
        }
    }
    
    if(a == b) return a;
    
    for(int i = 19; i >= 0; i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

void solve(){
    tree_dfs(1, 0);
    mkparent();
    
    for(auto &w : Query){
        cout << LCA(w.first, w.second) << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
