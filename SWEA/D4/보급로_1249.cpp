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

int N, test, K;
int Map[101][101];
int Cache[101][101];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void input(){
    cin >> N;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int k = 0; k < N; k++){
            Map[i][k] = str[k] - '0';
        }
    }
}

void BFS(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Cache[i][j] = INF;
        }
    }
    queue<pii > que;
    que.push({0, 0});
    Cache[0][0] = 0;
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            
            int cost = Cache[now.first][now.second] + Map[nr][nc];
            if(cost >= Cache[nr][nc]) continue; 
            
            Cache[nr][nc] = cost;
            que.push({nr, nc});
        }
    }
}

void solve(){
    BFS();
    cout << "#" << K+1 << " " << Cache[N-1][N-1] << "\n";
}

int main(){
    cin >> test;
    
    while(K < test){
        input();
        solve();
        K++;
    }
    
    return 0;
}
