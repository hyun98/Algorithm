#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e18
#define pii pair<int, int>
typedef long long ll;
#define pll pair<ll, ll>
// typedef pair<int, int> pii;

using namespace std;

ll N, M, K, idx;
vector<ll> interview_place;
vector<pll > adj[100001];
ll dist[100001];

void input(){
    cin >> N >> M >> K;
    ll u, v, c;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        adj[v].push_back({c, u});
    }
    for(int i = 0; i < K; i++){
        cin >> u;
        interview_place.push_back(u);
    }
    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }
}

void solve(){
    ll max_cost = 0;
    priority_queue<pll, vector<pll >, greater<pll > > pq;
    for(auto &w: interview_place){
        pq.push({0, w});
        dist[w] = 0;
    }
    
    while(!pq.empty()){
        ll now = pq.top().second;
        ll now_cost = pq.top().first;
        pq.pop();
        
        if(dist[now] < now_cost) continue;
        
        for(int i = 0; i < adj[now].size(); i++){
            ll next = adj[now][i].second;
            ll next_cost = adj[now][i].first + now_cost;
            
            if(dist[next] > next_cost){
                pq.push({next_cost, next});
                dist[next] = next_cost;
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(max_cost < dist[i]){
            idx = i;
            max_cost = dist[i];
        }
    }
    cout << idx << "\n" << max_cost << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
