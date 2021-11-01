#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 2e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M, K;
vector<pii > adj[1001];
vector<int> dist[1001];

void input(){
    cin >> N >> M >> K;
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
}

struct cmp{
    bool operator()(pii &a, pii &b){
        return a.first > b.first;
    }
};

void dijkstra(){
    priority_queue<pii, vector<pii >, cmp> pq; 
    pq.push({0, 1});
    
    while(!pq.empty()){
        int now = pq.top().second;
        int now_time = pq.top().first;
        pq.pop();
        
        dist[now].push_back(now_time);
        if(dist[now].size() > K) continue;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].second;
            int next_time = now_time + adj[now][i].first;
            
            pq.push({next_time, next});
        }
    }
}

void solve(){
    dijkstra();
    for(int i = 1; i <= N; i++){
        // sort(dist[i].begin(), dist[i].end());
        if(dist[i].size() < K) cout << -1 << "\n";
        else cout << dist[i][K-1] << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
