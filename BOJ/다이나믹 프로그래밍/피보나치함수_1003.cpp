#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

pii dp[41];
int dp0[41];

pii fibo(int n){
    if(n == 0) return {1, 0};
    if(n == 1) return {0, 1};
    
    pii &ret = dp[n];
    if(ret.first != -1 && ret.second != -1) return ret;
    
    ret.first = 0;
    ret.second = 0;
    ret.first += (fibo(n-2).first + fibo(n-1).first);
    ret.second += (fibo(n-2).second + fibo(n-1).second);
    return {ret.first, ret.second};
}

int main(){
    int T, a;
    cin >> T;
    while(T--){
        for(int i = 0; i < 41; i++){
            dp[i].first = -1;
            dp[i].second = -1;
        }
        cin >> a;
        cout << fibo(a).first << " " << fibo(a).second << "\n";
    }
    
    return 0;
}
