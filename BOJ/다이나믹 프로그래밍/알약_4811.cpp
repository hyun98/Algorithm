#include <iostream>
#include <cstring>

using namespace std;

int N;
long long dp[61][61];

long long solve(int one, int half){
    if(!one) return 1;
    
    long long &ret = dp[one][half];
    if(ret != -1) return ret;
    
    ret = 0;
    
    if(one > 0){
        // 한 조각 약을 먹고 반 조각을 추가
        ret += solve(one-1, half+1);
    }
    if(half > 0){
        // 반 조각을 먹는다
        ret += solve(one, half-1);
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    while(N){
        memset(dp, -1, sizeof(dp));
        cout << solve(N-1, 1) << "\n";
        cin >> N;
    }
    
    return 0;
}
