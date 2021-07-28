#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define Alphabet 100
typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N;
int capacity[Alphabet][Alphabet], flow[Alphabet][Alphabet];
vector<int> adj[Alphabet];


void input(){
    cin >> N;
    char a, b;
    int c;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        int u = a - 'A';
        int v = b - 'A';
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += c;
        capacity[v][u] += c;
    }
}

int MaxFlow(int source, int sink){
    int total_flow = 0;
    
    while(true){
        vector<int> parent(Alphabet, -1);
        queue<int> que;
        que.push(source);
        parent[source] = source;
        
        while(!que.empty() && parent[sink] == -1){
            int now = que.front();
            que.pop();
            
            for(int i = 0; i < adj[now].size(); i++){
                int next = adj[now][i];
                if(capacity[now][next] - flow[now][next] > 0 && parent[next] == -1){
                    que.push(next);
                    parent[next] = now;
                }
            }
        }
        
        if(parent[sink] == -1) break;
        
        int amount = INF;
        for(int p = sink; p != source; p = parent[p]){
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = sink; p != source; p = parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        
        total_flow += amount;
    }
    
    return total_flow;
}

void solve(){
    cout << MaxFlow(0, 25);
}

int main(){
    input();
    solve();
    
    return 0;
}
