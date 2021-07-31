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

int v, M;
int capacity[701][701], flow[701][701];
vector<int> adj[701];
int visited[701];

void input(){
    cin >> v >> M;
    int u, v, c;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = capacity[v][u] += c;
    }
}

void networkFlow(int source, int sink){
    int totalFlow = 0;
    
    while(true){
        memset(visited, -1, sizeof(visited));
        queue<int> que;
        visited[source] = source;
        que.push(source);
        
        while(!que.empty() && visited[sink] == -1){
            int now = que.front();
            que.pop();
            
            for(int i = 0; i < adj[now].size(); i++){
                int next = adj[now][i];
                if(capacity[now][next] - flow[now][next] > 0 && visited[next] == -1){
                    que.push(next);
                    visited[next] = now;
                    if(next == sink) break;
                }
            }
        }
        if(visited[sink] == -1) break;
        
        int amount = INF;
        int mu, mv;
        cout << "\nsink return : ";
        for(int i = sink; i != source; i = visited[i]){
            cout << i << " ";
            // amount = min(amount, capacity[visited[i]][i] - flow[visited[i]][i]);
            if(capacity[visited[i]][i] - flow[visited[i]][i] < amount){
                mu = visited[i];
                mv = i;
                amount = capacity[visited[i]][i] - flow[visited[i]][i];
            }
        }
        cout << source << "\n";
        cout << "min amount&Edge : "<< amount << ", " << mu << "->" << mv << "\n";
        cout << "flow setting\n";
        for(int i = sink; i != source; i = visited[i]){
            flow[visited[i]][i] += amount;
            flow[i][visited[i]] -= amount;
            cout << visited[i] << " -> " << i << " : " << flow[visited[i]][i] << "/" << capacity[visited[i]][i];
            cout << "\n";
            cout << i << " -> " << visited[i] << " : " << flow[i][visited[i]] << "/" << capacity[i][visited[i]];
            cout << "\n-----\n";
        }
        
        totalFlow += amount;
    }
    
    cout << "totalFlow : " << totalFlow << "\n";
}

void solve(){
    networkFlow(1, v);
}
// 8 11
// 1 2 3
// 2 6 3
// 6 8 5
// 1 3 4
// 3 6 2
// 1 4 5
// 4 7 7
// 7 8 4
// 7 6 1
// 2 5 1
// 5 8 3
int main(){
    input();
    solve();
    
    return 0;
}
