#include <iostream>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N, TN;
int parr[50001];
int dp[4][50001];

void input(){
    cin >> N;
    int a;
    for(int i = 1; i <= N; i++){
        cin >> a;
        parr[i] = a + parr[i-1];
    }
    cin >> TN;
    
    memset(dp, -1, sizeof(dp));
}

int solve(int tn, int con){
    if(tn == 4 || con > N) return 0;
    
    int &ret = dp[tn][con];
    if(ret != -1) return ret;
    
    ret = 0;
    
    ret = max(solve(tn, con+1), solve(tn+1, con+TN) + parr[con] - parr[con - TN]);
    
    return ret;
}

int main(){
    fastio
    input();
    cout << solve(1, TN);
    
    return 0;
}
