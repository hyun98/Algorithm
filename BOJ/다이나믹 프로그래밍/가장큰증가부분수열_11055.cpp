#include <iostream>

using namespace std;

int N;
int arr[1001], dp[1001] = {0, };

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void solve(){
    dp[0] = arr[0];
    int result = dp[0];
    for(int i = 0; i < N; i++){
        dp[i] = arr[i]; 
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        result = max(result, dp[i]);
    }
    cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}