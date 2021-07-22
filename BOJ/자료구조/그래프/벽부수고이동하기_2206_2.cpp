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

struct P{
    int r, c;
    int cnt;
    int wall;
};

int N, M;
int Map[1001][1001];
bool visited[1001][1001][2];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void input(){
    cin >> N >> M;
    string str;
    for(int r = 0; r < N; r++){
        cin >> str;
        for(int c = 0; c < M; c++){
            Map[r][c] = str[c] - '0';
        }
    }
}

int BFS(){
    queue<P> que;
    P st;
    st.r = 0; st.c = 0; st.cnt = 1; st.wall = 0;
    que.push(st);
    
    visited[0][0][0] = true;
    
    while(!que.empty()){
        P now = que.front();
        que.pop();
        
        if(now.r == N-1 && now.c == M-1){
            return now.cnt;
        }
        
        for(int k = 0; k < 4; k++){
            int nr = now.r + dr[k];
            int nc = now.c + dc[k];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(visited[nr][nc][now.wall]) continue;
            
            // 벽부수기 시도
            if(Map[nr][nc] && now.wall == 0 && !visited[nr][nc][now.wall+1]){
                visited[nr][nc][now.wall+1] = true;
                que.push({nr, nc, now.cnt+1, now.wall+1});
            }
            
            if(!Map[nr][nc] && !visited[nr][nc][now.wall]){
                visited[nr][nc][now.wall] = true;
                que.push({nr, nc, now.cnt+1, now.wall});
            }
        }
    }
    
    return -1;
}

void solve(){
    cout << BFS();
}

int main(){
    fasti
    input();
    solve();
    
    return 0;
}
