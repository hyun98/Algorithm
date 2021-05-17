#include <iostream>

using namespace std;

int visit[12];

int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 2;
    if(x == 3) return 4;
    if(visit[x] != 0) return visit[x];
    
    return visit[x] = dp(x-1) + dp(x-2) + dp(x-3);
}

inline void solve(){
    int n;
    cin >> n;
    cout << dp(n) << "\n";
}

int main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        solve();
    }
    return 0;
}
