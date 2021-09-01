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

int N, P, K;
vector<pii > adj[1001];
int freecnt[1001];

void input(){
    cin >> N >> P >> K;
    int u, v, c;
    for(int i = 0; i < P; i++){
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
}

bool Dijkstra(int bound){
    for(int i = 0; i < 1001; i++){
        freecnt[i] = INF;
    }
    priority_queue<pii, vector<pii >, greater<pii > > pq;
    pq.push({0, 1});
    freecnt[1] = 0;
    
    while(!pq.empty()){
        int now = pq.top().second;
        int cnt = pq.top().first;
        pq.pop();
        
        if(cnt > K) continue;
        if(now == N) return true;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].second;
            int next_cost = adj[now][i].first;
            int next_cnt = next_cost > bound? cnt+1 : cnt;
            
            if(freecnt[next] <= next_cnt) continue;
            freecnt[next] = next_cnt;
            pq.push({next_cnt, next});
        }
    }
    
    return false;
}

void solve(){
    int res = -1;
    int lo = 0;
    int hi = 1e6;
    int mid, tres;
    
    while(lo <= hi){
        mid = (lo + hi) / 2;
        
        if(Dijkstra(mid)){
            res = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    
    cout << res;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
