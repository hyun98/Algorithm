#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

using namespace std;


// 1:S, 2:Y
int Map[6][6];
int visited[6][6];
bool princess[6][6];
int ans;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void input(){
    string str;
    for(int r = 0; r < 5; r++){
        cin >> str;
        for(int c = 0; c < 5; c++){
            if(str[c] == 'S') Map[r][c] = 1;
            else Map[r][c] = 2;
        }
    }
}

bool check(){
    int cnt = 0;
    bool tempvisited[6][6];
    memset(tempvisited, 0, sizeof(tempvisited));
    
    queue<pii > que;
    for(int r = 0; r < 5; r++){
        bool bb = false;
        for(int c = 0; c < 5; c++){
            if(princess[r][c]){
                que.push({r, c});
                tempvisited[r][c] = true;
                bb = true;
                break;
            }
        }
        if(bb) break;
    }
    
    while(!que.empty()){
        pii now = que.front();
        cnt++;
        // cout << now.first << ',' << now.second << "\n";
        que.pop();
        
        if(cnt == 7){
            return true;
        }
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            
            if(nr >= 5 || nr < 0 || nc >= 5 || nc < 0 || tempvisited[nr][nc]) continue;
            if(princess[nr][nc]){
                tempvisited[nr][nc] = true;
                que.push({nr, nc});
            }
        }
    }
    
    return false;
}

void back(int sr, int sc, int s, int y, int n){
    if(y >= 4) return;
    if(n == 7){
        cout << "--------------\n";
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cout << princess[i][j] << " ";
            }
            cout << "\n";
        }
        if(s >= 4){
            if(check()) ans++;
        }
        return;
    }
    
    for(int r = sr; r < 5; r++){
        for(int c = sc; c < 5; c++){
            if(princess[r][c]) continue;
            princess[r][c] = true;
            if(Map[r][c] == 1) back(r, c, s+1, y, n+1);
            else back(r, c, s, y+1, n+1);
            princess[r][c] = false;
        }
    }
}

void solve(){
    back(0, 0, 0, 0, 0);
    
    cout << ans;
}

int main(){
    input();
    solve();
    
    return 0;
}
