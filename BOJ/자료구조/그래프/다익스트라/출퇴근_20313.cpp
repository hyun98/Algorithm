#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e15
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

struct MS{
    ll cost;
    int node;
    int magic_cnt;
};

struct cmp{
    bool operator()(MS &a, MS &b){
        return a.cost > b.cost;
    }
};

int N, M, A, B, K;
vector<pii > adj[1001];
vector<ll> cost[101];
ll dist[1001][101];


void input(){
    cin >> N >> M >> A >> B;
    int u, v;
    ll t;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> t;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        cost[0].push_back(t);
    }
    
    cin >> K;
    for(int i = 1; i <= K; i++){
        for(int j = 0; j < M; j++){
            cin >> t;
            cost[i].push_back(t);
        }
    }
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 101; j++){
            dist[i][j] = INF;
        }
    }
}

void Dijkstra(){
    priority_queue<MS, vector<MS>, cmp> pq;
    pq.push({0, A, 0});
    
    while(!pq.empty()){
        ll now_cost = pq.top().cost;
        int now = pq.top().node;
        int mcnt = pq.top().magic_cnt;
        pq.pop();
        
        if(now_cost > dist[now][mcnt]) continue;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            int next_id = adj[now][i].second;
            
            // no magic
            if(dist[next][mcnt] > now_cost + cost[mcnt][next_id]){
                dist[next][mcnt] = now_cost + cost[mcnt][next_id];
                pq.push({dist[next][mcnt], next, mcnt});
            }
            // N times magic
            for(int j = 1; j + mcnt <= K; j++){
                if(dist[next][mcnt+j] > now_cost + cost[mcnt+j][next_id] && mcnt+j <= K){
                    dist[next][mcnt+j] = now_cost + cost[mcnt+j][next_id];
                    pq.push({dist[next][mcnt+j], next, mcnt+j});
                }
            }
        }
    }
}

void solve(){
    Dijkstra();
    
    ll answer = INF;
    for(int i = 0; i < 101; i++){
        answer = min(answer, dist[B][i]);
    }
    
    cout << answer << "\n";
}

int main(){
    input();
    solve();
    
    return 0;
}
