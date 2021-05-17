#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int Map[1001][1001];
int dp[1001][1001];

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> Map[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
}

void solve(){
    int result = 0;
    for(int row = 1; row <= N; row++){
        for(int col = 1; col <= M; col++){
            dp[row][col] = max(dp[row-1][col], dp[row][col-1]) + Map[row][col];
            
        }
    }
    cout << dp[N][M];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    
    return 0;
}
