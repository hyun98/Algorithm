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

int N, M, result = INF;
int Lab[51][51];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
vector<pii > virus;

void input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Lab[i][j];
            if(Lab[i][j] == 2){
                virus.push_back({i, j});
            }
        }
    }
}

int bfs(vector<pii > &vec){
    int tLab[51][51];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tLab[i][j] = Lab[i][j];
        }
    }
    int ans = 0;
    queue<pii > que;
    for(auto &w : vec){
        que.push(w);
        tLab[w.first][w.second] = -1;
    }
    
    while(!que.empty()){
        pii now = que.front();
        int now_time = tLab[now.first][now.second];
        que.pop();
        
        
        if(Lab[now.first][now.second] != 2) ans = abs(now_time + 1);
        if(ans >= result) return INF;
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            
            if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if(tLab[nr][nc] == 1 || tLab[nr][nc] < 0) continue;
            if(!tLab[nr][nc] || tLab[nr][nc] == 2){
                tLab[nr][nc] = now_time - 1;
                que.push({nr, nc});
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!tLab[i][j]) return INF;
        }
    }
    return ans;
}

void dfs(int now, vector<pii > &vec){
    if(vec.size() == M){
        result = min(result, bfs(vec));
        return;
    }
    for(int i = now; i < virus.size(); i++){
        vec.push_back(virus[i]);
        dfs(i+1, vec);
        vec.pop_back();
    }
}

void solve(){
    vector<pii> vec;
    dfs(0, vec);
    
    if(result == INF) cout << -1 << "\n";
    else cout << result << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
