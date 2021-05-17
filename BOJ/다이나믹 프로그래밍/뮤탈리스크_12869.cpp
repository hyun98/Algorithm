#include <iostream>
#include <cstring>
using namespace std;

int N;

int dp[61][61][61];

int ds[6][3] = {
    {9, 3, 1}, {9, 1, 3},
    {3, 9, 1}, {3, 1, 9},
    {1, 3, 9}, {1, 9, 3}
};

void solve(int s1, int s2, int s3, int cnt){
    int &ret = dp[s1][s2][s3];
    if(ret != -1 && ret <= cnt) return;
    ret = cnt;
    
    if(s1 == 0 && s2 == 0 && s3 == 0) return;
    
    for(int i = 0; i < 6; i++){
        int ns1 = s1 - ds[i][0];
        int ns2 = s2 - ds[i][1];
        int ns3 = s3 - ds[i][2];
        if(ns1 < 0) ns1 = 0;
        if(ns2 < 0) ns2 = 0;
        if(ns3 < 0) ns3 = 0;
        
        solve(ns1, ns2, ns3, cnt+1);
    }
}

int main(){
    int SCV1 = 0, SCV2 = 0, SCV3 = 0;
    
    cin >> N;
    switch (N){
    case 1: cin >> SCV1; break;
    case 2: cin >> SCV1 >> SCV2; break;
    case 3: cin >> SCV1 >> SCV2 >> SCV3; break;
    default: break;
    }
    
    memset(dp, -1, sizeof(dp));
    
    solve(SCV1, SCV2, SCV3, 0);
    
    cout << dp[0][0][0];
    
    return 0;
}