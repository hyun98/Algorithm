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

struct T{
    int cost, ed, prev;
};

struct cmp{
    bool operator()(T &a, T &b){
        return a.cost > b.cost;
    }
};

int N, M;
vector<pii > adj[1001];
vector<pii > rebuild;
int dist[1001];

void input(){
    cin >> N >> M;
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }
}

void Dijkstra(){
    priority_queue<T, vector<T>, cmp> que;
    que.push({0, 1, 0});
    dist[1] = 0;
    
    int prev = 1;
    
    while(!que.empty()){
        T now = que.top();
        que.pop();
        
        if(now.cost > dist[now.ed]) continue;
        
        if(now.prev){
            rebuild.push_back({now.prev, now.ed});
        }
        
        for(int i = 0; i < adj[now.ed].size(); i++){
            int next = adj[now.ed][i].second;
            int next_cost = adj[now.ed][i].first + now.cost;
            
            if(next_cost < dist[next]){
                dist[next] = next_cost;
                que.push({next_cost, next, now.ed});
            }
        }
    }
}

void solve(){
    Dijkstra();
    
    cout << rebuild.size() << "\n";
    for(auto &w : rebuild){
        cout << w.first << " " << w.second << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
