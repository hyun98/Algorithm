#include <iostream>

#define MOD 1000000007
using namespace std;

class TILING2{
    int n, dp[101];
    
public:
    TILING2(){
        cin >> n;
    }
    int count_tile(){
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
        return dp[n];
    }
};

int main(){
    int test;
    cin >> test;
    while(test--){
        TILING2 T;
        cout << T.count_tile() << endl;
    }
    return 0;
}
