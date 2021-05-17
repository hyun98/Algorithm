#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long d[1000001];
long long temp[1000001];

long long DP(int x){
    temp[2] = 1;
    d[0] = 0;
    d[1] = 2;
    d[2] = 7;
    
    for(int i = 3; i <= x; i++){
        temp[i] = (temp[i-1] + d[i-3]) % MOD;
        d[i] = (d[i-1]*2 + d[i-2]*3 + temp[i]*2) % MOD;
    }
    return d[x];
}

int main(){
    int n;
    cin >> n;
    cout << DP(n);
    return 0;
}
