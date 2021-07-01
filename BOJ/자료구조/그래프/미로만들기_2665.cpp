#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

struct P{
    int r, c, b;
};

int N;
int Map[51][51];
bool found, visited[51][51];
int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
queue<P> que, tmp;

void input(){
    cin >> N;
    string line;
    for(int i = 0; i < N; i++){
        cin >> line;
        
        for(int j = 0; j < N; j++){
            if(line[j] == '1') Map[i][j] = 1;
            else if(line[j] == '0') Map[i][j] = 0;
        }
    }
    que.push({0, 0, 0});
    visited[0][0] = true;
}

void bfs(){
    while(!que.empty()){
        P now = que.front();
        que.pop();
        
        if(now.r == N-1 && now.c == N-1){
            found = true;
            break;
        }
        
        for(int k = 0; k < 4; k++){
            int nr = now.r + dr[k];
            int nc = now.c + dc[k];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            if(Map[nr][nc] == 1){
                que.push({nr, nc, now.b});
            }
            else if(Map[nr][nc] == 0){
                tmp.push({nr, nc, now.b+1});
            }
        }
    }
}

void solve(){
    int res = 0;
    while(!found){
        bfs();
        
        if(found) break;
        que = tmp;
        tmp = queue<P>();
        res++;
    }
    cout << res;
}

int main(){
    input();
    solve();
    
    return 0;
}