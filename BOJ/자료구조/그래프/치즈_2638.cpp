#include <iostream>
#include <queue>
#include <cstring>

#define pii pair<int, int>

using namespace std;

int Map[101][101];
int cntMap[101][101];
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

void melt_surface(){
    queue< pii > temps;
    bool visited[101][101];
    memset(visited, 0, sizeof(visited));
    memset(cntMap, 0, sizeof(cntMap));
    
    temps.push({0, 0});
    visited[0][0] = true;
    
    while(!temps.empty()){
        pii now = temps.front();
        temps.pop();
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) continue;
            
            if(Map[nr][nc]){
                if(++cntMap[nr][nc] >= 2){
                    visited[nr][nc] = true;
                    Map[nr][nc] = 0;
                }
            }
            else{
                visited[nr][nc] = true;
                temps.push({nr, nc});
            }
        }
    }
}

void solve(){
    int time = 0;
    
    while(true){
        bool block_in = false;
        for(int i = 0; i < N; i++){
            for(int j = 0 ; j < M; j++){
                if(!Map[i][j]) continue;
                block_in = true;
                break;
            }
            if(block_in) break;
        }
        
        if(!block_in) break;
        
        melt_surface();
        time++;
    }
    
    cout << time;
}

int main(){
    input();
    solve();
    return 0;
}