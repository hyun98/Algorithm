#include <iostream>
#include <queue>

#define pii pair<int, int>
using namespace std;

struct P{
    int r, c;
    int k;
    int cnt;
};

int K, W, H;
int Map[201][201];
bool visited[201][201][31];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
int hr[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int hc[8] = {-2, 2, -1, 1, -2, 2, -1, 1};

void BFS(){
    int cnt = 0;
    
    queue<P> que;
    que.push({0, 0, 0, 0});
    for(int i = 0; i <= K; i++){
        visited[0][0][i] = true;
    }
    
    while(!que.empty()){
        P now = que.front();
        que.pop();
        
        if(now.r == H-1 && now.c == W-1){
            cout << now.cnt << "\n";
            return;
        }
        
        if(now.k < K){
            for(int i = 0; i < 8; i++){
                int nr = now.r + hr[i];
                int nc = now.c + hc[i];
                
                // 말 처럼 k+1번 이동했을 때 방문하지 않았다면
                if(nr < 0 || nr >= H || nc < 0 || nc >= W || Map[nr][nc] || visited[nr][nc][now.k+1]) continue;
                visited[nr][nc][now.k+1] = true;
                que.push({nr, nc, now.k+1, now.cnt+1});
            }
        }
        
        for(int i = 0; i < 4; i++){
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            
            // 말 처럼 k번 이동했을 때 방문하지 않았다면 
            if(nr < 0 || nr >= H || nc < 0 || nc >= W || Map[nr][nc] || visited[nr][nc][now.k]) continue;
            visited[nr][nc][now.k] = true;
            que.push({nr, nc, now.k, now.cnt+1});
        }
    }
    cout << -1;
}

void input(){
    cin >> K >> W >> H;
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> Map[i][j];
        }
    }
}

int main(){
    input();
    BFS();
    return 0;
}
