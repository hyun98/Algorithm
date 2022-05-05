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

struct W{
    int r1, c1, r2, c2;
};

int N, M;
int Map[6][6];
int answer;

W wings[4] = {
    {0, -1, 1, 0},
    {0, -1, -1, 0},
    {-1, 0, 0, 1},
    {1, 0, 0, 1}
};

void input(){
    cin >> N >> M;
    int k;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }
}

void dfs(int r, int c, int visited, int sum){
    answer = max(answer, sum);
    
    if(r == N) return;
    if(c == M){
        dfs(r+1, 0, visited, sum);
        return;
    }
    
    // 현재 칸이 중심
    for(int i = 0; i < 4; i++){
        int nr1 = r + wings[i].r1;
        int nc1 = c + wings[i].c1;
        int nr2 = r + wings[i].r2;
        int nc2 = c + wings[i].c2;
        if(nr1 < 0 || nc1 < 0 || nr2 < 0 || nc2 < 0 || \
           nr1 >= N || nc1 >= M || nr2 >= N || nc2 >= M) continue;
        int tempv = ((1 << (r * M + c)) | (1 << (nr1 * M + nc1))) | (1 << (nr2 * M + nc2));
        if(tempv & visited) continue;
        
        int tsum = Map[r][c] * 2 + Map[nr1][nc1] + Map[nr2][nc2];
        dfs(r, c+1, visited | tempv, sum + tsum);
    }
    
    // 현재 칸은 중심 x
    dfs(r, c+1, visited, sum);
    
}


void solve(){
    dfs(0, 0, 0, 0);
    cout << answer << '\n';
}

int main(){
    input();
    solve();
    
    return 0;
}
