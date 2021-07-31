#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<ll, ll>
#define MAX 1000001
typedef long long ll;
// typedef pair<ll, ll> pii;

using namespace std;

ll N, M, K;
ll arr[MAX];
ll tree[MAX * 4];
const ll MOD = 1000000007;

void input(){
    cin >> N >> M >> K;
    ll a, b, c;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

ll make_tree(int startidx, int endidx, int node){
    if(startidx == endidx) return tree[node] = arr[startidx];
    int mid = (startidx + endidx) / 2;
    return tree[node] = (make_tree(startidx, mid, node*2) * \
                         make_tree(mid+1, endidx, node*2+1)) % MOD;
}

ll update_tree(int startidx, int endidx, int targetidx, ll update, int node){
    if(targetidx < startidx || targetidx > endidx) return tree[node];
    if(startidx == endidx) return tree[node] = update;
    
    int mid = (startidx + endidx) / 2;
    return tree[node] = (update_tree(startidx, mid, targetidx, update, node*2) *\
                         update_tree(mid+1, endidx, targetidx, update, node*2+1)) % MOD;
}

ll getQuery(int startidx, int endidx, int targetlidx, int targetridx, int node){
    if(targetridx < startidx || targetlidx > endidx) return 1;
    if(targetlidx <= startidx && endidx <= targetridx) return tree[node];
    int mid = (startidx + endidx) / 2;
    return (getQuery(startidx, mid, targetlidx, targetridx, node*2) * \
            getQuery(mid+1, endidx, targetlidx, targetridx, node*2+1)) % MOD;
}

void solve(){
    make_tree(1, N, 1);
    
    ll a, b, c;
    for(int i = 0; i < M + K; i++){
        cin >> a >> b >> c;
        if(a == 1){
            update_tree(1, N, b, c, 1);
            arr[b] = c;
        }
        else if(a == 2) cout << getQuery(1, N, b, c, 1) << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
