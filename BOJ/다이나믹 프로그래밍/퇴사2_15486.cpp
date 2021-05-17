#include <iostream>
using namespace std;

int N, Ti[1500001], Pi[1500001], dp[1500001] = {0, };

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Ti[i] >> Pi[i];
    }
}

// dynamic programming bottom-up style O(N)
void solve(){
    int result = 0;
    //�ڿ������� Ž�� 
    for(int i = N-1; i >= 0; i--){
        // next : ���� ��¥
        int next = i + Ti[i];
        if(next > N){
            dp[i] = dp[i+1];
        }
        // next�Ͽ� ���� ����, ���� ����
        else{
            dp[i] = max(dp[i+1], dp[next] + Pi[i]);
        }
    }
    cout << dp[0];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    int result = 0;
    
    solve();
    return 0;
}
