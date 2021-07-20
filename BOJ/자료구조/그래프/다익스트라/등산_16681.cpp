#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e13+7

typedef long long ll;
#define pii pair<ll, int>
// typedef pair<int, int> pii;

using namespace std;

int N, M, D, E;
long long Height[100001];
vector<pii > Route[100001];
ll dist[100001][2];
long long Value;

void input(){
    cin >> N >> M >> D >> E;
    for(int i = 1; i <= N; i++){
        cin >> Height[i];
    }
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        Route[a].push_back({c, b});
        Route[b].push_back({c, a});
    }
    for(int i = 0; i <= N; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
}

void Dijkstra(int st, int k){
    priority_queue<pii, vector<pii >, greater<pii > > pque;
    pque.push({0, st});
    dist[st][k] = 0;
    
    while(!pque.empty()){
        int now_idx = pque.top().second;
        ll min_cost = pque.top().first;
        pque.pop();
        
        if(min_cost > dist[now_idx][k]){
            continue;
        }
        
        for(int i = 0; i < Route[now_idx].size(); i++){
            int next = Route[now_idx][i].second;
            ll next_cost = Route[now_idx][i].first + min_cost;
            if(dist[next][k] > next_cost && Height[next] > Height[now_idx]){
                dist[next][k] = next_cost;
                pque.push({next_cost, next});
            }
        }
    }
}

void drive_answer(){
    ll maxi = -INF * 100000;
    for(int i = 1; i <= N; i++){
        maxi = max(maxi, Height[i]*E - D * (dist[i][0] + dist[i][1]));
    }
    
    if(maxi == -INF * 100000) cout << "Impossible" << '\n';
    else cout << maxi << '\n';
}

void solve(){
    // 시작점에서 다익스트라
    Dijkstra(1, 0);
    // 도착점에서 다익스트라
    Dijkstra(N, 1);
    
    drive_answer();
}

int main(){
    input();
    solve();
    
    return 0;
}
