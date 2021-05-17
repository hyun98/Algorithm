#include <iostream>
#include <cstring>

using namespace std;

int N, M, sum = 0;
int memory[101], cost[101];
// dp[i][j] : i���� ���� �������� j������� ���� �� �ִ� �ִ��� �޸� ��
int dp[101][10001];

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> memory[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> cost[i];
        sum += cost[i];
    }
    
    memset(dp, 0, sizeof(dp));
}

//void showdp(){
//    for(int i = 0; i < N; i++){
//        for(int j = 0; j <= sum; j++){
//            cout << dp[i][j] <<" ";
//        }
//        cout << endl;
//    }
//}

void solve(){
    int result = 1e8+7;
    // 0��°���� ���� ���� ��, ����� cost[0]��ŭ ���� ���� �� �ִ� �ִ� �޸�
    
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= sum; j++){
            
            if(j >= cost[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i]);
            
            else dp[i][j] = max(dp[i][j], dp[i-1][j]); 
            
            if(dp[i][j] >= M) result = min(result, j);
            
        }
    }
//    showdp();
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    
    return 0;
}
