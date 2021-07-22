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
            // 자신이 도착점인 경우엔 자신의 방해시간이 걸리는 시간이 된다.
            if(r == c) res[r][c] = Bulltime[r].first;
            // r에서 c로가는 최소시간은 r에서 c로가는 거리의 최솟값 + r과 c중 더 오래걸리는 방해시간
            else res[r][c] = dp[r][c] + max(Bulltime[r].first, Bulltime[c].first);
        }
    }
    
    sort(Bulltime+1, Bulltime+N+1);
    
    // 정점 번호를 인덱스로 넣으면 해당 정점이
    // sort된 Bulltime의 몇 번 인덱스에 위치하는지 알 수 있다.
    int Bullidx[501];
    for(int i = 1; i <= N; i++){
        Bullidx[Bulltime[i].second] = i;
    }
    
    for(int i = 1; i <= N; i++){
        int via = Bulltime[i].second;
        for(int r = 1; r <= N; r++){             
            for(int c = 1; c <= N; c++){
                // via, r, c 정점 중 가장 긴 방해시간
                int delay = max(Bulltime[i].first, max(Bulltime[Bullidx[r]].first, Bulltime[Bullidx[c]].first));
                // 최단 거리 계산
                dp[r][c] = min(dp[r][c], dp[r][via] + dp[via][c]);
                // 최단 시간 계산
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
