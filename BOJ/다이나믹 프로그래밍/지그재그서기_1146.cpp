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

int N;
const int MOD = 1000000;

ll dp[101];
ll combi[101][101];

ll Combination(int n, int r){
    if(r == 0 || r == n) return 1;
    if(r == 1) return n;

    ll &ret = combi[n][r];
    if(ret != -1) return ret;
    return ret = (Combination(n-1, r-1) + Combination(n-1, r)) % MOD;
}

void Alternating_Permutation(){
    // 100!의 경우를 어떻게 줄일까
    // 순열 발견 1, 2, 4, 10, 32 ...
    // Alternating Permutation
    memset(combi, -1, sizeof(combi));
    
    dp[0] = 1;
    dp[1] = 1;
    
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < i; j++){
            dp[i] += (Combination(i-1, j) * dp[j] * dp[i - 1 - j]) % MOD;
        }
        dp[i] /= 2;
        dp[i] %= MOD;
    }
    
    if(N == 1) cout << 1;
    else cout << (dp[N] * 2) % MOD;
}

int cache[101][101];

int solve(int here, int left, int right){
    
}


int main(){
    cin >> N;
    Alternating_Permutation();
    
    return 0;
}
