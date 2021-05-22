#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 2e9+7;

int N;
int cost[1001][3];
int dp[1001][3];

int solve(int start){
    dp[0][0] = INF;
    dp[0][1] = INF;
    dp[0][2] = INF;
    dp[0][start] = cost[0][start];

    for(int i = 1; i < N; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + cost[i][2];
    }
    
    int result = INF;
    for(int i = 0; i < 3; i++){
        if(i == start) continue;
        result = min(result, dp[N-1][i]);
    }
    
    return result;
}

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> cost[i][j];
        }
    }
}

int main(){
    input();
    int res = INF;
    for(int i = 0; i < 3; i++){
        res = min(res, solve(i));
    }
    cout << res;
    
    return 0;
}
