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

int N;
int Map[126][126];
int dist[126][126];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void input(){
    cin >> N;
    memset(Map, 0, sizeof(Map));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
            Map[i][j] *= -1;
            dist[i][j] = -INF;
        }
    }
    if(!N) exit(0);
}

void Dijkstra(){
    priority_queue<pair<int, pii > > pq;
    pq.push({Map[0][0], {0, 0}});
    
    while(!pq.empty()){
        pii now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(now.first == N-1 && now.second == N-1) return;
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            int next_cost = cost + Map[nr][nc];
            if(dist[nr][nc] < next_cost){
                dist[nr][nc] = next_cost;
                pq.push({next_cost, {nr, nc}});
            }
        }
    }
}

void solve(int i){
    Dijkstra();
    cout << "Problem " << i << ": " << -dist[N-1][N-1] << "\n";
}

int main(){
    fastio
    int i = 1;
    while(true){
        input();
        solve(i++);
    }
    
    return 0;
}
