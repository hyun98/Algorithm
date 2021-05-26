#include <iostream>
#include <cstring>

using namespace std;

int N, dp[100001][3];

int top_down(int row, int cage){
    
    if(row == N-1) return 1;
    
    int &ret = dp[row][cage];
    if(ret != -1) return ret;
    
    ret = 0;
    
    switch(cage){
        case 0:
        ret += (top_down(row+1, 0) + top_down(row+1, 1) + top_down(row+1, 2))%9901;
        break;
        
        case 1:
        ret += (top_down(row+1, 0) + top_down(row+1, 2))%9901;
        break;
        
        case 2:
        ret += (top_down(row+1, 0) + top_down(row+1, 1))%9901;
        break;
        
        default: break;
    }
    
    return ret % 9901;
}

void bottom_up(){
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i = 2; i <= N; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%9901;
    }
    cout << (dp[N][0] + dp[N][1] + dp[N][2])%9901;
}

int main(){
    cin >> N;
    // memset(dp, -1, sizeof(dp));
    // cout << (top_down(0, 0) + top_down(0, 1) + top_down(0, 2))%9901;
    bottom_up();
    
    return 0;
}