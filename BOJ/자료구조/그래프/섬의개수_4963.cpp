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

int W, H;
int Map[51][51];
bool visited[51][51];

int dr[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dc[8] = {1, -1, 0, 0, -1, 1, -1, 1};

void bfs(int r, int c){
    
    queue<pii > que;
    que.push({r, c});
    
    visited[r][c] = true;
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        for(int i = 0; i < 8; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            
            if(visited[nr][nc]) continue;
            if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            
            if(Map[nr][nc]){
                visited[nr][nc] = true;
                que.push({nr, nc});
            }
        }
    }
}

void solve(){
    for(int r = 0; r < H; r++){
        for(int c = 0; c < W; c++){
            cin >> Map[r][c];
        }
    }
    
    int ret = 0;
    
    memset(visited, 0, sizeof(visited));
    
    for(int r = 0; r < H; r++){
        for(int c = 0; c < W; c++){
            if(visited[r][c]) continue;
            if(Map[r][c]){
                bfs(r, c);
                ret++;
            }
        }
    }
    
    cout << ret << '\n';
}

int main(){
    while(true){
        cin >> W >> H;
        if(!W && !H) return 0;
        solve();
    }
    
    return 0;
}
