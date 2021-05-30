#include <iostream>
#include <cstring>
#include <queue>
#define pii pair<int, int>

using namespace std;

int N, M, K;
int Map[51][51];
bool visited[51][51];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void BFS(int r, int c){
    queue<pii> que;
    que.push({r, c});
    visited[r][c] = true;
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            
            if(nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc] || Map[nr][nc] == 0) continue;
            else{
                que.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
}

void solve(){
    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] || Map[i][j] == 0) continue;
            BFS(i, j);
            res++;
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, x, y;
    cin >> t;
    while(t--){
        cin >> M >> N >> K;
        
        memset(Map, 0, sizeof(Map));
        memset(visited, 0, sizeof(visited));
        
        for(int b = 0; b < K; b++){
            cin >> x >> y;
            Map[y][x] = 1;
        }
        
        solve();
    }
    return 0;
}
