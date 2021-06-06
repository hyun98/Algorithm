#include <iostream>
#include <cstring>
using namespace std;

int T, W;
int jadu[1001], dp[1001][31][2];    // [�ð�][������ Ƚ��][��� �ڵ��� ��ġ]

int solve(int cnt, int s, int loc){
    if(cnt >= T) return 0;
    
    int &ret = dp[cnt][s][loc];
    if(ret != -1) return ret;
    
    int a = solve(cnt+1, s, loc);
    int b = 0;
    if(jadu[cnt] == loc) a += 1;
    
    if(s < W){
        b = solve(cnt+1, s+1, 1 - loc);
        if(jadu[cnt] == 1 - loc) b += 1;
    }
    
    ret = max(ret, max(a, b));
    
    return ret;
}

int main(){
    cin >> T >> W;
    for(int i = 0; i < T; i++){
        cin >> jadu[i];
        jadu[i] -= 1;
    }
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 0, 0);
    
    return 0;
}
