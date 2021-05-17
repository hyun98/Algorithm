#include <iostream>

using namespace std;

class Triangle{
    int n;
    int dp[501][501];
    int tri[501][501];
public:
    Triangle(){
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                cin >> tri[i-1][j];
                dp[i-1][j] = -1;
            }
        }
        solve(n);
    }
    
//    int path2(int y, int x){
//        if(y == n-1) return tri[y][x];
//        
//        if(dp[y][x] != -1) return dp[y][x];
//        return max(path2(y+1, x), path2(y+1, x+1)) + tri[y][x];
//    }
    
    void solve(int n){
        dp[0][0] = tri[0][0];
        dp[1][0] = tri[1][0] + tri[0][0];
        dp[1][1] = tri[1][1] + tri[0][0];
        
        for(int i = 2; i < n; i++){
            dp[i][0] = tri[i][0] + dp[i-1][0];
            dp[i][i] = tri[i][i] + dp[i-1][i-1];
            for(int j = 1; j < i; j++){
                dp[i][j] = tri[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++){
            result = max(dp[n-1][i], result);
        }
        cout << result << endl;
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        Triangle T1;
    }
    return 0;
}
