#include <iostream>

using namespace std;

// 찾았다 최장 증가 수열!

int N, child[201], dp[201];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> child[i];
    }
}

void solve(){
    int result = 0;
    for(int i = 0; i < N; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(child[i] > child[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(dp[i], result);
        }
    }
    cout << N - result;
}


int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    
    return 0;
}
