#include <iostream>
#include <cstring>
using namespace std;

const int INF = 999999999;

class File{
    int K, files[501], sum[501], dp[501][501];
    
public:    
    File(){
        cin >> K;
        // ������ ���� �� �������� �����Ѵ�
        for(int i = 1; i <= K; i++){
            cin >> files[i];
            sum[i] = sum[i-1] + files[i];
        }
        memset(dp, 0, sizeof(dp));
    }
    
    void solve(){
        //�� ���� ���� ������ ����
        for(int i = 1; i < K; i++){
            // ���� ����
            for(int st = 1; st + i <= K; st++){
                int ed = i + st;
                // st���� ed���� ���� ���
                dp[st][ed] = INF;
                for(int mid = st; mid < ed; mid++){
//                    cout << "i : " << i << "  " << dp[st][mid] << " " << dp[mid+1][ed] <<endl;
                    dp[st][ed] = min(dp[st][ed], dp[st][mid] + dp[mid+1][ed] + sum[ed] - sum[st-1]);
                }
//                cout << "dp["<< st <<"][" << ed << "]" << " : " << dp[st][ed] <<endl;
            }
        }
        cout << dp[1][K] << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test;
    cin >>test;
    while(test--){
        File f1;
        f1.solve();
    }
    return 0;
}
