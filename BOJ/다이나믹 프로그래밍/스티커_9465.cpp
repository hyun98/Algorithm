#include <iostream>
#include <cstring>

using namespace std;

int N, stick[2][100001];
int dp[2][100001];

int solve(int r, int c){
    if(c >= N) return 0;
    
    int &ret = dp[r][c];
    if(ret != -1) return ret;
    
    ret = stick[r][c];
    ret += max(solve(1-r, c+1), solve(1-r, c+2));
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < N; j++){
                cin >> stick[i][j];
            }
        }
        
        int res = max(solve(0, 0), solve(1, 0));
        cout << res << "\n";
    }
    return 0;
}
