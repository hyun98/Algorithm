#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

ll N, P, Q;
map<ll, ll> cache;

void input(){
    cin >> N >> P >> Q;
}

ll recur(ll n){
    
    if(cache.find(n) != cache.end()) return cache[n];
    
    
    return cache[n] = recur(n/P) + recur(n/Q);
}

void solve(){
    cache[0] = 1;
    cout << recur(N);
}

int main(){
    input();
    solve();
    
    return 0;
}
