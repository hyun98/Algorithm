#include <iostream>
#define lli long long int
using namespace std;

lli dp[21][21][21];

void init_dp(){
    dp[1][1][1] = 1;
    for(int k = 2; k <= 20; k++){
        for(int i = 1; i <= 20; i++){
            for(int j = 1; j <= 20; j++){
                dp[k][i][j] = dp[k-1][i][j] * (k-2) + dp[k-1][i-1][j] + dp[k-1][i][j-1];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, a, b, c;
    init_dp();
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> a >> b >> c;
        cout << dp[a][b][c] << "\n";
    }
    return 0;
}