#include <iostream>
#include <string>
#include <queue>
#include <utility>

#define pii pair<int, int>

using namespace std;

int N;
char Map[101][101];
bool visited[101][101][2];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void input(){
    string in;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> in;
        for(int j = 0; j < N; j++){
            Map[i][j] = in[j];
        }
    }
}

void BFS(int r, int c, int d, char color){
    queue<pii> que;
    que.push({r, c});
    visited[r][c][d] = true;
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc][d]) continue;
            if(d == 0){     //색약이 아닌경우
                if(Map[nr][nc] == color){
                    visited[nr][nc][d] = true;
                    que.push({nr, nc});
                }
            }
            else{   // 색약인 경우
                if(color == Map[nr][nc]){
                    visited[nr][nc][d] = true;
                    que.push({nr, nc});
                }
                else if((color == 'R' && Map[nr][nc] == 'G') || (color == 'G' && Map[nr][nc] == 'R')){
                    visited[nr][nc][d] = true;
                    que.push({nr, nc});
                }
            }
        }
    }
}

void solve(){
    int ncount = 0, cwcount = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char nowColor = Map[i][j];
            // 색약이 아닌경우 bfs
            if(!visited[i][j][0]){
                BFS(i, j, 0, nowColor);
                ncount++;
            }
            // 색약인 경우 bfs
            if(!visited[i][j][1]){
                BFS(i, j, 1, nowColor);
                cwcount++;
            }
        }
    }
    cout << ncount << " " << cwcount;
}

int main(){
    input();
    solve();
    
    return 0;
}
