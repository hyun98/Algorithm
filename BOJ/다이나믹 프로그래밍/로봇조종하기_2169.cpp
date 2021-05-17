#include <iostream>
#include <cstring>
using namespace std;

const int minINF = -1000000;

int N, M;
int dr[3] = {0, 0, 1};  //right left down
int dc[3] = {1, -1, 0};

int Map[1001][1001];
int dp[1001][1001][3];
bool visited[1001][1001];

void input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
            for(int k = 0; k < 3; k++){
                dp[i][j][k] = minINF;
            }
        }
    }
    
    memset(visited, false, sizeof(visited));
}

int CheckRoute(int r, int c, int dir){
    if(r == N-1 && c == M-1) return Map[r][c];
    
    int &ret = dp[r][c][dir];
    if(ret != minINF) return ret;
    ret = minINF;
    
    visited[r][c] = true;
    
    for(int i = 0; i < 3; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 && nr < N && nc >= 0 && nc < M){
            if(!visited[nr][nc]){
                ret = max(ret, CheckRoute(nr, nc, i) + Map[r][c]);
            }
        }
    }
    visited[r][c] = false;

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    cout << CheckRoute(0, 0, 0);
    
    return 0;
}
