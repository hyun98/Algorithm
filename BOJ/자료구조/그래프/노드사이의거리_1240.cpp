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
vector<pii > adj[1001];
vector<pii > Mlist;

void input(){
    cin >> N >> M;
    int u, v, d;
    for(int i = 0; i < N-1; i++){
        cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }
    
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        Mlist.push_back({u, v});
    }
}


int bfs(int S, int E){
    queue<pii > que;
    bool visited[1001];
    que.push({0, S});
    memset(visited, 0, sizeof(visited));
    visited[S] = true;
    
    while(!que.empty()){
        int now = que.front().second;
        int dist = que.front().first;
        que.pop();
        
        if(now == E){
            return dist;
        }
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].second;
            int next_dist = adj[now][i].first + dist;
            
            if(!visited[next]){
                visited[next] = true;
                que.push({next_dist, next});
            }
        }
    }
    return -1;
}

void solve(){
    for(auto &w: Mlist){
        cout << bfs(w.first, w.second) << '\n';
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
