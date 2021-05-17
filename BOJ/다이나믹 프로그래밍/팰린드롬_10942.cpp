#include <iostream>
#include <cstring>
using namespace std;

int N, M, S, E;
int num[2001], dp[2001][2001];

void palindrome(){
    for(int i = 1; i <= N; i++){
        dp[i][i] = 1;
    }
    for(int i = 1; i < N; i++){
        if(num[i] == num[i+1]){
            dp[i][i+1] = 1;
        }
    }
    
    for(int d = 2; d <= N; d++){
        for(int s = 1; s + d <= N; s++){
            if(dp[s+1][s+d-1] && num[s] == num[s+d]){
                dp[s][s+d] = 1;
            }
        }
    }
//    for(int i = 1; i <= N; i++){
//        for(int j = 1; j <= N; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
}

void solve(){
    palindrome();
    for(int i = 0; i < M; i++){
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }
}

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }
    cin >> M;
    
    memset(dp, 0, sizeof(dp));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    
    return 0;
}
