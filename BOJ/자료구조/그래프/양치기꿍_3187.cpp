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

int R, C;
// 0:벽, 1:빈 곳, 2:양, 3:늑대
int Map[251][251];
bool visited[251][251];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void input(){
    cin >> R >> C;
    string str;
    for(int r = 0; r < R; r++){
        cin >> str;
        for(int c = 0; c < C; c++){
            switch (str[c]){
            case '.': Map[r][c] = 1; break;
            case 'k': Map[r][c] = 2; break;
            case 'v': Map[r][c] = 3; break;
            default: break;
            }
        }
    }
}

pii bfs(int r, int c){
    pii ret = {0, 0}; // {양, 늑대}
    queue<pii > que;
    visited[r][c] = true;
    que.push({r, c});
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        if(Map[now.first][now.second] == 2) ret.first++;
        else if(Map[now.first][now.second] == 3) ret.second++;
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || !Map[nr][nc] || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            que.push({nr, nc});
        }
    }
    
    return ret;
}

void solve(){
    int sheep = 0, wolf = 0;
    pii temp;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(!Map[r][c] || visited[r][c]) continue;
            temp = bfs(r, c);
            if(temp.first > temp.second) sheep += temp.first;
            else wolf += temp.second;
        }
    }
    cout << sheep << " " << wolf << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
