#include <iostream>

using namespace std;

int N, Map[501][501], dp[501][501];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, 1, -1};
bool visited[501][501] = {false, };

void init(){
    cin >> N;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            cin >> Map[r][c];
            dp[r][c] = 1;
            visited[r][c] = false;
        }
    }
}

int find_bamboo(int row, int col){
    // 방문한 적이 있으면 해당 지점의 dp값을 구했다는 의미이므로 그 값을 리턴
    if(visited[row][col]){
        return dp[row][col];
    }
    
    visited[row][col] = true;
    
    int res = 1;
    for(int i = 0; i < 4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];
        if(nr >= 0 && nr < N && nc >= 0 && nc < N && (Map[nr][nc] > Map[row][col])){
            if(visited[nr][nc]){
                res = max(res, 1 + dp[nr][nc]);
            }
            else{
                res = max(res, 1 + find_bamboo(nr, nc));
            }
        }
    }
    
    // 최댓값을 dp에 저장하면서 리턴
    return dp[row][col] = res;
}

void solve(){
    int result = 1;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            result = max(result, find_bamboo(r, c));
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    init();
    solve();
    
    return 0;
}
