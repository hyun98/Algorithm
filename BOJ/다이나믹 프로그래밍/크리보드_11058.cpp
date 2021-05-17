#include <iostream>

using namespace std;

int N;
long long dp[101] = {0, };

void init__DP(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;
    
    for(int i = 7; i <= N; i++){
        dp[i] = dp[i-1] + 1;
        for(int j = i - 5; j <= i-3; j++){
            dp[i] = max(dp[i], dp[j] * (i-j-1));
        }
    }
    
    cout << dp[N];
}

int main(){
    cin >> N;
    init__DP();
    
    return 0;
}