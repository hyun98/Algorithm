#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;


// 명령 1. Go k: k는 1, 2 또는 3일 수 있다. 현재 향하고 있는 방향으로 k칸 만큼 움직인다.
// 명령 2. Turn dir: dir은 left 또는 right 이며, 각각 왼쪽 또는 오른쪽으로 90° 회전한다.

struct State{
    int r, c, dir;
    int cnt = 0;
};

bool operator==(State &a, State &b){
    return a.r == b.r && a.c == b.c && a.dir == b.dir;
}

int N, M;
int Map[101][101];
State src, dst;

int dr[5] = {0, 0, 0, 1, -1};
int dc[5] = {0, 1, -1, 0, 0};

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> Map[i][j];
        }
    }
    cin >> src.r >> src.c >> src.dir;
    cin >> dst.r >> dst.c >> dst.dir;
}

int turn_right(int d){
    if(d == 1) return 3;
    else if(d == 2) return 4;
    else if(d == 3) return 2;
    else return 1;
}

int turn_left(int d){
    if(d == 1) return 4;
    else if(d == 2) return 3;
    else if(d == 3) return 1;
    else return 2;
}

int bfs(){
    queue<State> que;
    que.push(src);
    
    bool visited[101][101][5];
    memset(visited, 0, sizeof(visited));
    visited[src.r][src.c][src.dir] = true;
    
    while(!que.empty()){
        State now = que.front();
        que.pop();
        
        if(now == dst){
            return now.cnt;
        }
        
        // 명령1
        for(int k = 1; k <= 3; k++){
            // 1, 2, 3 칸만큼 움직임
            int nr = now.r + dr[now.dir] * k;
            int nc = now.c + dc[now.dir] * k;
            // 벽이 있는 경우에만 break시켜준다
            // 조건을 하나로 묶어버리면 벽은 없지만 k칸 이동했을 때 방문한 적이 있다면 
            // 바로 break가 걸리기 때문에 정답을 못구할 수도 있다.
            if(Map[nr][nc]) break;
            if(nr < 1 || nr > N || nc < 1 || nc > M || visited[nr][nc][now.dir]) continue;
            
            // 갈 수 있는 경우
            visited[nr][nc][now.dir] = true;
            que.push({nr, nc, now.dir, now.cnt+1});
        }
        
        // 명령2
        int td = turn_left(now.dir);
        if(!visited[now.r][now.c][td]){
            visited[now.r][now.c][td] = true;
            que.push({now.r, now.c, td, now.cnt+1});
        }
        
        td = turn_right(now.dir);
        if(!visited[now.r][now.c][td]){
            visited[now.r][now.c][td] = true;
            que.push({now.r, now.c, td, now.cnt+1});
        }
    }
    
    return -1;
}


int main(){
    fastio
    input();
    cout << bfs();
    
    return 0;
}
