#include <iostream>

using namespace std;

int n, box[1001], dp[1001];

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> box[i];
        dp[i] = 1;
    }
}

void solve(){
    int result = 0;
    for(int i = 0; i < n; i++){
        int temp = dp[i];
        for(int j = 0; j < i; j++){
            if(box[i] > box[j]){
                dp[i] = max(dp[i], temp + dp[j]);
            }
            result = max(result, dp[i]);
        }
    }
    cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}
