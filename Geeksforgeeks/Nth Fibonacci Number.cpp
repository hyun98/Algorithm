#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

class Solution {
    int dp[1001];
    const int MOD = 1000000007;
public:
    long long int nthFibonacci(long long int n){
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2])%MOD;
        }
        return dp[n];
    }
};

int main(){
    Solution S1;
    cout << S1.nthFibonacci(5);
    
    return 0;
}
