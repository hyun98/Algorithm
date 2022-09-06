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

struct Light{
    int r, c, dir;
    int mirrorCnt;
};

struct cmp {
    bool operator()(Light &l1, Light &l2){
        return l1.mirrorCnt > l2.mirrorCnt;
    }
};

int N;

// 동 서 남 북
int dir[4] = {0, 1, 2, 3};
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

// [r][c][dir]
int dp[51][51][4];

int Map[51][51];
bool mirror[51][51];
pii st = {-1, -1}, ed;

void input(){
    cin >> N;
    string s;
    
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < N; j++){
            switch (s[j]) {
            case '*': Map[i][j] = 0; break;
            case '#': 
                Map[i][j] = 2; 
                if(st.first == -1) st = {i, j}; 
                else ed = {i, j};
                break;
            case '.': Map[i][j] = 1; break;
            case '!': Map[i][j] = 3; mirror[i][j] = true; break;
            default: break;
            }
        }
    }
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k < 4; k++){
                dp[i][j][k] = INF;
            }
        }
    }
}

vector<int> validDir(int dir){
    if(dir == 0 || dir == 1){
        return vector<int> {2, 3};
    }
    else{
        return vector<int> {0, 1};
    }
}

void solve(){
    priority_queue<Light, vector<Light>, cmp > pq;
    
    for(int i = 0; i < 4; i++){
        int nr = st.first + dr[i];
        int nc = st.second + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N || !Map[nr][nc]) continue;
        pq.push({st.first, st.second, i, 0});
        dp[st.first][st.second][i] = 0;
    }
    
    while(!pq.empty()){
        Light now = pq.top();
        pq.pop();
        
        if(dp[now.r][now.c][now.dir] < now.mirrorCnt){
            continue;
        }
        
        // 일반 공간 : 방향 그대로 직진
        // 거울 공간 : 거울 설치 안하고 직진
        if(Map[now.r][now.c]) {
            int nr = now.r + dr[now.dir];
            int nc = now.c + dc[now.dir];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N && Map[nr][nc]){
                if(now.mirrorCnt < dp[nr][nc][now.dir]){
                    dp[nr][nc][now.dir] = now.mirrorCnt;
                    pq.push({nr, nc, now.dir, now.mirrorCnt});
                }
            }
        }
        
        // 거울 공간
        if(Map[now.r][now.c] == 3){
            for(auto ndir: validDir(now.dir)){
                int nr = now.r + dr[ndir];
                int nc = now.c + dc[ndir];
                
                if(nr < 0 || nr >= N || nc < 0 || nc >= N || !Map[nr][nc]) continue;
                if(dp[nr][nc][ndir] <= now.mirrorCnt + 1) continue;
                
                dp[nr][nc][ndir] = now.mirrorCnt + 1;
                pq.push({nr, nc, ndir, now.mirrorCnt + 1});
            }
        }
    }
    
    int answer = INF;
    for(int i = 0; i < 4; i++){
        answer = min(answer, dp[ed.first][ed.second][i]);
    }
    
    cout << answer;
}

int main(){
    input();
    solve();
    
    return 0;
}
