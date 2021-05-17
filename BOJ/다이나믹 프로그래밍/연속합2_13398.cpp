#include <iostream>

using namespace std;

int N, result = 0;
int arr[100001];
int dp[100001][2];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    dp[1][0] = arr[1];
    dp[1][1] = arr[1];
    
    result = arr[1];
    
    for(int i = 2; i <= N; i++){
        dp[i][0] = max(arr[i], dp[i-1][0] + arr[i]);
        dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-1][0]);
        result = max(result, max(dp[i][0], dp[i][1]));
    }
    
    cout << result;
    
    return 0;
}
