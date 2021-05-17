#include <iostream>
#include <vector>
using namespace std;

// ���� ���� �κм���
class LIS{
    int n;
    vector<int> arr;
    int dp[501] ={0, };

public:
    LIS(){
        cin >> n;
        arr.resize(n+1);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
    }
    
    void solve(){
        int longest = 0;
        for(int i = 0; i < n; i++){
            longest = max(findLIS(i), longest);
        }
        cout << longest << endl;
    }
    
    // ����Լ��� ���� top-down���
    int findLIS(int pos){
        if(dp[pos] != 0) return dp[pos];
        
        dp[pos] = 1;
        for(int i = pos + 1; i < n; i++){
            if(arr[pos] < arr[i]){
                dp[pos] = max(dp[pos], 1 + findLIS(i));
            }
        }
        
        return dp[pos];
    }
};

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        LIS l1;
        l1.solve();
    }
    return 0;
}
