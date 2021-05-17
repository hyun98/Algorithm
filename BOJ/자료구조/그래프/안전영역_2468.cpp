#include <iostream>
#include <cstring>

using namespace std;

int N, max_height = 0, result = 1;
int Map[101][101];
bool visited[101][101];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
            max_height = max(max_height, Map[i][j]);
        }
    }
}

void BFS(int r, int c, int w){
    visited[r][c] = true;
    
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 && nr < N && nc >= 0 && nc < N){
            if(!visited[nr][nc] && Map[nr][nc] > w) BFS(nr, nc, w);
        }
    }
}

inline void safety(int w){
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j] && Map[i][j] > w){
                cnt++;
                BFS(i, j, w);
            }
            else visited[i][j] = true;
        }
    }
//    cout << "높이 : " << w << "  safeN : " << cnt << endl;
    result = max(result, cnt);
}

void solve(){
    // 물의 높이가 1부터 가장 높은 건물의 높이까지 확인
    for(int i = 1; i <= max_height; i++){
        memset(visited, false, sizeof(visited));
        safety(i);
    }
    cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}
