#include <iostream>
#include <vector>
using namespace std;

// 최장 증가 부분수열
class KLIS{
    int n, k;
    vector<int> arr;
    int dp[501] ={0, };

public:
    KLIS(){
        cin >> n >> k;
        arr.resize(n+1);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
    }
    
    
};

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        KLIS l1;
        l1.solve();
    }
    return 0;
}
