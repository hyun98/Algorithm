#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define MAX 2005
typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M, K;
int capacity[MAX][MAX], flow[MAX][MAX];
vector<int> adj[MAX];

void input(){
    cin >> N >> M >> K;
    int a, b;
    adj[0].push_back(2); adj[2].push_back(0);
    capacity[0][2] = K;
    for(int i = 3; i < 3+N; i++){
        cin >> a;
        adj[0].push_back(i); adj[i].push_back(0);
        adj[2].push_back(i); adj[i].push_back(2);
        capacity[0][i] = capacity[2][i] = 1;
        for(int j = 0; j < a; j++){
            cin >> b;
            adj[i].push_back(2+N+b); adj[2+N+b].push_back(i);
            capacity[i][2+N+b] = 1;
        }
    }
    for(int i = 3+N; i < 3+N+M; i++){
        adj[i].push_back(1); adj[1].push_back(i);
        capacity[i][1] = 1;
    }
}

void MaxFlow(int source, int sink){
    int total_flow = 0;
    
    while(true){
        vector<int> prev(MAX, -1);
        queue<int> que;
        que.push(source);
        prev[source] = source;
        
        while(!que.empty() && prev[sink] == -1){
            int now = que.front();
            que.pop();
            
            for(int k = 0; k < adj[now].size(); k++){
                int next = adj[now][k];
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
    
    cout << total_flow << "\n";
}

int main(){
    fastio
    input();
    MaxFlow(0, 1);
    
    return 0;
}
