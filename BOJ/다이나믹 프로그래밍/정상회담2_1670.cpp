#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define MOD 987654321

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N;
ll dp[10001];

void solve(){
    dp[0] = 1;
    
    for(int i = 2; i <= N; i+=2){
        for(int j = 0; j <= i-2; j+=2){
            dp[i] = (dp[i] + ((dp[j] * dp[i-2-j]) % MOD)) % MOD;
        }
    }
    
    cout << dp[N] % MOD;
}

int main(){
    cin >> N;
    solve();
    
    return 0;
}
