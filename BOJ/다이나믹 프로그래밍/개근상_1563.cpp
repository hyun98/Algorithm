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

ll dp[1001][3][1001];
ll N;

ll solve(ll day, ll lazy, ll d){
    ll &ret = dp[day][lazy][d];
    if(ret != -1) return ret % 1000000;
    
    if(lazy >= 2 || d >= 3) return ret = 0;
    if(day == N) return ret = 1;
    
    ret = 0;
    
    ret += ((solve(day+1, lazy, 0) + solve(day+1, lazy+1, 0) + solve(day+1, lazy, d+1)) % 1000000);
    
    return ret;
}

int main(){
    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0) % 1000000;
    
    return 0;
}
