/*����
0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ ������ �ٲ� ���� �ٸ� ���� ����(1+2�� 2+1�� ���� �ٸ� ���). ���� �� ���� ���� ���� �� �� ���� �ִ�.

�Է�
ù° �ٿ� �� ���� N(1 �� N �� 200), K(1 �� K �� 200)�� �־�����.

���
ù° �ٿ� ���� 1,000,000,000���� ���� �������� ����Ѵ�.

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
