#include <iostream>
#include <queue>
#include <cstring>

#define pii pair<int, int>

using namespace std;

int R, C;
// *:0  .:1  S:1  D:2  X:3
int Map[51][51];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
bool visited[51][51];
pii beaver;

queue<pii > water;
queue<pii > gosm;


void input(){
    string str;
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            if(str[j] == 'D'){
                Map[i][j] = 2;
                beaver = {i, j};
            }
            else if(str[j] == '.'){
                Map[i][j] = 1;
            }
            else if(str[j] == 'S'){
                gosm.push({i, j});
                Map[i][j] = 1;
                visited[i][j] = true;
            }
            else if(str[j] == '*'){
                Map[i][j] = 0;
                water.push({i, j});
            }
            else if(str[j] == 'X'){
                Map[i][j] = 3;
            }
        }
    }
}

int BFS(){
    queue<pii > nextwater, nextgosm;
    int cnt = 0;
    
    while(!gosm.empty()){
        
        // 물 먼저 차오름
        while(!water.empty()){
            pii now = water.front();
            water.pop();
            
            for(int k = 0; k < 4; k++){
                int nr = now.first + dr[k];
                int nc = now.second + dc[k];
                
                if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if(Map[nr][nc] != 1) continue;
                
                nextwater.push({nr, nc});
                Map[nr][nc] = 0;
            }
            
        }
        
        // 고슴도치 이동
        while(!gosm.empty()){
            pii now = gosm.front();
            gosm.pop();
            
            if(now.first == beaver.first && now.second == beaver.second) return cnt;
            
            for(int k = 0; k < 4; k++){
                int nr = now.first + dr[k];
                int nc = now.second + dc[k];
                
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
                if(Map[nr][nc] != 1 && Map[nr][nc] != 2) continue;
                
                visited[nr][nc] = true;
                nextgosm.push({nr, nc});
            }
        }
        
        cnt++;
        water = nextwater;
        while(!nextwater.empty()) nextwater.pop();
        gosm = nextgosm;
        while(!nextgosm.empty()) nextgosm.pop();
    }
    
    return -1;
}

void solve(){
    int res = BFS();
    
    if(res == -1) cout << "KAKTUS";
    else cout << res;
}

int main(){
    input();
    solve();
    
    return 0;
}
