#include <iostream>

using namespace std;

int dp[501][501];
int tri[501][501];

void solve(int n){
    dp[0][0] = tri[0][0];
    dp[1][0] = tri[1][0] + tri[0][0];
    dp[1][1] = tri[1][1] + tri[0][0];
    
    for(int i = 2; i < n; i++){
        dp[i][0] = tri[i][0] + dp[i-1][0];
        dp[i][i] = tri[i][i] + dp[i-1][i-1];
        for(int j = 1; j < i; j++){
            dp[i][j] = tri[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        result = max(dp[n-1][i], result);
    }
    cout << result;
}

void input(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            cin >> tri[i-1][j];
        }
    }
    solve(n);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    return 0;
}
