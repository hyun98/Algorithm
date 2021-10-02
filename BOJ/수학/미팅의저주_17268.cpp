#include <iostream>
typedef long long ll;

using namespace std;

const ll MOD = 987654321;
int N;
ll dp[10001];

void solve(){
    dp[0] = 1;
    dp[2] = 1;
    dp[4] = 2;
    dp[6] = 5;
    dp[8] = 14;
    
    for(int i = 10; i <= N; i+=2){
        for(int j = 0; j < i; j+=2){
            dp[i] += ((dp[j] * dp[i-j-2]) % MOD);
        }
        dp[i] %= MOD;
    }
    
    cout << dp[N];
}

int main(){
    cin >> N;
    solve();
    
    return 0;
}
