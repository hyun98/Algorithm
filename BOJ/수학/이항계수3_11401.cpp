// ------------------------------------------
//
//                   모르겠다
//                             2021-02-16
// ------------------------------------------

#include <iostream>

using namespace std;
#define MOD 1000000007
int N, K;

int fact(int a){
    long long before = 1;
    for(int i = 1; i <= a; i++){
        before = (before * i) % MOD;
    }
    return before;
}

// a 의 n제곱 (MOD)
int Pow(long long a, int n){
    for(int i = 0; i < n; i++){
        a = (a * a) % MOD;
    }
    return a;
}

void solve(){
    long long a = fact(N);
    int b = fact(N-K);
    int c = fact(K);
    long long div = (b * c) % MOD;
    cout << "분자 : " << a << endl;
    cout << "분모 : " << div << endl;
    int result = (a / div) % MOD;
    cout << result;
}

int main(){
    cin >> N >> K;
    solve();
    return 0;
}
