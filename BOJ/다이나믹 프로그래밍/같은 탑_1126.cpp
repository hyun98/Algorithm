#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, sum = 0;
// dp[i][w]  i개 사용, 높이차 w
int dp[51][500001];
vector<int> top;

void input(){
    cin >> N;
    top.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin >> top[i];
        sum += top[i];
    }
    memset(dp, -1, sizeof(dp));
}

// knapsack 문제와 비슷
void Pile_block(){
    dp[1][0] = 0;   // dp[1][1~sum] = -1;
    dp[1][top[1]] = top[1];
    for(int i = 2; i <= N; i++){
        for(int w = 0; w <= sum; w++){
            //탑을 i-1개 사용하고 높이차가 w일 때가 없는 경우는 탑을 해당 조건에 맞게 쌓는게 불가능한 경우임
            if(dp[i-1][w] == -1) continue;

            //안 쌓는 경우
            //w(높이차)는 그대로이거나 이전까지 쌓은것과 비교해서 큰거
            dp[i][w] = max(dp[i][w], dp[i-1][w]);
            
            //------높은 탑에 올리는 경우------
            // 1.탑 간의 높이차가 증가하는 경우
            dp[i][w + top[i]] = max(dp[i][w + top[i]], dp[i-1][w] + top[i]);

            //------낮은 탑에 올리는 경우------
            // 1.탑의 최대 높이가 바뀌는 경우
            if(top[i] > w) dp[i][top[i]-w] = max(dp[i-1][w] + top[i] - w, dp[i][top[i]-w]);
            
            // 2.탑의 최대높이는 바뀌지 않고 탑 사이의 높이 차가 좁아지는 경우
            else dp[i][w-top[i]] = max(dp[i-1][w], dp[i][w-top[i]]);
            
        }
    }
    
    if(dp[N][0] == 0) cout << "-1";
    else cout << dp[N][0];
}

int main(){
    input();
    Pile_block();
    
    return 0;
}
