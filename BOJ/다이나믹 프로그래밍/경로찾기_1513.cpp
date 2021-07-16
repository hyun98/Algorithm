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

int N, M, C;
int dp[51][51][51][51];
int Map[51][51];

void input(){
    cin >> N >> M >> C;
    int r, c;
    for(int i = 1; i <= C; i++){
        cin >> r >> c;
        Map[r][c] = i;
    }
    memset(dp, -1, sizeof(dp));
}

int path_num(int r, int c, int gcnt, int lastg){
    
    int &ret = dp[r][c][gcnt][lastg];
    if(ret != -1) return ret;
    
    if(Map[r+1][c] > lastg){
        path_num(r+1, c, gcnt+1, Map[r+1][c]);
    }
    
    if(Map[r+1][c] == 0)
    
    path_num(r+1, c, )
}

void solve(){
    
}

int main(){
    input();
    solve();
    
    return 0;
}
