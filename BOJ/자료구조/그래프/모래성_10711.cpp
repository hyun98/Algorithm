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

int H, W;
int Map[1001][1001];
int Wave[1001][1001];
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
queue<pii > castle, tempcastle;

void input(){
    cin >> H >> W;
    string str;
    for(int r = 0; r < H; r++){
        cin >> str;
        for(int c = 0; c < W; c++){
            if(str[c] == '.') continue;
            Map[r][c] = str[c] - '0';
        }
    }
}

bool Crash_Castle(){
    int crash = 0;
    
    while(!castle.empty()){
        pii now = castle.front();
        castle.pop();
        
        int cnt = 0;
        
        for(int k = 0; k < 8; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            
            if(Map[nr][nc]){
                Wave[nr][nc]++;
                if(Map[nr][nc] == Wave[nr][nc]){
                    crash++;
                    tempcastle.push({nr, nc});
                }
            }
        }
    }
    
    return crash;
}

bool init(){
    for(int r = 0; r < H; r++){
        for(int c = 0; c < W; c++){
            for(int k = 0; k < 8; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                
                if(!Map[nr][nc]) Wave[r][c]++;
            }
            
            if(Map[r][c] && Wave[r][c] >= Map[r][c]){
                castle.push({r, c});
            }
        }
    }
    return !castle.empty();
}

void show(){
    for(int r = 0; r < H; r++){
        for(int c = 0; c < W; c++){
            if(Wave[r][c] < Map[r][c]){
                cout << Map[r][c] << " ";
            }
            else cout << "0 ";
        }
        cout << "\n";
    }
    cout << "-----------------\n";
}

void solve(){
    int wave_cnt = 0;
    
    if(init()) wave_cnt++;
    
    while(Crash_Castle()){
        wave_cnt++;
        while(!tempcastle.empty()){
            pii now = tempcastle.front();
            castle.push(now);
            tempcastle.pop();
        }
    }
    
    cout << wave_cnt;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}

