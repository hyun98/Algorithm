#include <iostream>
#include <cstring>
#define INF 1e9+7
using namespace std;

int N, K;
int bright[202];
int dp[201][201];

int solve(int st, int ed){
    if(st == ed) return 0;
    
    int &ret = dp[st][ed];
    if(ret != -1) return ret;
    
    ret = INF;
    
    for(int i = st; i < ed; i++){
        int temp = (bright[st] == bright[i+1]? 0 : 1);
        ret = min(ret, solve(st, i) + solve(i + 1, ed) + temp);
    }
    
    return ret;
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> bright[i];
    }
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, N-1);
    return 0;
}