/*
    처음에 dp[][] 값이 0이라도 방문 했을 수 있다는 사실을 간과했음
    DFS + DP 로 해결
    배열은 모두 -1로 초기화가 안됨 0으로만 시켜줄 수 있고, 1이나 -1로 초기화를 시키려면
    memset(배열이름, 바꾸려는 숫자, sizeof(배열이름)) 사용하기
    2021-01-10
*/

#include <iostream>
#include <vector>
using namespace std;

int M, N;
int Map[501][501];
int dp[501][501];
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

int DFS(int r, int c){
    if(r == M-1 && c == N-1) return 1;
    
    if(dp[r][c] != -1) return dp[r][c];
    
    int result = 0;
    
    for(int k = 0; k < 4; k++){
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(nr >= 0 && nr < M && nc >= 0 && nc < N){
            if(Map[r][c] > Map[nr][nc]){
                result += DFS(nr, nc);
            }
        }
    }
    dp[r][c] = result;
    return dp[r][c];
}

void input(){
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
            dp[i][j] = -1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    cout << DFS(0, 0);
    return 0;
}
