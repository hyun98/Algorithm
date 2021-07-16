#include <iostream>
#include <string.h>
#include <limits>

using namespace std;
#define ll long long
// 최장 증가 부분수열
class JLIS{
    int n, m;
    int A[101], B[101], dp[101][101];
    const ll _INF = numeric_limits<ll>::min();

public:
    JLIS(){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        for(int i = 0; i < m; i++){
            cin >> B[i];
        }
        memset(dp, -1, sizeof(dp));
    }
    
    void solve(){
        
        cout << Jlis(-1, -1) - 2 << endl;
    }
    
    // 재귀함수로 구현
    int Jlis(int indexA, int indexB){
        int &ret = dp[indexA+1][indexB+1];
        if(ret != -1) return ret;
        
        ret = 2;
        
        ll a = (indexA == -1 ? _INF : A[indexA]);
        ll b = (indexB == -1 ? _INF : B[indexB]);
        
        ll maxElement = max(a, b);
        
        // solve의 처음일 때는 a와 b가 모두 numeric min 이다
        for(int nextA = indexA+1; nextA < n; nextA++){
            if(maxElement < A[nextA]){
                ret = max(ret, Jlis(nextA, indexB) + 1);
            }
        }
        for(int nextB = indexB+1; nextB < m; nextB++){
            if(maxElement < B[nextB]){
                ret = max(ret, Jlis(indexA, nextB) + 1);
            }
        }
        
        return ret;
    }
};

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        JLIS l1;
        l1.solve();
    }
    return 0;
}
