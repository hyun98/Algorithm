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
int Map[1001][1001];
int dist[1001][1001][11];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

struct P{
    int r, c, movecnt, wallcnt, daynight; // 1 is day, -1 is night
};

void input(){
    cin >> N >> M >> K;
    memset(Map, -1, sizeof(Map));
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            Map[i][j] = str[j] - '0';
        }
    }
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            for(int k = 0; k < 11; k++){
                dist[r][c][k] = INF;
            }
        }
    }
}

void bfs(){
    queue<P> que;
    que.push({0, 0, 1, 0, 1});
    dist[0][0][0] = 1;
    
    while(!que.empty()){
        int now_r = que.front().r;
        int now_c = que.front().c;
        int now_move = que.front().movecnt;
        int now_wall = que.front().wallcnt;
        int now_daynight = que.front().daynight;
        que.pop();
        
        if(now_r == N-1 && now_c == M-1){
            cout << now_move;
            return;
        }
        
        for(int k = 0; k < 4; k++){
            int nr = now_r + dr[k];
            int nc = now_c + dc[k];
            int nd = (now_daynight == 0 ? 1:0);
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            
            // 벽을 부술 수 있을 때 (현재 낮)
            if(Map[nr][nc] && now_daynight){
                if(now_wall+1 <= K && dist[nr][nc][now_wall+1] > now_move+1){
                    dist[nr][nc][now_wall+1] = now_move+1;
                    que.push({nr, nc, now_move+1, now_wall+1, nd});
                }
            }
            // 벽을 앞에 두고 기다릴 때 (현재 밤)
            if(Map[nr][nc] && !now_daynight){
                que.push({now_r, now_c, now_move+1, now_wall, nd});
            }
            
            // 열린 공간일 때
            if(!Map[nr][nc]){
                if(dist[nr][nc][now_wall] > now_move+1){
                    dist[nr][nc][now_wall] = now_move+1;
                    que.push({nr, nc, now_move+1, now_wall, nd});
                }
            }
        }
    }
    cout << -1;
}

int main(){
    fastio
    input();
    bfs();
    
    return 0;
}
