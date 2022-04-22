#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

// [현재 커피의 번호][카페인의 양] = 카페인을 채우기 위해 최소로 마신 커피의 수
int dp[101][100001];
int N, K;
int Coffee[101];

void input(){
    cin >> N >> K;
    for(int i = 0; i <= N; i++){
        for(int j = 1; j <= K; j++){
            dp[i][j] = INF;
        }
    }
    for(int i = 0; i < N; i++){
        cin >> Coffee[i];
        dp[i][Coffee[i]] = 1;
    }
}

void solve(){
    for(int i = 1; i < N; i++){
        int now_coffee = Coffee[i];
        
        for(int c = 0; c <= K; c++){
            // 음수가 된다는건 어떤 의미?
            // 불가능한거
            if(c - now_coffee < 0) dp[i][c] = dp[i-1][c];
            else{
                int temp = min(dp[i-1][c-now_coffee] + 1, dp[i-1][c]);
                dp[i][c] = min(dp[i][c], temp);
            }
        }
    }
    if (dp[N-1][K] == INF){
        cout << -1;
    }
    else cout << dp[N-1][K];
}

int main(){
    input();
    solve();
    
    return 0;
}
