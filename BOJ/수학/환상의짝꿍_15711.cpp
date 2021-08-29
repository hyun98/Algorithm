#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define NUM 2000001
typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

ll A, B;
bool check[NUM];
vector<int> primelist;

void input(){
    cin >> A >> B;
}

void che(){
    for(int i = 2; i < NUM; i++){
        if(check[i]) continue;
        primelist.push_back(i);
        
        for(int j = 1; i*j < NUM; j++){
            check[i*j] = true;
        }
    }
}

bool is_prime(ll num){
    for(int i = 0; i < primelist.size() && primelist[i] < num; i++){
        if(!(num % primelist[i])) return false;
    }
    
    return true;
}

void solve(){
    if(A + B <= 3){
        cout << "NO\n";
        return;
    }
    
    if((A + B) % 2 == 0) cout << "YES\n";
    else{
        if(is_prime(A + B - 2)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
    fastio
    int T;
    cin >> T;
    che();
    while(T--){
        input();
        solve();
    }
    
    return 0;
}
