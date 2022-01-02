#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e15+7
typedef long long ll;
#define pli pair<ll, int>

using namespace std;

struct Edge{
    int kcnt;
    int dst;
    ll cost;
};

struct cmp{
    bool operator()(Edge &a, Edge &b){
        return a.cost > b.cost;
    }
};

int N, M, K;
vector<pli > adj[10001];
ll distTime[10001][21];

void input(){
    cin >> N >> M >> K;
    int u, v;
    ll c;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){
            distTime[i][j] = INF;
        }
    }
}

void printAns(){
    ll ans = INF;
    for(int i = 0; i <= K; i++){
        ans = min(ans, distTime[N][i]);
    }
    
    cout << ans;
}

void dijkstra(){
    priority_queue<Edge, vector<Edge>, cmp> pq;
    
    Edge new_edge;
    new_edge.cost = 0;
    new_edge.kcnt = 0;
    new_edge.dst = 1;
    
    pq.push(new_edge);
    
    // 1번에서 시작하므로 0
    distTime[1][0] = 0;
    
    while(!pq.empty()){
        int now = pq.top().dst;
        int kUse = pq.top().kcnt;
        ll now_cost = pq.top().cost;
        pq.pop();
        
        if(distTime[now][kUse] < now_cost) continue;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].second;
            ll next_cost = now_cost + adj[now][i].first;
            
            // 도로 건설하는 경우
            // 현재 비용 그대로 유지하면서 다음 도로로 이동.
            if(K > kUse && now_cost < distTime[next][kUse+1]){
                distTime[next][kUse+1] = now_cost;
                pq.push({kUse+1, next, now_cost});
            }
            
            // 그냥 비용이 감소할 때
            if(next_cost < distTime[next][kUse]){
                distTime[next][kUse] = next_cost;
                pq.push({kUse, next, next_cost});
            }
        }
    }
}

void solve(){
    dijkstra();
    printAns();
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
