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

int V, E;
int dp[401][401];

void input(){
    cin >> V >> E;
    int a, b, c;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i == j) continue;
            dp[i][j] = INF;
        }
    }
    
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        dp[a][b] = c;
    }
}

void solve(){
    for(int k = 1; k <= V; k++){
        for(int r = 1; r <= V; r++){
            for(int c = 1; c <= V; c++){
                if(dp[r][k] == INF || dp[k][c] == INF) continue;
                dp[r][c] = min(dp[r][c], dp[r][k] + dp[k][c]);
            }
        }
    }
    
    int ans = INF;
    for(int r = 1; r <= V; r++){
        for(int c = 1; c <= V; c++){
            if(r == c) continue;
            // cout << r << "->" << c << " : " << dp[r][c] << "\n";
            ans = min(ans, dp[r][c] + dp[c][r]);
        }
    }
    
    if(ans == INF) cout << -1;
    else cout << ans;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
