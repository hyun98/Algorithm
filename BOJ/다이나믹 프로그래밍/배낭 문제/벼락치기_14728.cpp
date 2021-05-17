#include <iostream>
#include <cstring>
using namespace std;

int N, T;
int K[101], S[101];
int dp[101][10001];

void input(){
    cin >> N >> T;
    for(int i = 1; i <= N; i++){
        cin >> K[i] >> S[i];
    }
    
    memset(dp, 0, sizeof(dp));
}

void solve(){
    int result = 0;
    
    for(int i = 1; i <= N; i++){
        // j = 지금까지 사용한 시간
        for(int j = 0; j <= 10000; j++){
            if(j + K[i] <= T){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j+K[i]] + S[i]);
            }
            else{
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
            if(dp[i][j] > result) result = dp[i][j];
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    
    return 0;
}
