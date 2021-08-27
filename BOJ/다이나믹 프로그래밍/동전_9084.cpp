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

int N, M;
int arr[10001];
int dp[10001][21];
vector<int> res;

void input(){
    memset(dp, 0, sizeof(dp));
    int a;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        dp[arr[i]][i] = 1;
    }
    cin >> M;
}

void solve(){
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            if(i - arr[j] < 0) continue;
            for(int k = 0; k <= j; k++){
                dp[i][j] += dp[i-arr[j]][k];
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += dp[M][i];
    }
    
    cout << ans << "\n";
}

int main(){
    fastio
    int T;
    cin >> T;
    while(T--){
        input();
        solve();
    }
    
    return 0;
}
