#include <iostream>
#include <vector>

#define INF 1e9+7
using namespace std;

int N;
vector<int> graph[101];

int dp[101][101][101];

void solve(){
    for(int i = 1; i <= N; i++){
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= N; c++){
                if(dp[i-1][r][c]) dp[i][r][c] = 1;
                else if(dp[i-1][r][i] && dp[i-1][i][c]) dp[i][r][c] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[0][i][j] = 0;    // 아무것도 경유하지 않고 i -> j 로 가는 경로의 수
        }
    }
    
    int is_link;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> is_link;
            if(is_link){
                graph[i].push_back(j);
                dp[0][i][j] = 1;
            }
        }
    }
    
    solve();
    
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            cout << dp[N][r][c] << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}
