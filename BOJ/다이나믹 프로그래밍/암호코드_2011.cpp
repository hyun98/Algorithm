#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000

int N[5001];
long long dp[5001][2];

void solve(int n){
    dp[n-1][0] = 1;
    dp[n-1][1] = 0;
    
    for(int i = n-2; i >= 0; i--){
        dp[i][0] = (dp[i+1][0] + dp[i+1][1]) % MOD;
        dp[i][1] = dp[i+1][0];
        
        if(N[i] > 2 || (N[i] == 2 && N[i+1] > 6) || N[i] == 0){
            dp[i][1] = 0;
        }
        if(N[i+1] == 0){
            dp[i][0] = 0;
        }
    }
}

int main(){
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        N[i] = str[i] - '0';
    }
    
    solve(str.size());
    
    if(N[0] == 0) cout << 0;
    else cout << (dp[0][0] + dp[0][1]) % MOD;
    
    return 0;
}
