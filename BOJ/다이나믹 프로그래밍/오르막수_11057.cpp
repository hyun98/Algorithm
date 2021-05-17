#include <iostream>

using namespace std;

int N, dp[1001][10];

void input(){
    dp[1][0] = 1;
    for(int i = 1; i < 10; i++){
        dp[1][i] = (dp[1][i-1]+1);
    }
    cin >> N;
}

void solve(){
    for(int i = 2; i <= N; i++){
        int psum = 0;
        for(int j = 0; j < 10; j++){
            psum += (dp[i-1][j] % 10007);
            dp[i][j] = psum % 10007;
        }
    }
    cout << dp[N][9] % 10007;
}

int main(){
    input();
    solve();
    
    return 0;
}
