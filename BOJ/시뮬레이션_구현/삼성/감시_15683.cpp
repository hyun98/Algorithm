#include <iostream>
#include <vector>
#include <cstring>

#define pii pair<int, int>

using namespace std;

int N, M, blank = 0, res = 100;
int Map[9][9];
int dircnt[6] = {0, 1, 2, 2, 3, 4};
int dir[6][4] = { {}, {0}, {0, 2}, {0, 1}, {0, 1, 3}, {0, 1, 2, 3} };
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<pii > cctv;


void input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
            if(Map[i][j] != 0 && Map[i][j] != 6){
                cctv.push_back({i, j});
            }
            else if(!Map[i][j]) blank++;
        }
    }
}

void solve(int now, int cnt){
    if(now == cctv.size()){
        res = min(res, cnt);
        return;
    }
    
    int r = cctv[now].first;
    int c = cctv[now].second;
    int cnum = Map[r][c];
    
    int tmpMap[9][9];
    memcpy(tmpMap, Map, sizeof(Map));
    
    for(int k = 0; k < 4; k++){
        // 각 cctv의 방향을 정해준다
        memcpy(Map, tmpMap, sizeof(Map));
        int tmpcnt = cnt;
        
        for(int i = 0; i < dircnt[cnum]; i++){
            int nextdir = dir[cnum][i];
            int nr = r + dr[(nextdir + k) % 4];
            int nc = c + dc[(nextdir + k) % 4];
            
            while(nr >= 0 && nr < N && nc >= 0 && nc < M && Map[nr][nc] != 6){
                if(!Map[nr][nc]){
                    Map[nr][nc] = -1;
                    tmpcnt--;
                }
                nr += dr[(nextdir + k) % 4];
                nc += dc[(nextdir + k) % 4];
            }
        }
        solve(now+1, tmpcnt);
    }
}

int main(){
    input();
    
    solve(0, blank);
    cout << res;
    return 0;
}
