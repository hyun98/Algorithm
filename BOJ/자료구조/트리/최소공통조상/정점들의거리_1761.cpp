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
vector<pii > tree[40001];
int depth[40001];
pii parent[40001][18];

vector<pii > Query;
bool visited[40001];

void input(){
    cin >> N;
    int a, b, d;
    for(int i = 0; i < N-1; i++){
        cin >> a >> b >> d;
        tree[a].push_back({b, d});
        tree[b].push_back({a, d});
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
        int next = tree[now][i].first;
        if(visited[next]) continue;
        parent[next][0] = {now, tree[now][i].second};
        tree_dfs(next, d+1);
    }
}

void mkparent(){
    parent[1][0] = {0, 0};
    for(int i = 1; i <= 17; i++){
        for(int j = 1; j <= N; j++){
            parent[j][i] = {parent[parent[j][i-1].first][j-1].first, \
                            parent[j][i-1].second + parent[parent[j][i-1].first][i-1].second};
        }
    }
}

int LCA_dist(int a, int b){
    int dist = 0;
    if(depth[a] > depth[b]) swap(a, b);
    
    for(int i = 17; i >= 0; i--){
        if(depth[b] - depth[a] >= (1 << i)){
            dist += parent[b][i].second;
            b = parent[b][i].first;
        }
    }
    if(a == b) return dist;
    
    for(int i = 17; i >= 0; i--){
        if(!parent[a][i].first && !parent[b][i].first){
            dist += (parent[a][i].second + parent[b][i].second);
            a = parent[a][i].first;
            b = parent[b][i].first;
        }
    }
    return dist;
}

void solve(){
    tree_dfs(1, 0);
    mkparent();
    
    for(auto &w : Query){
        cout << LCA_dist(w.first, w.second) << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
