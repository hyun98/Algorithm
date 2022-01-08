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

int N, Map[33][33];
// shape : 0, 1, 2 : 가로, 세로, 대각
ll dp[33][33][3];

void input(){
    memset(Map, -1, sizeof(Map));
    
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
}

ll solve(int r, int c, int shape){
    
    if(r == N-1 && c == N-1) return 1;
    
    ll &ret = dp[r][c][shape];
    if(ret != -1) return ret;
    ret = 0;
    
    if(shape == 0){
        if(!Map[r][c+1] && !Map[r+1][c] && !Map[r+1][c+1]) ret += solve(r+1, c+1, 2);
        if(!Map[r][c+1]) ret += solve(r, c+1, 0);
    }
    else if(shape == 1){
        if(!Map[r][c+1] && !Map[r+1][c] && !Map[r+1][c+1]) ret += solve(r+1, c+1, 2);
        if(!Map[r+1][c]) ret += solve(r+1, c, 1);
    }
    else if(shape == 2){
        if(!Map[r][c+1] && !Map[r+1][c] && !Map[r+1][c+1]) ret += solve(r+1, c+1, 2);
        if(!Map[r][c+1]) ret += solve(r, c+1, 0);
        if(!Map[r+1][c]) ret += solve(r+1, c, 1);
    }
    
    return ret;
}

int main(){
    fastio
    input();
    cout << solve(0, 1, 0);
    
    return 0;
}
