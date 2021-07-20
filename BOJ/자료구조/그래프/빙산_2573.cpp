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

int N, M;
int Map[301][301];
int Tmap[301][301];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
queue<pii > iceque, icetemp;
int year = 0;

bool visited[301][301];

void input(){
    cin >> N >> M;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> Map[r][c];
            Tmap[r][c] = Map[r][c];
            if(Map[r][c]) iceque.push({r, c});
        }
    }
}

void BFS(){
    while(!iceque.empty()){
        pii now = iceque.front();
        iceque.pop();
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            
            if(!Map[nr][nc]){
                Tmap[now.first][now.second]--;
            }
        }
        if(Tmap[now.first][now.second] > 0){
            icetemp.push({now});
        }
        else Tmap[now.first][now.second] = 0;
    }
}

void show(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            Map[r][c] = Tmap[r][c];
        }
    }
}

void check(int r, int c){
    queue<pii > que;
    que.push({r, c});
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || !Map[nr][nc] || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            que.push({nr, nc});
        }
    }
}

void solve(){
    while(!iceque.empty()){
        year++;
        BFS();
        show();
        memset(visited, 0, sizeof(visited));
        
        int ct = 0;
        while(!icetemp.empty()){
            int r = icetemp.front().first;
            int c = icetemp.front().second;
            iceque.push(icetemp.front());
            if(!visited[r][c]){
                check(r, c);
                ct++;
            }
            if(ct > 1){
                cout << year;
                return;
            }
            icetemp.pop();
        }
    }
    cout << 0;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
