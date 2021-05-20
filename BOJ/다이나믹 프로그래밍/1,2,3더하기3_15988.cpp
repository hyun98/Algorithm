#include <iostream>

using namespace std;

long long dp[1000001];
const int MOD = 1000000009;

void init_DP(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i = 4; i <= 1000000; i++){
        dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD + dp[i-3]%MOD)%MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init_DP();
    int test, n;
    cin >> test;
    for(int i = 0; i < test; i++){
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
