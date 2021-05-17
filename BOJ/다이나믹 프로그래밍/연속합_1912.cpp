#include <iostream>

using namespace std;

int N, arr[100001] = {0, }, dp[100001] = {0, };

inline void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

void solve(){
    dp[1] = arr[1];
    int result = dp[1];
    
    for(int i = 1; i <= N; i++){
        dp[i] = max(arr[i], arr[i] + dp[i-1]);
        cout << dp[i] << endl;
        result = max(result, dp[i]);
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    return 0;
}
