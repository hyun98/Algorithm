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

int N, M, s, t;
vector<pii > adj[5001];
int dist[5001];

void input(){
    cin >> N >> M;
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> s >> t;
    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }
}

void solve(){
    priority_queue<pii, vector<pii >, greater<pii > > pq;
    pq.push({0, s});
    dist[s] = 0;
    
    while(!pq.empty()){
        int now = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();
        
        if(now_cost > dist[now]) continue;
        
        if(now == t){
            cout << now_cost << "\n";
            return;
        }
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].second;
            int next_cost = now_cost + adj[now][i].first;
            
            if(next_cost < dist[next]){
                dist[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
