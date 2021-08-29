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

int V, E, P;

vector<pii > adj[5001];
int dist[5001];

void input(){
    cin >> V >> E >> P;
    int a, b, c;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
}

int Dijkstra(int start, int end){
    for(int i = 0; i < 5001; i++){
        dist[i] = INF;
    }
    
    priority_queue<pii, vector<pii >, greater<pii> > pq;
    pq.push({0, start});
    
    while(!pq.empty()){
        int now = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();
        
        if(now == end) return now_cost;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].second;
            int next_cost = now_cost + adj[now][i].first;
            
            if(dist[next] > next_cost){
                dist[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }
    
    return INF;
}

void solve(){
    int min_to_masan = Dijkstra(1, V);
    int min_to_gun = Dijkstra(1, P);
    int gun_to_masan = Dijkstra(P, V);
    
    if(min_to_masan < min_to_gun + gun_to_masan) cout << "GOOD BYE\n";
    else cout << "SAVE HIM\n";
}

int main(){
    input();
    solve();
    
    return 0;
}
