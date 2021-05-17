#include <iostream>

using namespace std;

const int INF = 1e9+7;

int dp[101][101][101];
int N, M;

void process(){
    for(int i = 1; i <= N; i++){
        // i까지 경유 가능
        
        //r에서 c까지 갈 때 i이하를 경유가능할 때 최단거리
        for(int r = 1; r <= N; r++){
            
            for(int c = 1; c <= N; c++){
                if(r == c){
                    dp[i][r][c] = 0;
                    continue;
                }
                dp[i][r][c] = min(dp[i-1][r][c], dp[i-1][r][i] + dp[i-1][i][c]);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(dp[N][i][j] >= 1e9+7) cout << 0 << " ";
            else cout << dp[N][i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    int s, d, c;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[0][i][j] = INF;
        }
    }
    
    for(int i = 1; i <= M; i++){
        cin >> s >> d >> c;
        dp[0][s][d] = min(dp[0][s][d], c);
    }
    
    process();
    
    return 0;
}