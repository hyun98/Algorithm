#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define NUM 2021

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M;
int capacity[NUM][NUM], flow[NUM][NUM];
vector<int> adj[NUM];

void input(){
    cin >> N >> M;
    int wn, w;
    for(int i = 2; i < N+2; i++){
        cin >> wn;
        adj[i].push_back(0);
        adj[0].push_back(i);
        capacity[0][i] = 2;
        for(int j = 0; j < wn; j++){
            cin >> w;
            adj[i].push_back(1+N+w);
            adj[1+N+w].push_back(i);
            capacity[i][1+N+w] = 1;
        }
    }
    for(int i = 0; i < M; i++){
        adj[1].push_back(2+N+i);
        adj[2+N+i].push_back(1);
        capacity[2+N+i][1] = 1;
    }
}

void solve(){
    int total_flow = 0;
    
    while(true){
        vector<int> prev(NUM, -1);
        queue<int> que;
        que.push(0);
        prev[0] = 0;
        
        while(!que.empty() && prev[1] == -1){
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
        if(prev[1] == -1) break;
        
        int amount = INF;
        for(int p = 1; p != 0; p = prev[p]){
            amount = min(amount, capacity[prev[p]][p] - flow[prev[p]][p]);
        }
        for(int p = 1; p != 0; p = prev[p]){
            flow[prev[p]][p] += amount;
            flow[p][prev[p]] -= amount;
        }
        
        total_flow += amount;
    }
    
    cout << total_flow << "\n";
}

int main(){
    input();
    solve();
    
    return 0;
}
