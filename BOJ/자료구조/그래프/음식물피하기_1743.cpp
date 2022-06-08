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

int N, M, K;
int Map[101][101];
bool visited[101][101];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int answer;

void input(){
    cin >> N >> M >> K;
    int a, b;
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        Map[a-1][b-1] = 1;
    }
    memset(visited, 0, sizeof(visited));
}

int bfs(int r, int c){
    int ret = 1;
    
    queue<pii > que;
    que.push({r, c});
    visited[r][c] = true;
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(!Map[nr][nc] || visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            ret++;
            que.push({nr, nc});
        }
    }
    
    return ret;
}

void solve(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(!visited[r][c] && Map[r][c]){
                answer = max(answer, bfs(r, c));
            }
        }
    }
    cout << answer;
}

int main(){
    input();
    solve();
    
    return 0;
}
