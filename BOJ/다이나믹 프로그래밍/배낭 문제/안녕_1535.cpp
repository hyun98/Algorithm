#include <iostream>
#include <cstring>
using namespace std;

int N;
int Lost[21], Joy[21];
int dp[21][101];

void input(){
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> Lost[i];
    }
    
    for(int i = 1; i <= N; i++){
        cin >> Joy[i];
    }
    memset(dp, 0, sizeof(dp));
}

void solve(){
    int result = 0;
    
    for(int i = 1; i <= N; i++){
        for(int h = 0; h <= 100; h++){
            // 인사 가능
            if(h + Lost[i] < 100){
                // max(인사 x,인사 o)
                // 현재 잃은 체력이 아직 포함되지 않은 이전 최대 기쁨[h+Lost[i]]에 현재 인사의 기쁨을 더해서 비교
                dp[i][h] = max(dp[i-1][h], dp[i-1][h+Lost[i]] + Joy[i]);
            }
            // 인사 불가능          원래 값, 이전 값 중 큰 값
            else dp[i][h] = max(dp[i][h], dp[i-1][h]); 
            
            if(dp[i][h] > result) result = dp[i][h];
        }
    }
    cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}
