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
    // 방문한 곳에 다시 도달한다는건 사이클을 이룬다는 뜻이므로 무한번 움직일 수 있다.
    if(visited[r][c]){
        cout << -1;
        exit(0);
    }
    int &ret = cache[r][c];
    if(ret != -1) return ret;
    
    // 방문 처리
    visited[r][c] = true;
    ret = 0;
    
    // 현재 위치 숫자만큼 상하좌우로 이동
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i] * Map[r][c];
        int nc = c + dc[i] * Map[r][c];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M || !Map[nr][nc]) continue;
        
        // 가장 많이 움직일 수 있는 방향의 이동 횟수를 받는다.
        ret = max(ret, solve(nr, nc) + 1);
    }
    
    visited[r][c] = false;
    
    // 현재 위치에서 가장 많이 움직일 수 있는 횟수를 리턴
    return ret;
}

int main(){
    fastio
    input();
    cout << solve(0, 0) + 1;
    
    return 0;
}
