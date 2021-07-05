#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;


int N, M, S, E;
const int INF = 1e9+7;
vector<pii > graph[1001]; 
vector<int> dist;

void input(){
    int u, v, c;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(c, v));
    }
    cin >> S >> E;
    
    dist.resize(N+1, INF);
}

void Dijstra(){
    dist[S] = 0;
    
    priority_queue<pii, vector<pii >, greater<pii > > que;
    que.push({0, S});
    
    while(!que.empty()){
        int min_cost = que.top().first;
        int now = que.top().second;
        que.pop();
        
        if(min_cost > dist[now]) continue;
        
        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].second;
            int next_cost = min_cost + graph[now][i].first;
            
            if(next_cost < dist[next]){
                dist[next] = next_cost;
                que.push({next_cost, next});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    Dijstra();
    cout << dist[E];
    
    return 0;
}