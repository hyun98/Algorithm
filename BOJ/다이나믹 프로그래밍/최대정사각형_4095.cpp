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

int N, M, answer;
int Map[1001][1001];
int dp[1001][1001];

void solve(){
    for(int r = 2; r <= N; r++){
        for(int c = 2; c <= M; c++){
            if(Map[r][c]){
                dp[r][c] = min(dp[r-1][c-1], min(dp[r][c-1], dp[r-1][c])) + 1;
                answer = max(answer, dp[r][c]);
            }
        }
    }
    cout << answer << "\n";
}

int main(){
    while(true){
        memset(dp, 0, sizeof(dp));
        
        answer = 0;
        cin >> N >> M;
        if(!N && !M) break;
        
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= M; c++){
                cin >> Map[r][c];
                dp[r][c] = Map[r][c];
                answer = max(answer, dp[r][c]);
            }
        }
        solve();
    }
    
    return 0;
}
