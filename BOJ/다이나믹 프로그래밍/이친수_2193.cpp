#include <iostream>
using namespace std;

int N;
long long dp[91] = {0, };

void solve(){
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i = 3; i <= N; i++){
        //끝이 1일 때  끝이 0일 때
        dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[N];
}

int main(){
    cin >> N;
    solve();
    
    return 0;
}
