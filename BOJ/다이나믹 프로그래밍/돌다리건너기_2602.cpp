#include <iostream>
#include <cstring>

using namespace std;

int dp[101][2][21];
string Sq, Bridge[2];

int solve(int now_idx, int now_b, int sq_idx){
    if(sq_idx == Sq.size()) return 1;
    
    int &ret = dp[now_idx][now_b][sq_idx];
    if(ret != -1) return ret;
    
    ret = 0;
    
    for(int i = now_idx; i < Bridge[0].size(); i++){
        if(Bridge[now_b][i] == Sq[sq_idx]){
            ret += solve(i+1, !now_b, sq_idx+1);
        }
    }
    
    return ret;
}

int main(){
    int result = 0;
    cin >> Sq >> Bridge[0] >> Bridge[1];
    
    memset(dp, -1, sizeof(dp));
    
    result += solve(0, 0, 0);   // 악마 먼저
    result += solve(0, 1, 0);   // 천사 먼저
    
    cout << result;
    
    return 0;
}