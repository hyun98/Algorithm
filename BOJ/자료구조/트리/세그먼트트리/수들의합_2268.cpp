#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;

#define NUM 1000001

int N, M;
ll arr[NUM];
ll tree[NUM * 4];

ll tree_sum(int startidx, int endidx, int tsidx, int teidx, int node){
    if(tsidx > endidx || teidx < startidx) return 0;
    if(tsidx <= startidx && endidx <= teidx) return tree[node];
    
    int mid = (startidx + endidx) / 2;
    
    return tree_sum(startidx, mid, tsidx, teidx, node*2) + tree_sum(mid+1, endidx, tsidx, teidx, node*2+1);
}

void modify(int startidx, int endidx, int target, int update, int node){
    if(target < startidx || target > endidx) return;
    tree[node] += update;
    
    if(startidx == endidx) return;
    
    int mid = (startidx + endidx) / 2;
    
    modify(startidx, mid, target, update, node*2);
    modify(mid+1, endidx, target, update, node*2+1);
}

void solve(){
    cin >> N >> M;
    int s, a, b;
    int update;
    for(int i = 0; i < M; i++){
        cin >> s >> a >> b;
        if(s == 0){
            if(a > b) swap(a, b);
            cout << tree_sum(1, N, a, b, 1) << '\n';
        }
        else{
            update = b - arr[a];
            arr[a] = b;
            modify(1, N, a, update, 1);
        }
    }
}

int main(){
    fastio
    solve();
    
    return 0;
}
