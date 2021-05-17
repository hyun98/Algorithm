#include <iostream>

using namespace std;

class Triangle{
    int n;
    int dp[101][101];
    int cdp[101][101];
    int tri[101][101];
public:
    Triangle(){
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                cin >> tri[i-1][j];
                dp[i-1][j] = -1;
                cdp[i-1][j] = -1;
            }
        }
    }
    
    int make_dp(int row, int col){
        if(row == n-1) return tri[row][col];
        int &ret = dp[row][col];
        if(ret != -1) return ret;
        
        return ret = max(make_dp(row+1, col), make_dp(row+1, col+1)) + tri[row][col];
        
    }
    
    int path_cnt(int y, int x){
        if(y == n-1) return 1;
        int& ret = cdp[y][x];
        if(ret != -1) return ret;
        ret = 0;
        
        if(make_dp(y+1, x+1) >= make_dp(y+1, x)){
            ret += path_cnt(y+1, x+1);
        }
        if(make_dp(y+1, x+1) <= make_dp(y+1, x)){
            ret += path_cnt(y+1, x);
        }
        return ret;
    }
    
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        Triangle T1;
        T1.make_dp(0, 0);
        cout << T1.path_cnt(0, 0) << endl;
    }
    return 0;
}
