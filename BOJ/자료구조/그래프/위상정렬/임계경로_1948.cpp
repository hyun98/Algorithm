#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int, int>

using namespace std;

int N, M, S, E, roadcnt;
vector<pii > graph[10001][2];

// 정점에 도달하는 시간
int time[10001];

void input(){
    cin >> N >> M;
    int u, v, c;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        graph[u][0].push_back({v, c});
        graph[v][1].push_back({u, c});
    }
    cin >> S >> E;
}

void bfs(int k){
    queue<int> que;
    que.push(S);
    time[S] = 0;
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        
        for(int i = 0; i < graph[now][k].size(); i++){
            int next = graph[now][k][i].first;
            int next_time = graph[now][k][i].second + time[now];
            
            if(time[next] < next_time){
                time[next] = next_time;
                que.push(next);
            }
        }
    }
}

void rev_bfs(int k){
    queue<pii > que;
    que.push({E, 0});
    
    bool visited[10001];
    memset(visited, 0, sizeof(visited));
    visited[E] = true;
    
    while(!que.empty()){
        int now = que.front().first;
        int now_time = que.front().second;
        que.pop();
        
        for(int i = 0; i < graph[now][k].size(); i++){
            int next = graph[now][k][i].first;
            int next_time = graph[now][k][i].second + now_time;
            
            if(time[E] - next_time == time[next]){
                if(!visited[next]){
                    visited[next] = true;
                    roadcnt++;
                    que.push({next, next_time});
                }
                else roadcnt++;
            }
        }
    }
}

int main(){
    fastio
    input();
    bfs(0);
    rev_bfs(1);
    cout << time[E] << "\n" << roadcnt;
    
    return 0;
}
