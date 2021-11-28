#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M, T, D;
int Map[27][27];
int preset[27][27];
int max_height;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

struct W{
    int r, c, d;
};

struct cmp{
    bool operator()(const W &a, const W &b){
        return a.d > b.d;
    }
};

void input(){
    cin >> N >> M >> T >> D;
    
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            if(islower(str[j])){
                Map[i][j] = str[j] - 'a' + 26;
            }
            else{
                Map[i][j] = str[j] - 'A';
            }
        }
    }
    max_height = Map[0][0];
    
    for(int r = 0; r < 27; r++){
        for(int c = 0; c < 27; c++){
            preset[r][c] = INF;
        }
    }
}

void dijkstra(int r, int c, bool is_climb){
    int temp[27][27];
    for(int i = 0; i < 27; i++){
        for(int j = 0; j < 27; j++){
            temp[i][j] = INF;
        }
    }
    priority_queue<W, vector<W>, cmp> pq;
    pq.push({r, c, 0});
    
    while(!pq.empty()){
        W now = pq.top();
        pq.pop();
        
        if(!is_climb && now.r == 0 && now.c == 0){
            preset[r][c] = now.d;
            return;
        }
        
        if(is_climb && now.d + preset[now.r][now.c] > D) continue;
        if(is_climb && Map[now.r][now.c] > max_height) max_height = Map[now.r][now.c];
        
        for(int k = 0; k < 4; k++){
            int nr = now.r + dr[k];
            int nc = now.c + dc[k];
            int next_d = now.d;
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(abs(Map[nr][nc] - Map[now.r][now.c]) > T) continue;
            
            if(Map[nr][nc] > Map[now.r][now.c]){
                next_d += pow(Map[nr][nc] - Map[now.r][now.c], 2);
            }
            else next_d += 1;
            
            if(next_d >= temp[nr][nc] || next_d > D) continue;
            temp[nr][nc] = next_d;
            pq.push({nr, nc, next_d});
        }
    }
}

void solve(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            dijkstra(r, c, false);
        }
    }
    
    dijkstra(0, 0, true);
    
    cout << max_height;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
