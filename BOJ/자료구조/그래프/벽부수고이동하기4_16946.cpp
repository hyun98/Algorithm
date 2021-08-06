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

int N, M;
int Map[1001][1001];
int setMap[1001][1001];
int result[1001][1001];
int setnums[1000001];

int setcount = 1;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void input(){
    cin >> N >> M;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            Map[i][j] = str[j] - '0';
        }
    }
}

void bfs(int r, int c){
    queue<pii > que;
    que.push({r, c});
    setMap[r][c] = setcount;
    
    int cnt = 0;
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        cnt++;
        
        for(int k = 0; k < 4; k++){
            int nr = now.first+ dr[k];
            int nc = now.second + dc[k];
            
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(Map[nr][nc] > 0 || setMap[nr][nc]) continue;
            setMap[nr][nc] = setcount;
            que.push({nr, nc});
        }
    }
    
    setnums[setcount++] = cnt;
}

void solve(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(Map[r][c] != 0 || setMap[r][c] > 0) continue;
            bfs(r, c);
        }
    }
    
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(Map[r][c] > 0){
                int cnt = 1;
                vector<int> check;
                for(int k = 0; k < 4; k++){
                    bool con = false;
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    
                    if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
                    for(auto &w : check){
                        if(w == setMap[nr][nc]){
                            con = true;
                            break;
                        }
                    }
                    check.push_back(setMap[nr][nc]);
                    if(con) continue;
                    cnt += setnums[setMap[nr][nc]];
                }
                result[r][c] = cnt;
            }
        }
    }
    
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cout << result[r][c]%10;
        }
        cout << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
