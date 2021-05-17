#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최장 증가 부분수열
class LIS{
    int n;
    vector<int> arr, rarr;
    int dp[1001] ={0, }, dpr[1001] = {0, };

public:
    LIS(){
        cin >> n;
        arr.resize(n+1);
        rarr.resize(n+1);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            rarr[n-i-1] = arr[i];
        }
    }
    
    void solve(){
        for (int now = 0; now < n; now++) {
            if (dp[now] == 0) dp[now] = 1;
            for (int b = 0; b < now; b++) {
                if (arr[now] > arr[b]) {
                    if (dp[now] <= dp[b]) {
                        dp[now] = dp[b] + 1;
                    }
                }
            }
        }
        
        for (int now = 0; now < n; now++) {
            if (dpr[now] == 0) dpr[now] = 1;
            for (int b = 0; b < now; b++) {
                if (rarr[now] > rarr[b]) {
                    if (dpr[now] <= dpr[b]) {
                        dpr[now] = dpr[b] + 1;
                    }
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++){
            result.push_back(dp[i] + dpr[n-i-1] -1);
        }
        sort(result.begin(), result.end(), greater<int>());
        
        cout << result[0];
    }
};

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    LIS l1;
    l1.solve();
    return 0;
}
