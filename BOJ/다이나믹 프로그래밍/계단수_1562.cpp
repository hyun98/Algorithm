#include <iostream>

#define MOD 1000000000
using namespace std;

int N, cmp, res;
long long dp[101][10][1 << 10];

void solve(){
    
    for(int i = 1; i <= 9; i++){
        dp[1][i][1 << i] = 1;
    }
    
    for(int n = 2; n <= N; n++){
        for(int i = 0; i <= 9; i++){
            for(int k = 0; k < (1 << 10); k++){
                
                // k�� i��° bit�� on ��Ų��
                int offset = k | (1 << i);
                
                // n�ڸ� + i�� ������ + ���� k ����(���� ����� ������ ����)���� ���� i�� �߰��ϴ� ����
                // n-1�ڸ� + i-1 or i+1�� ������ + ���� ������ ��(���� i�� �߰����� ����) �� ������� �Ѵ�.
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

//int offset = 0;
//long long sum = 0;
//
//if(i == 0){
//    for(int k = 0; k <= 9; k++){
//        if(dp[n-1][i+1][1 << k] > 0){
//            offset |= (1 << k);
//            sum = (sum + dp[n][i-1][1 << k]) % MOD;
//        }
//    }
//    dp[n][i][offset] = sum;
//}
//else if(i == 9){
//    for(int k = 0; k <= 9; k++){
//        if(dp[n-1][i-1][1 << k] > 0){
//            offset |= (1 << k);
//            sum = (sum + dp[n][i-1][1 << k]) % MOD;
//        }
//    }
//    dp[n][i-1][offset] = sum;
//}
//else{
//    for(int k = 0; k <= 9; k++){
//        if(dp[n-1][i-1][1 << k] > 0){
//            offset |= (1 << k);
//            sum = (sum + dp[n][i-1][1 << k]) % MOD;
//        }
//    }
//    dp[n][i][offset] = sum;
//    
//    offset = 0; sum = 0;
//    for(int k = 0; k <= 9; k++){
//        if(dp[n-1][i+1][1 << k] > 0){
//            offset |= (1 << k);
//            sum = (sum + dp[n][i-1][1 << k]) % MOD;
//        }
//    }
//    dp[n][i][offset] = sum;
//}
