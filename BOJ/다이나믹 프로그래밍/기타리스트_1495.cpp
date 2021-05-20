#include <iostream>

using namespace std;

int V[101];   // i��° ���� �����ϱ� ���� �ٲ� �� �ִ� ����
// ���� ������ P�̰� ���� i��° ���� �����ϱ� ���̶��, i�� ���� P+V[i]�� P-V[i] �� �����ؾ� �Ѵ�
int dp[101][1001];  // i��° ���� �����ϱ� ���� +-V[i]��ŭ ������ ��Ʈ���ؼ� ��ġ �� �� �ִ� ����j
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
