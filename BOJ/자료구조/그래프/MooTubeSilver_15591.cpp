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

int N, Q;

vector<pii > adj[5001];

void input(){
    cin >> N >> Q;
    int p, q, r;
    for(int i = 0; i < N-1; i++){
        cin >> p >> q >> r;
        adj[p].push_back({r, q});
        adj[q].push_back({r, p});
    }
}

int bfs(int k, int v){
    int cnt = 0;
    
    bool visited[5001];
    memset(visited, 0, sizeof(visited));
    visited[v] = true;
    
    queue<int> que;
    que.push(v);
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].second;
            int next_road = adj[now][i].first;
            
            if(visited[next]) continue;
            if(next_road < k) continue;
            
            cnt++;
            visited[next] = true;
            que.push(next);
        }
    }
    
    return cnt;
}

void solve(){
    int k, v;
    for(int i = 0; i < Q; i++){
        cin >> k >> v;
        cout << bfs(k, v) << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
