#include <iostream>

typedef long long ll;

using namespace std;

ll X, K;

void input(){
    cin >> X >> K;
}

void solve(){
    ll Y = 0;
    int kidx = 0;
    for(int i = 0; i < 65; i++){
        if((X >> i) & 1LL) continue;
        if((K >> kidx) & 1LL){
            Y |= (1LL << i);
        }
        kidx++;
    }
    
    cout << Y;
}

int main(){
    input();
    solve();
    
    return 0;
}
