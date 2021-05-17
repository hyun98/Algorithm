#include <iostream>
#include <cstring>

using namespace std;

int N, stick[2][100001];
int dp[2][100001];

int solve(int r, int c){
    cout << "뭔데\n";
}

int main(){
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
