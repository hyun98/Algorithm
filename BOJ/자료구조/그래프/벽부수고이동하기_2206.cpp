#include <bits/stdc++.h>

using namespace std;

struct P{
    int r, c;
    int cnt = 1;
    int wall = 0;
};

int N, M;
int Map[1001][1001];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
int visited[1001][1001][2] = {0, };

void input(){
    cin >> N >> M;
    string in;
    for(int i = 0; i < N; i++){
        cin >> in;
        for(int j = 0; j < M; j++){
            Map[i][j] = in[j] - '0';
        }
    }
    
}

void BFS(){
    int result = 0;
    queue<P> que;
    P temp;
    temp.r = 0;  temp.c = 0;
    que.push(temp);
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;
    
    while(!que.empty()){
        P now = que.front();
        que.pop();
        if(now.r == N-1 && now.c == M-1){
            result = now.cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            P next;
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(visited[nr][nc][now.wall]) continue;
            
            next.r = nr;
            next.c = nc;
            next.cnt = now.cnt + 1;
            
            if(!Map[nr][nc]) next.wall = now.wall;
            else{
                if(now.wall) continue;
                next.wall = 1;
            }
            visited[nr][nc][next.wall] = 1;
            que.push(next);
        }
    }
    
    if(result) cout << result;
    else cout << -1;
    
}

int main(){
    input();
    BFS();
    return 0;
}