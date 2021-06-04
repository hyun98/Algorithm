#include <bits/stdc++.h>

#define pii pair<int, int>
using namespace std;

// 1 : 빈공간   2 : 벽   3: 시작위치   4 : 불
int Map[1001][1001];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
int W, H;
pii start_c;
queue<pii> fire;
bool visited[1001][1001];

void input(){
    string str;
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> str;
        for(int j = 0; j < W; j++){
            if(str[j] == '.') Map[i][j] = 1;
            else if(str[j] == '#') Map[i][j] = 2;
            else if(str[j] == 'J'){
                Map[i][j] = 3;
                start_c = {i, j};
            }
            else if(str[j] == 'F'){
                Map[i][j] = 4;
                fire.push({i, j});
            }
        }
    }
}

void BFS(){
    int cnt = 0;
    queue<pii> me;
    
    me.push(start_c);
    visited[start_c.first][start_c.second] = true;
    
    while(!me.empty()){
        queue<pii> mfire = fire;
        
        while(!mfire.empty()){
            pii firenow = mfire.front();
            mfire.pop();
            fire.pop();
            for(int i = 0; i < 4; i++){
                int nr = firenow.first + dr[i];
                int nc = firenow.second + dc[i];
                if(nr < 0 || nc < 0 || nr >= H || nc >= W || Map[nr][nc] == 2 || Map[nr][nc] == 4) continue;
                Map[nr][nc] = 4;
                fire.push({nr, nc});
            }
        }
        
        queue<pii> mme = me;
        cnt++;
    
        while(!mme.empty()){
            pii menow = mme.front();
            mme.pop();
            me.pop();
            for(int i = 0; i < 4; i++){
                int nr = menow.first + dr[i];
                int nc = menow.second + dc[i];
                if(nr < 0 || nc < 0 || nr >= H || nc >= W){
                    cout << cnt << "\n";
                    return;
                }
                if(visited[nr][nc] ||Map[nr][nc] == 4 || Map[nr][nc] == 2) continue;
                visited[nr][nc] = true;
                
                me.push({nr, nc});
            }
        }
        
    }
    cout << "IMPOSSIBLE\n";
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    BFS();
    
    return 0;
}
