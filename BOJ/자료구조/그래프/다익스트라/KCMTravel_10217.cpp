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

// 시간을 가장 작게
void solve(){
    priority_queue<IF, vector<IF>, cmp> pq;
    pq.push({1, 0, 0});
    dist[1][0] = 0;
    
    while(!pq.empty()){
        int now = pq.top().dest;
        int now_cost = pq.top().cost;
        int now_time = pq.top().time;
        pq.pop();
        
        if(dist[now][now_cost] < now_time) continue;
        dist[now][now_cost] = now_time;
        
        if(now == N){
            cout << dist[now][now_cost] << "\n";
            return;
        }
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].dest;
            int next_cost = adj[now][i].cost + now_cost;
            int next_time = adj[now][i].time + now_time;
            
            if(next_cost > M) continue;
            pq.push({next, next_cost, next_time});
        }
    }
    
    cout << "Poor KCM\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        input();
        solve();
    }
    
    return 0;
}
