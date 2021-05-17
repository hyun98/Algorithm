/*문제
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.

입력
첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.

출력
첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.

20 2
21
*/

#include <iostream>
#include <cstring>
using namespace std;

int N, K, MOD = 1000000000;
long long dp[202][202] = {0, }, res[202];

long long solve(int k){
    
    if(res[k] != -1) return res[k];
    res[k] = 0;
    dp[k][0] = solve(k-1);
    res[k] = (res[k] + dp[k][0]) % MOD;
    
    for(int i = 1; i <= N; i++){
        dp[k][i] = (dp[k][i-1] - dp[k-1][i-1] + MOD) % MOD;
        res[k] = (res[k] + dp[k][i]) % MOD;
    }
    return res[k];
}

inline void input(){
    cin >> N >> K;
    memset(res, -1, sizeof(res));
    res[1] = 1;
    res[2] = (N+1) % MOD;
    for(int i = 0; i <= N; i++){
        dp[2][i] = 1;
    }
}

int main(){
    input();
    cout << solve(K);
    return 0;
}
