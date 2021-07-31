#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define MAX 2002
typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M;
int capacity[MAX][MAX], flow[MAX][MAX];
vector<int> adj[MAX];

void input(){
    cin >> N >> M;
    int a, w;
    for(int i = 2; i <= N+1; i++){
        cin >> a;
        adj[0].push_back(i);
        adj[i].push_back(0);
        capacity[0][i] = 1;
        for(int k = 0; k < a; k++){
            cin >> w;
            adj[i].push_back(w+1+N);
            adj[w+1+N].push_back(i);
            capacity[i][w+1+N] = capacity[w+1+N][i] = 1;
        }
    }
    for(int i = 2+N; i < M+2+N; i++){
        adj[1].push_back(i);
        adj[i].push_back(1);
        capacity[i][1] = 1;
    }
}

int MaxFlow(int source, int sink){
    int total_flow = 0;
    
    while(true){
        vector<int> prev(MAX, -1);
        queue<int> que;
        que.push(source);
        prev[source] = source;
        
        while(!que.empty() && prev[sink] == -1){
            int now = que.front();
            que.pop();
            
            for(int i = 0; i < adj[now].size(); i++){
                int next = adj[now][i];
                if(capacity[now][next] - flow[now][next] > 0 && prev[next] == -1){
                    prev[next] = now;
                    que.push(next);
                }
            }
        }
        if(prev[sink] == -1) break;
        
        int amount = INF;
        
        for(int p = sink; p != source; p = prev[p]){
            amount = min(amount, capacity[prev[p]][p] - flow[prev[p]][p]);
        }
        for(int p = sink; p != source; p = prev[p]){
            flow[prev[p]][p] += amount;
            flow[p][prev[p]] -= amount;
        }
        total_flow += amount;
    }
    return total_flow;
}

void solve(){
    cout << MaxFlow(0, 1);
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
