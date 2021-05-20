#include <iostream>

using namespace std;

long long dp[10001][4];

void init_DP(){
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    
    for (int i = 4; i < 10001; i++) {
        dp[i][1] = 1;   // 1로 시작
        dp[i][2] = dp[i-2][1] + dp[i-2][2]; // 
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init_DP();
    int test, n;
    cin >> test;
    for(int i = 0; i < test; i++){
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
    return 0;
}
