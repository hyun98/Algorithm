#include <iostream>
#include <queue>
#include <cstring>

#define pii pair<int, int>

using namespace std;

int Map[101][101];
int N, M;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }
}

bool melt_surface(){
    int cheese_num = 0;
    queue< pii > temps;
    bool visited[101][101];
    memset(visited, 0, sizeof(visited));
    
    temps.push({0, 0});
    visited[0][0] = true;
    
    while(!temps.empty()){
        pii now = temps.front();
        temps.pop();
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            if(Map[nr][nc]){
                cheese_num++;
                Map[nr][nc] = 0;
                continue;
            }
            else temps.push({nr, nc});
        }
    }
    if(cheese_num) return true;
    else return false;
}

bool cvisited[101][101];

int cheese_block(int r, int c){
    int block_cnt = 1;
    queue< pii > que;
    cvisited[r][c] = true;
    que.push({r, c});
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || cvisited[nr][nc] || !Map[nr][nc]) continue;
            
            block_cnt++;
            cvisited[nr][nc] = true;
            que.push({nr, nc});
        }
    }
    
    return block_cnt;
}

// void show(){
//     cout << "=======\n";
//     for(int i = 0; i < N; i++){
//         for(int j = 0 ; j < M; j++){
//             cout << Map[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     cout << "========\n";
// }

void solve(){
    int result = 0, time = 0;
    
    while(true){
        int block_cnt = 0;
        memset(cvisited, 0, sizeof(cvisited));
        
        for(int i = 0; i < N; i++){
            for(int j = 0 ; j < M; j++){
                if(cvisited[i][j] || !Map[i][j]) continue;
                block_cnt += cheese_block(i, j);
            }
        }
        if(!block_cnt) break;
        result = block_cnt;
        
        melt_surface();
        time++;
    }
    
    cout << time << "\n" << result;
}

int main(){
    input();
    solve();
    return 0;
}