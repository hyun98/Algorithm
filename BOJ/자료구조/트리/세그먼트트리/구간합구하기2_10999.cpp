#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define MAX 1000001
typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M, K;
ll arr[MAX];
ll tree[MAX * 4];
ll lazy[MAX * 4];

void input(){
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

ll make_tree(int startidx, int endidx, int node){
    if(startidx == endidx) return tree[node] = arr[startidx];
    int mid = (startidx + endidx) / 2;
    return tree[node] = make_tree(startidx, mid, node*2) +\
                        make_tree(mid+1, endidx, node*2+1);
}

void update_lazy(int startidx, int endidx, int node){
    if(lazy[node]){
        tree[node] += (lazy[node] * (endidx - startidx +1));
        if(startidx != endidx){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll getquery(int startidx, int endidx, int lidx, int ridx, int node){
    update_lazy(startidx, endidx, node);
    if(ridx < startidx || lidx > endidx) return 0;
    if(lidx <= startidx && endidx <= ridx) return tree[node];
    int mid = (startidx + endidx) / 2;
    return getquery(startidx, mid, lidx, ridx, node*2) + \
           getquery(mid+1, endidx, lidx, ridx, node*2+1);
}

void update(int startidx, int endidx, int lidx, int ridx, ll up, int node){
    // 미루다가 필요할 때 update한다
    update_lazy(startidx, endidx, node);
    if(ridx < startidx || lidx > endidx) return;
    if(lidx <= startidx && endidx <= ridx){
        tree[node] += (up * (endidx - startidx + 1));
        if(startidx != endidx){
            lazy[node*2] += up;
            lazy[node*2+1] += up;
        }
        return;
    }
    
    int mid = (startidx + endidx) / 2;
    update(startidx, mid, lidx, ridx, up, node*2);
    update(mid+1, endidx, lidx, ridx, up, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void solve(){
    make_tree(1, N, 1);
    int a, b, c;
    ll d;
    for(int i = 0; i < K+M; i++){
        cin >> a;
        if(a & 1){
            cin >> b >> c >> d;
            update(1, N, b, c, d, 1);
        }
        else{
            cin >> b >> c;
            cout << getquery(1, N, b, c, 1) << "\n";
        }
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
