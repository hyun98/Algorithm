#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct P{
    int r, c;
};

int R, C;
vector<string> Lake;
queue<P> swanQ, waterQ, tmpswanQ, tmpwaterQ;
int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
bool visited[1501][1501], found = false;

void input(){
    string line;
    P swan;
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> line;
        Lake.push_back(line);
        for(int j = 0; j < C; j++){
            if(line[j] != 'X'){
                waterQ.push({i, j});
            }
            if(line[j] == 'L'){
                swan.r = i;
                swan.c = j;
            }
            
        }
    }
    swanQ.push(swan);
    visited[swan.r][swan.c] = true;
}

void swanBFS(){
    while(!swanQ.empty()){
        P now = swanQ.front();
        swanQ.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            if(Lake[nr][nc] == 'X'){
                tmpswanQ.push({nr, nc});
            }
            else if(Lake[nr][nc] == '.'){
                swanQ.push({nr, nc});
            }
            else if(Lake[nr][nc] == 'L'){
                found = true;
                break;
            }
        }
    }
}

void waterBFS(){
    while(!waterQ.empty()){
        P now = waterQ.front();
        waterQ.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            
            if(Lake[nr][nc] == 'X'){
                Lake[nr][nc] = '.';
                tmpwaterQ.push({nr, nc});
            }
        }
    }
}

void solve(){
    int day = 0;
    
    while(!found){
        swanBFS();
        if(found) break;
        waterBFS();
        
        swanQ = tmpswanQ;
        waterQ = tmpwaterQ;
        
        tmpswanQ = queue<P>();
        tmpwaterQ = queue<P>();
        
        day++;
    }
    
    cout << day << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
    
    return 0;
}
