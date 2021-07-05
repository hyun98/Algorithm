#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

const int INF = 1e9+7;
int V, E, n, m;
vector<vector<pii > > Map;
vector<int> firehouse, dist;

void input(){
    int a, b, t;
    cin >> V >> E >> n >> m;
    
    Map = vector<vector<pii > >(V + 1);
    firehouse = vector<int>();
    dist.resize(V+1, INF);
    
    for(int i = 0; i < E; i++){
        cin >> a >> b >> t;
        Map[a].push_back({t, b});
        Map[b].push_back({t, a});
    }
    for(int i = 0; i < n; i++){
        cin >> a;
        firehouse.push_back(a);
    }
    for(int i = 0; i < m; i++){
        cin >> a;
        Map[0].push_back({0, a});
    }
}

void Dijstra(){
    priority_queue<pii, vector<pii >, greater<pii > > que;
    
    dist[0] = 0;
    que.push({0, 0});
    
    while(!que.empty()){
        int now = que.top().second;
        int min_cost = que.top().first;
        que.pop();
        
        if(min_cost > dist[now]) continue;

        for(int i = 0; i < Map[now].size(); i++){
            int next = Map[now][i].second;
            int next_cost = min_cost + Map[now][i].first;
            
            if(next_cost < dist[next]){
                dist[next] = next_cost;
                que.push({next_cost, next});
            }
        }
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int res = 0;
        input();
        Dijstra();
        
        for(int i = 0; i < firehouse.size(); i++){
            res += dist[firehouse[i]];
        }
        cout << res << "\n";
    }
    
    return 0;
}
