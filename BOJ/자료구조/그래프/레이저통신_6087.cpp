#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct P{
    int r, c;
    int dir;    // 0 1 2 3 : 동 서 남 북
    int mnum;
};

const int INF = 1e9+7;
int W, H;
int Map[101][101];
int mirrornum[101][101];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
vector<pair<int, int> > Cs;

void input(){
    string str;
    cin >> W >> H;
    for(int i = 0; i < H; i++){
        cin >> str;
        for(int j = 0; j < W; j++){
            char cc = str[j];
            switch (cc){
            case '.': Map[i][j] = 1; break;
            case 'C':
                Map[i][j] = 2; 
                Cs.push_back({i, j});
                break;
            case '*': Map[i][j] = 0; break;
            default: break;
            }
            mirrornum[i][j] = INF;
        }
    }
}

void bfs(){
    queue<P> que;
    for(int k = 0; k < 4; k++){
        que.push({Cs[0].first, Cs[0].second, k, 0});
    }
    
    while(!que.empty()){
        P now = que.front();
        que.pop();
        
        if(now.r == Cs[1].first && now.c == Cs[1].second) continue;
        
        for(int k = 0; k < 4; k++){
            int nr = now.r + dr[k];
            int nc = now.c + dc[k];
            
            if(nr < 0 || nr >= H || nc < 0 || nc >= W || !Map[nr][nc]) continue;
            
            if(now.dir != k){
                if(mirrornum[nr][nc] < now.mnum + 1) continue;
                mirrornum[nr][nc] = now.mnum + 1;
                que.push({nr, nc, k, now.mnum + 1});
            }
            else{
                if(mirrornum[nr][nc] < now.mnum) continue;
                mirrornum[nr][nc] = now.mnum;
                que.push({nr, nc, k, now.mnum});
            }
        }
    }
}

int main(){
    input();
    bfs();
    cout << mirrornum[Cs[1].first][Cs[1].second];
    return 0;
}