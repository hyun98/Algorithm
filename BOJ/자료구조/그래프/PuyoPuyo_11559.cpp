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

char Map[13][13];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void input(){
    string row;
    char f;
    for(int r = 0; r < 12; r++){
        for(int c = 0; c < 6; c++){
            cin >> f;
            Map[r][c] = f;
        }
    }
}

bool Boom(int r, int c){
    
    vector<pii > boomField;
    queue<pii > que;
    bool visited[13][13];
    memset(visited, 0, sizeof(visited));
    
    boomField.push_back({r, c});
    que.push({r, c});
    visited[r][c] = true;
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        char nowColor = Map[now.first][now.second];
        
        for(int i = 0; i < 4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            
            if(nr < 0 || nr > 12 || nc < 0 || nc > 6) continue;
            if(Map[nr][nc] == nowColor && !visited[nr][nc]){
                visited[nr][nc] = true;
                boomField.push_back({nr, nc});
                que.push({nr, nc});
            }
        }
    }
    
    if(boomField.size() >= 4){
        for(auto &coord: boomField){
            Map[coord.first][coord.second] = '.';
        }
        return true;
    }
    
    return false;
}

void print(){
    for(int r = 0; r < 12; r++){
        for(int c = 0; c < 6; c++){
            cout << Map[r][c];
        }
        cout << '\n';
    }
}

void down(){
    
    for(int c = 0; c < 6; c++){
        queue<char> col;
        
        for(int r = 11; r >= 0; r--){
            if(Map[r][c] != '.'){
                col.push(Map[r][c]);
                Map[r][c] = '.';
            }
        }
        
        int row = 11;
        while(!col.empty()){
            char nowColor = col.front();
            col.pop();
            Map[row--][c] = nowColor;
        }
    }
}

void solve(){
    int count = 0;
    
    while(true){
        bool isBoomed = false;
        for(int r = 0; r < 12; r++){
            for(int c = 0; c < 6; c++){
                if(Map[r][c] != '.'){
                    if(Boom(r, c)) isBoomed = true;
                }
            }
        }
        
        if(!isBoomed){
            cout << count;
            return;
        }
        down();
        count++;
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
