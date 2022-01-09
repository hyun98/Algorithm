#include <iostream>
#include <set>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define NUM 200001
#define MOD 1000000007
typedef long long ll;
#define pll pair<ll, ll>

using namespace std;


pll tree[NUM * 4];
int N;

void input(){
    cin >> N;
}

pll makeTree(int s, int e, int node, int coord){
    if(coord < s || coord > e){
        return tree[node];
    }
    if(s == e && s == coord){
        tree[node].first++;
        tree[node].second += coord;
        return tree[node];
    }
    int mid = (s + e) / 2;
    pll left = makeTree(s, mid, node*2, coord);
    pll right = makeTree(mid+1, e, node*2+1, coord);
    tree[node].first = (left.first + right.first);
    tree[node].second = (left.second + right.second);
    return tree[node];
}

pll leftQuery(int s, int e, int node, int coord){
    if(e < coord) return tree[node];
    if(coord <= s) return {0, 0};
    
    int mid = (s + e) / 2;
    pll left = leftQuery(s, mid, node*2, coord);
    pll right = leftQuery(mid+1, e, node*2+1, coord);
    ll first = (left.first + right.first);
    ll second = (left.second + right.second);
    return {first, second};
}

pll rightQuery(int s, int e, int node, int coord){
    if(s > coord) return tree[node];
    if(coord >= e) return {0, 0};
    
    int mid = (s + e) / 2;
    pll left = rightQuery(s, mid, node*2, coord);
    pll right = rightQuery(mid+1, e, node*2+1, coord);
    ll first = (left.first + right.first);
    ll second = (left.second + right.second);
    return {first, second};
}

void solve(){
    int x;
    ll ans = 1, la, ra;
    pll left, right;
    set<int> st;
    for(int i = 1; i <= N; i++){
        cin >> x;
        st.insert(x);
        left = leftQuery(0, NUM, 1, x);
        right = rightQuery(0, NUM, 1, x);
        la = left.first * x - left.second;
        ra = right.second - x * right.first;
        cout << la << ", " << ra << '\n';
        makeTree(0, NUM, 1, x);
        
        if((la + ra) == 0) continue;
        if(i != 1) ans = (((la + ra) % MOD) * ans) % MOD;
    }
    if(st.size() == 1){
        cout << 0;
    }
    else cout << ans;
}

int main(){
    input();
    solve();
    
    return 0;
}
