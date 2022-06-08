#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M, K, X;
vector<int> adj[300001];
int dist[300001];
set<int> answer;

void input(){
    cin >> N >> M >> K >> X;
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for(int i = 0; i <= N; i++){
        dist[i] = INF;
    }
}

void dijkstra(){
    priority_queue<pii, vector<pii >, greater<pii > > pq;
    pq.push({0, X});
    dist[X] = 0;
    
    while(!pq.empty()){
        int now = pq.top().second;
        int nowCost = pq.top().first;
        pq.pop();
        
        if(nowCost > dist[now]) continue;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i];
            int nextCost = nowCost + 1;
            
            if(nextCost < dist[next]){
                if(nextCost == K){
                    answer.insert(next);
                }
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
}

void solve(){
    dijkstra();
    if(answer.empty()) cout << -1;
    else{
        for(auto &a: answer){
            cout << a << '\n';
        }
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
