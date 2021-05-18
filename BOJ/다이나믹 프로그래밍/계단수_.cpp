#include <iostream>
#include <cstring>

using namespace std;

int N, MOD = 1000000000;
long long dp[101][10][1 << 10], ans[101] = {0, };

void solve(){
    ans[10] = 1;
    dp[1][0] = 0;
    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j+1] % MOD;
            }
            else if(j == 9) dp[i][j] = dp[i-1][j-1] % MOD;
            else{
                dp[i][j] = dp[i-1][j-1] % MOD;
                dp[i][j] += (dp[i-1][j+1] % MOD);
            }
            ans[i] += (dp[i][j] % MOD);
        }
    }
}

int main(){
    cin >> N;
    memset(dp, 0, sizeof(dp));
    
    solve();
    cout << ans[N] % MOD;
    return 0;
}
