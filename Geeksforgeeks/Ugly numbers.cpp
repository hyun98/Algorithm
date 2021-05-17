#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

class Solution{
    ull dp[10001];
public:
    ull getNthUglyNo(int n){
        
        dp[1] = 1;
        ull p2 = 1, p3 = 1, p5 = 1, Min = 999999999;
        
        for(int i = 2; i <= n; i++){
            if(dp[p2] * 2 < dp[p3] * 3) Min = dp[p2] * 2;
            else Min = dp[p3] * 3;
            if(dp[p5] * 5 < Min) Min = dp[p5] * 5;
            
            if(Min == dp[p2] * 2) p2++;
            if(Min == dp[p3] * 3) p3++;
            if(Min == dp[p5] * 5) p5++;
            
            dp[i] = Min;
        }
        
        return dp[n];
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
