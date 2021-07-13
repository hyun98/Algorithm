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
int dp[101][101];

void input(){
    cin >> N >> M;
    int r, c;
    for(r = 1; r <= N; r++){
        for(c = 1; c <= N; c++){
            dp[r][c] = INF;
        }
    }
    
    for(int i = 0; i < M; i++){
        cin >> r >> c;
        dp[r][c] = 1;
        dp[c][r] = 1;
    }
}

void solve(){
    for(int i = 1; i <= N; i++){
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= N; c++){
                dp[r][c] = min(dp[r][i] + dp[i][c], dp[r][c]);
            }
        }
    }
    int res;
    int sum = INF;
    for(int i = 1; i <= N; i++){
        int tsum = 0;
        for(int j = 1; j <= N; j++){
            tsum += dp[i][j];
        }
        if(tsum < sum){
            res = i;
            sum = tsum;
        }
    }
    cout << res;
}

int main(){
    fasti
    input();
    solve();
    
    return 0;
}
