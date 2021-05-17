#include <iostream>
#include <cstring>
using namespace std;

int N, K;
int I[1001], T[1001];
int dp[1001][10001];

void input(){
    cin >> N >> K;
    for(int i = 1; i <= K; i++){
        cin >> I[i] >> T[i];
    }
    for(int i = 0; i < 10001; i++){
        dp[0][i] = 0;
    }
}

void solve(){
    int result = 0;
    for(int i = 1; i <= K; i++){
        // 현재까지 사용한 공부시간
        for(int j = 0; j <= 10000; j++){
            // 현재 과목을 수강하기위한 조건은
            // 현재까지 사용한 공부시간 + 지금 공부할 과목에 필요한 공부시간이 최대 공부시간보다 같거나 작아야 한다
            if(j + T[i] <= N){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j+T[i]] + I[i]);
            }
            else dp[i][j] = max(dp[i][j], dp[i-1][j]);
            
            if(dp[i][j] > result) result = dp[i][j];
        }
    }
    
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    
    return 0;
}
