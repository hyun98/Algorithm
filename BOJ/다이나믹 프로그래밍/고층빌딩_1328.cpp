#include <iostream>

#define MOD 1000000007
using namespace std;

int N, L, R;
long long dp[101][101][101];

void solve(){
    dp[1][1][1] = 1;
    
    for(int n = 2; n <= N; n++){
        for(int l = 1; l <= N; l++){
            for(int r = 1; r <= N; r++){
                dp[n][l][r] = (dp[n-1][l-1][r] + dp[n-1][l][r-1] + dp[n-1][l][r] * (n-2)) % MOD;
            }
        }
    }
    cout << dp[N][L][R];
}

int main(){
    cin >> N >> L >> R;
    solve();
    return 0;
}
