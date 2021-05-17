#include <iostream>
#include <cstring>

using namespace std;

int N, nums[101], sum_result;
long long dp[101][21];

void input(){
    cin >> N;
    for(int i = 0; i < N-1; i++){
        cin >> nums[i];
    }
    cin >> sum_result;
    
    memset(dp, 0, sizeof(dp));
}

// bottom-up style O(N);
void solve(){
    dp[0][nums[0]] = 1;
    
    for(int i = 1; i < N-1; i++){
        for(int j = 0; j < 21; j++){
            if(dp[i-1][j] != 0){
                if(j + nums[i] <= 20) dp[i][j + nums[i]] += dp[i-1][j];
                if(j - nums[i] >= 0) dp[i][j - nums[i]] += dp[i-1][j];
            }
        }
    }
    
//    for(int i = 0; i < N; i++){
//        for(int j = 0; j < 21; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << dp[N-2][sum_result];
}

int main(){
    input();
    solve();
    
    return 0;
}
