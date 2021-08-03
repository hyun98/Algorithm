#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define LINF 1e15
#define pii pair<int, int>
typedef long long ll;
#define pil pair<int ,ll>
// typedef pair<int, int> pii;

using namespace std;

struct INFO{
    int city;
    ll cost;
    int min_ppl; // price per liter
};

struct cmp{
    bool operator()(INFO &a, INFO &b){
        return a.cost > b.cost;
    }
};

int N, M;
int price[2501];
ll dist[2501][2501];
vector<pil > adj[2501];

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> price[i];
    }
    int u, v, c;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    memset(dist, -1, sizeof(dist));
}

void solve(){
    ll res = LINF;
    priority_queue<INFO, vector<INFO>, cmp> pq;
    pq.push({1, 0, price[1]});
    
    while(!pq.empty()){
        int now = pq.top().city;
        ll now_cost = pq.top().cost;
        int now_ppl = pq.top().min_ppl;
        pq.pop();
        
        if(dist[now][now_ppl] != -1) continue;
        dist[now][now_ppl] = now_cost;
        
        if(now == N){
            cout << now_cost << "\n";
            return;
        }
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            ll next_cost = now_cost + adj[now][i].second * now_ppl;
            int next_ppl = min(now_ppl, price[next]);
            
            if(dist[next][next_ppl] != -1) continue;
            pq.push({next, next_cost, next_ppl});
        }
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
