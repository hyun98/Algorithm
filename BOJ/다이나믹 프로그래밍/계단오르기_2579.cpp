#include <iostream>

using namespace std;

int dp[301], stair[301];

int solve(int x){
    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
    for(int i = 3; i < x; i++){
        // 이전 계단을 밟은 경우, 밟지 않은 경우
        dp[i] = max(dp[i-3] + stair[i-1] + stair[i], dp[i-2] + stair[i]);
    }
    
    return dp[x-1];
}

int main(){
    cout << "시작\n";
    int stair_num;
    cin >> stair_num;
    for(int i = 0; i < stair_num; i++){
        cin >> stair[i];
    }
    cout << solve(stair_num);
    
    return 0;
}
