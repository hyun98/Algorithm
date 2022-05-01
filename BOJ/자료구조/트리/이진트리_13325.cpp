#include <iostream>
#include <cmath>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;

int K, tree[1 << 21 + 1];
ll ans;

void input(){
    cin >> K;
    for(int i = 2; i <= (1 << (K+1))-1; i++){
        cin >> tree[i];
    }
}

ll dfs(int node, int h){
    if(h == K){
        ans += tree[node];
        return tree[node];
    }
    
    ll left = dfs(node*2, h+1);
    ll right = dfs(node*2+1, h+1);
    ans += (tree[node] + abs(left - right));
    return tree[node] + max(left, right);
}

void solve(){
    dfs(1, 0);
    cout << ans;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}

//       1        2
//     1   3    2   4
//    1 1 1 1  1 1 1 1

//     1        1000
//   1   1   1000   1000