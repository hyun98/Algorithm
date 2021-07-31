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

int N, Q;
ll arr[100001];
ll tree[400004];

void input(){
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

ll make_tree(int startidx, int endidx, int node){
    if(startidx == endidx) return tree[node] = arr[startidx];
    int mid = (startidx + endidx) / 2;
    return tree[node] = make_tree(startidx, mid, node*2) + \
                        make_tree(mid+1, endidx, node*2+1);
}

ll getquery(int startidx, int endidx, int targetlidx, int targetridx, int node){
    if(targetridx < startidx || targetlidx > endidx) return 0;
    if(targetlidx <= startidx && endidx <= targetridx) return tree[node];
    int mid = (startidx + endidx) / 2;
    return getquery(startidx, mid, targetlidx, targetridx, node*2) + \
           getquery(mid+1, endidx, targetlidx, targetridx, node*2+1);
}

ll update(int startidx, int endidx, int targetidx, ll up, int node){
    if(targetidx < startidx || targetidx > endidx) return tree[node];
    if(startidx == endidx) return tree[node] = up;
    int mid = (startidx + endidx) / 2;
    return tree[node] = update(startidx, mid, targetidx, up, node*2) + \
                        update(mid+1, endidx, targetidx, up, node*2+1);
}

void solve(){
    make_tree(1, N, 1);
    ll x, y, a, b;
    for(int i = 0; i < Q; i++){
        cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        cout << getquery(1, N, x, y, 1) << "\n";
        update(1, N, a, b, 1);
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
