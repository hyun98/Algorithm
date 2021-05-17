#include <iostream>
#include <cstring>

using namespace std;

int N, arr[1001]={0, }, dp[1001];

inline void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < 1000; i++){
        dp[i] = 1;
    }
}

void solve(){
    
    int result = 1;
    
    for(int i = 1; i <= N; i++){
        int start = arr[i];
        for(int j = 1; j < i; j++){
            int now = arr[j];
            if(start > now){
                dp[i] = max(dp[i], dp[j]+1);
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
