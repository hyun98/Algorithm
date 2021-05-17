#include <iostream>

using namespace std;

int N;
int P[1001], dp[1001] = {0, };

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> P[i];
    }
    dp[0] = 0;
}

void solve(){
    for(int i = 1; i <= N; i++){
        dp[i] = P[i];
        for(int j = 1; j < i; j++){
            dp[i] = max(dp[i], dp[i-j] + dp[j]);
        }
    }
    cout << dp[N];
}

int main(){
    input();
    solve();
    
    return 0;
}
