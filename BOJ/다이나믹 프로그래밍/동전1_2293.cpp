#include <iostream>

using namespace std;

int N, K;
int value[101], dp[100001] = {0, };

void input(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> value[i];
    }
    dp[0] = 1;
}
//  idx 0   1   2   3   4   5   6   7   8   9   10  (k)
//  dp  1   0   0   0   0   0   0   0   0   0   0   (초기화)
// for문 반복 시작
//  dp  1   1   1   1   1   1   1   1   1   1   1   (1만 사용하여 k를 만들 수 있는 경우의 수)
//  dp  1   1   2   2   3   3   4   4   5   5   6   (1과 2를 사용하여 k를 만들 수 있는 경우의 수)
//  dp  1   1   2   2   3   4   5   6   7   8   10  (1, 2, 5를 모두 사용하여 k를 만들 수 있는 경우의 수)
void solve(){
    for(int i = 0; i < N; i++){
        for(int j = value[i]; j <= K; j++){
            if(j - value[i] >= 0) dp[j] += dp[j - value[i]];
        }
    }
    cout << dp[K];
}

int main(){
    input();
    solve();
    return 0;
}
