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

int N, M, Q;
pii Bulltime[501];
int dp[501][501];
int res[501][501];
pii Query[40001];

void input(){
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++){
        cin >> Bulltime[i].first;
        Bulltime[i].second = i;
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j){
                dp[i][j] = Bulltime[i].first;
                continue;
            }
            dp[i][j] = INF;
            res[i][j] = INF;
        }
    }
    
    int a, b, d;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> d;
        dp[a][b] = d;
        dp[b][a] = d;
    }
    
    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        Query[i] = {a, b};
    }
}

void solve(){
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            if(r == c) res[r][c] = Bulltime[r].first;
            else{
                res[r][c] = dp[r][c] + max(Bulltime[r].first, Bulltime[c].first);
            }
        }
    }
    
    sort(Bulltime+1, Bulltime+N+1);
    
    int Bullidx[501];
    for(int i = 1; i <= N; i++){
        Bullidx[Bulltime[i].second] = i;
    }
    
    for(int i = 1; i <= N; i++){
        int via = Bulltime[i].second;
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= N; c++){
                int delay = max(Bulltime[i].first, max(Bulltime[Bullidx[r]].first, Bulltime[Bullidx[c]].first));
                dp[r][c] = min(dp[r][c], dp[r][via] + dp[via][c]);
                res[r][c] = min(res[r][c], dp[r][via] + delay + dp[via][c]);
            }
        }
    }
    
    for(int i = 0; i < Q; i++){
        int ans = res[Query[i].first][Query[i].second];
        if(ans >= INF) cout << -1 <<"\n";
        else cout << ans << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
