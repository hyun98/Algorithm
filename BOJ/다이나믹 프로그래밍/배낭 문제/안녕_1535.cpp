#include <iostream>
#include <cstring>
using namespace std;

int N;
int Lost[21], Joy[21];
int dp[21][101];

void input(){
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> Lost[i];
    }
    
    for(int i = 1; i <= N; i++){
        cin >> Joy[i];
    }
    memset(dp, 0, sizeof(dp));
}

void solve(){
    int result = 0;
    
    for(int i = 1; i <= N; i++){
        for(int h = 0; h <= 100; h++){
            // �λ� ����
            if(h + Lost[i] < 100){
                // max(�λ� x,�λ� o)
                // ���� ���� ü���� ���� ���Ե��� ���� ���� �ִ� ���[h+Lost[i]]�� ���� �λ��� ����� ���ؼ� ��
                dp[i][h] = max(dp[i-1][h], dp[i-1][h+Lost[i]] + Joy[i]);
            }
            // �λ� �Ұ���          ���� ��, ���� �� �� ū ��
            else dp[i][h] = max(dp[i][h], dp[i-1][h]); 
            
            if(dp[i][h] > result) result = dp[i][h];
        }
    }
    cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}
