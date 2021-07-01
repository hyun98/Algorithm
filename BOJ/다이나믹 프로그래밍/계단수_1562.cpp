#include <iostream>

#define MOD 1000000000
using namespace std;

int N, cmp, res;
long long dp[101][10][1 << 10];

void solve(){
    
    for(int i = 1; i <= 9; i++){
        dp[1][i][1 << i] = 1;
    }
    
    for(int n = 2; n <= 100; n++){
        for(int i = 0; i <= 9; i++){
            for(int k = 0; k < (1 << 10); k++){
                
                // k의 i번째 bit를 on 시킨다
                int offset = k | (1 << i);
                
                // n자리 + i로 끝나고 + 기존 k 상태(여태 사용한 숫자의 모음)에서 숫자 i를 추가하는 경우는
                // n-1자리 + i-1 or i+1로 끝나고 + 기존 상태의 값(숫자 i를 추가하지 않음) 을 더해줘야 한다.
                if(i == 0){
                    dp[n][i][offset] = (dp[n][i][offset] + dp[n-1][1][k]) % MOD;
                }
                else if(i == 9){
                    dp[n][i][offset] = (dp[n][i][offset] + dp[n-1][8][k]) % MOD;
                }
                else{
                    dp[n][i][offset] = (dp[n][i][offset] + dp[n-1][i-1][k]) % MOD;
                    dp[n][i][offset] = (dp[n][i][offset] + dp[n-1][i+1][k]) % MOD;
                }
            }
            
            
        }
    }
    
    int offset = 0;
    long long ans = 0;
    for(int i = 0; i <= 9; i++){
        ans = (ans + dp[N][i][cmp]) % MOD;
    }
    cout << ans;
}

int main(){
    cin >> N;
    
    for(int i = 0; i <= 9; i++){
        cmp |= (1 << i);
    }
    
    solve();
    
    return 0;
}