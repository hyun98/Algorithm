#include <iostream>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N, M;
int Map[51][51];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

bool visited[51][51];
int cache[51][51];

void input(){
    cin >> N >> M;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            if(str[j] == 'H') Map[i][j] = 0;
            else Map[i][j] = str[j] - '0';
        }
    }
    memset(cache, -1, sizeof(cache));
}

int solve(int r, int c){
    if(visited[r][c]){
        cout << -1;
        exit(0);
    }
    int &ret = cache[r][c];
    if(ret != -1) return ret;
    
    visited[r][c] = true;
    ret = 0;
    
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i] * Map[r][c];
        int nc = c + dc[i] * Map[r][c];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M || !Map[nr][nc]) continue;
        
        ret = max(ret, solve(nr, nc) + 1);
    }
    
    visited[r][c] = false;
    
    return ret;
}

int main(){
    fastio
    input();
    cout << solve(0, 0) + 1;
    
    return 0;
}
