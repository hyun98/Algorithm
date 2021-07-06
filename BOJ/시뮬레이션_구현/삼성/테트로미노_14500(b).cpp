#include <iostream>
#include <cstring>

using namespace std;

int N, M, result;
int MAP[501][501];
bool visited[501][501];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> MAP[i][j];
        }
    }
}

void dfs(int r, int c, int sum, int cnt){
    visited[r][c] = true;
    
    if(cnt == 3){
        result = max(result, sum);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
        if(visited[nr][nc]) continue;
        
        dfs(nr, nc, sum + MAP[nr][nc], cnt+1);
        visited[nr][nc] = false;
    }
}

// ㅗ ㅜ ㅏ ㅓ 를 따로 찾아주는 방법
// ㅗ
inline void Shape1(int x, int y){
    int Tmp_Sum = 0;
    Tmp_Sum = MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x - 1][y + 1];
    result = max(result, Tmp_Sum);
}

// ㅜ
inline void Shape2(int x, int y){
    int Tmp_Sum = 0;
    Tmp_Sum = MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x + 1][y + 1];
    result = max(result, Tmp_Sum);
}

// ㅏ
inline void Shape3(int x, int y){
    int Tmp_Sum = 0;
    Tmp_Sum = MAP[x][y] + MAP[x + 1][y] + MAP[x + 2][y] + MAP[x + 1][y + 1];
    result = max(result, Tmp_Sum);
}

// ㅓ
inline void Shape4(int x, int y){
    int Tmp_Sum = 0;
    Tmp_Sum = MAP[x][y] + MAP[x - 1][y + 1] + MAP[x][y + 1] + MAP[x + 1][y + 1];
    result = max(result, Tmp_Sum);
} 

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            memset(visited, false, sizeof(visited));
            dfs(i, j, MAP[i][j], 0);
            // ㅗ ㅜ ㅏ ㅓ 찾기
            if(i - 1 >= 0 && j + 2 < M) Shape1(i, j);   // ㅗ
            if(i + 1 <  N && j + 2 < M) Shape2(i, j);   // ㅜ
            if(i + 2 <  N && j + 1 < M) Shape3(i, j);   // ㅏ
            if(i - 1 >= 0 && i + 1 < N && j + 1 < M) Shape4(i, j);   // ㅓ
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    
    return 0;
}
