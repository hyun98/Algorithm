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

struct IF{
    int dest, cost, time;
};

int N, M, K;
vector<IF> adj[10001];
int dist[101][10001];

void input(){
    for(int i = 0; i < 10001; i++){
        adj[i].clear();
    }
    
    cin >> N >> M >> K;
    int u, v, c, d;
    for(int i = 0; i < K; i++){
        cin >> u >> v >> c >> d;
        adj[u].push_back({v, c, d});
    }
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j < 10001; j++){
            dist[i][j] = INF;
        }
    }
}

struct cmp{
    bool operator()(IF &a, IF &b){
        return a.cost > b.cost;
    }
};

void solve(){
    priority_queue<IF, vector<IF>, cmp> pq;
    pq.push({1, 0, 0});
    dist[1][0] = 0;
    
    while(!pq.empty()){
        int now = pq.top().dest;
        int now_cost = pq.top().cost;
        int now_time = pq.top().time;
        pq.pop();
        
        if(dist[now][now_cost] < now_time || now_cost > M) continue;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].dest;
            int next_cost = adj[now][i].cost + now_cost;
            int next_time = adj[now][i].time + now_time;
            
            if(dist[next][next_cost] <= next_time || next_cost > M) continue;
            dist[next][next_cost] = next_time;
            pq.push({next, next_cost, next_time});
            
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        input();
        solve();
        int res = INF;
        for(int i = 1; i <= M; i++){
            res = min(res, dist[N][i]);
        }
        if(res != INF) cout << res << "\n";
        else cout << "Poor KCM\n";
    }
    
    return 0;
}
