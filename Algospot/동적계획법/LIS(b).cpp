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
    // bottom-up ���
    void solve(){
        int res = 0, temp;
        for (int now = 0; now < n; now++) {
            if (dp[now] == 0) dp[now] = 1;
            for (int b = 0; b < now; b++) {
                // ���� ���� ���� ������ ũ��
                // ���� ���� dp������ ���簪�� dp���� ���ų� �۴ٸ�
                // (������ �����ϹǷ�) +1
                if (arr[now] > arr[b]) {
                    if (dp[now] <= dp[b]) {
                        dp[now] = dp[b] + 1;
                    }
                }
                temp = max(dp[now], dp[b]);
                res = max(res, temp);
            }
        }
        cout << res << endl;
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
