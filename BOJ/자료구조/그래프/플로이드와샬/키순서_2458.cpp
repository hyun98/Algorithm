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
int adj[501][501][2];

void input(){
    cin >> N >> M;
    int a, b;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j) continue;
            adj[i][j][0] = INF;
            adj[i][j][1] = INF;
        }
    }
    
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a][b][0] = 1;
        adj[b][a][1] = 1;
    }
}

void solve(){
    for(int i = 1; i <= N; i++){
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= N; c++){
                adj[r][c][0] = min(adj[r][i][0] + adj[i][c][0], adj[r][c][0]);
                adj[r][c][1] = min(adj[r][i][1] + adj[i][c][1], adj[r][c][1]);
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= N; i++){
        bool find = true;
        for(int j = 1; j <= N; j++){
            if(adj[i][j][0] == INF && adj[i][j][1] == INF){
                find = false;
                break;
            }
        }
        if(find) answer++;
    }
    
    cout << answer;
}

int main(){
    fasti
    input();
    solve();
    
    return 0;
}
