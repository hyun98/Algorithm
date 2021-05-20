#include <iostream>

using namespace std;

int V[101];   // i번째 곡을 연주하기 전에 바꿀 수 있는 볼륨
// 현재 볼륨이 P이고 지금 i번째 곡을 연주하기 전이라면, i번 곡은 P+V[i]나 P-V[i] 로 연주해야 한다
int dp[101][1001];  // i번째 곡을 연주하기 전에 +-V[i]만큼 볼륨을 컨트롤해서 위치 할 수 있는 볼륨j
int N, S, M;

int main(){
    cin >> N >> S >> M;
    for(int i = 1; i <= N; i++){
        cin >> V[i];
    }
    dp[0][S] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(!dp[i-1][j]) continue;
            if(j - V[i] >= 0) dp[i][j - V[i]] = 1;
            if(j + V[i] <= M) dp[i][j + V[i]] = 1;
        }
    }
    
    int res = -1;
    
    for(int i = 0; i <= M; i++){
        if(dp[N][i]) res = max(res, i);
    }
    
    cout << res;
    
    return 0;
}
