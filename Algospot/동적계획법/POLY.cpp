#include <iostream>
#include <cstring>
using namespace std;

int MOD = 10000000;

class Polyomino{
    int N, dp[101][101];
    
public:
    Polyomino(){
        cin >> N;
        memset(dp, -1, sizeof(dp));
    }
    
    void solve(){
        int result = 0;
        for(int i = 1; i <= N; i++){
            result = (result + polynum(N, i)) % MOD;
        }
        cout << result << endl;
    }
    
    // n���� ���簢������ �̷�� ����, ���� ������ top���� ���簢���� ������ Poly
    int polynum(int n, int top){
        if(n == top) return 1;
        
        int &ret = dp[n][top];
        if(ret != -1) return ret;
        ret = 0;
        
        //���� ���� ���� ���簢���� ���� for��
        for(int i = 1; i <= n-top; i++){
            int mul = top + i - 1;
            mul = mul * polynum(n-top, i);
            mul %= MOD;
            ret += mul;
            ret %= MOD;
        }
        return ret;
    }
};

int main(){
    int test;
    cin >> test;
    while(test--){
        Polyomino P1;
        P1.solve();
    }
    return 0;
}
