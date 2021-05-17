#include <iostream>
using namespace std;

int N;
int grape[10001] = {0, } ,dp[10001] = {0, };
inline void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> grape[i];
    }
}

void solve(){
    dp[1] = grape[1];
    dp[2] = grape[2] + grape[1];
    int result = max(dp[1], dp[2]);
    
    for(int i = 3; i <= N; i++){
        //i��° �����ָ� �����ϴ� ���
        dp[i] = max(grape[i-1] + dp[i-3], dp[i-2]) + grape[i];
        //i��° �����ָ� �������� �ʴ� ���
        dp[i] = max(dp[i], dp[i-1]);
        
        result = max(result, dp[i]);
    }
    
    cout << result;
}

int main(){
    input();
    solve();
    return 0;
}
