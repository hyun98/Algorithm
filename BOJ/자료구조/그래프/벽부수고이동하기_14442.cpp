#include <bits/stdc++.h>

using namespace std;

struct P{
    int r, c;       // 현재 위치
    int cnt = 1;    // 지금까지 지나온 칸 수
    int wall = 0;   // 지금까지 부순 벽의 수 
};

int N, M, K;
int Map[1001][1001];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
int visited[1001][1001][11] = {0, };

void input(){
    cin >> N >> M >> K;
    string in;
    for(int i = 0; i < N; i++){
        cin >> in;
        for(int j = 0; j < M; j++){
            Map[i][j] = in[j] - '0';
        }
    }
}

int BFS(){
    int result = 0;
    queue<P> que;
    P temp;
    temp.r = 0;  temp.c = 0;
    que.push(temp);

    visited[0][0][0] = 1;

    while(!que.empty()){
        P now = que.front();
        que.pop();
        
        // BFS 이므로 가장 먼저 도착한 경우임
        if(now.r == N-1 && now.c == M-1) return now.cnt;
        
        for(int i = 0; i < 4; i++){
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            
            // 좌표를 넘어가는 경우
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            // 이미 방문한 경우
            if(visited[nr][nc][now.wall]) continue;
            
            // 다음이 벽이 아니고, 방문하지 않았다면
            if(!Map[nr][nc] && !visited[nr][nc][now.wall]){
                visited[nr][nc][now.wall] = 1;
                que.push({nr, nc, now.cnt+1, now.wall});
            }
            // 다음이 벽이고, 벽을 최소 하나 더 부술 수 있고, 하나 더 부순 경우에 방문하지 않았다면
            if(Map[nr][nc] && now.wall < K && !visited[nr][nc][now.wall+1]){
                visited[nr][nc][now.wall+1] = 1;
                que.push({nr, nc, now.cnt+1, now.wall+1});
            }
        }
    }
    
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << BFS();
    return 0;
}
