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

int N, M;
vector<int> company[100001];
int tree[100001 * 4];
int lazy[100001 * 4];
pii segment[100001];

void input(){
    cin >> N >> M;
    int t;
    for(int i = 1; i <= N; i++){
        cin >> t;
        if(t == -1) continue;
        company[t].push_back(i);
    }
}

void preorder(int node, int &idx){
    segment[node].first = idx;
    
    for(int i = 0; i < company[node].size(); i++){
        int next = company[node][i];
        preorder(next, ++idx);
    }
    segment[node].second = idx;
}

void update_lazy(int startidx, int endidx, int node){
    if(lazy[node]){
        tree[node] += lazy[node];
        if(startidx != endidx){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int startidx, int endidx, int left, int right, int node, int value){
    update_lazy(startidx, endidx, node);
    if(right < startidx || left > endidx) return;
    if(left <= startidx && endidx <= right){
        tree[node] += value;
        if(startidx != endidx){
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
        return;
    }
    int mid = (startidx + endidx) / 2;
    
    update(startidx, mid, left, right, node*2, value);
    update(mid+1, endidx, left, right, node*2+1, value);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int getQuery(int startidx, int endidx, int target, int node){
    update_lazy(startidx, endidx, node);
    if(target < startidx || target > endidx) return 0;
    if(startidx == endidx && startidx == target) return tree[node];
    
    int mid = (startidx + endidx) / 2;
    
    return getQuery(startidx, mid, target, node*2) + \
           getQuery(mid+1, endidx, target, node*2+1);
}

void solve(){
    int idx = 1;
    preorder(1, idx);
    
    int s, i, w;
    pii seg;
    for(int j = 0; j < M; j++){
        cin >> s;
        if(s == 1){
            cin >> i >> w;
            seg = segment[i];
            update(1, N, seg.first, seg.second, 1, w);
        }
        else{
            cin >> i;
            seg = segment[i];
            cout << getQuery(1, N, seg.first, 1) << "\n";
        }
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
// 6 10
// -1 1 1 3 2 2
// 1 2 2
// 1 5 5
// 1 6 3
// 1 4 4
// 2 1
// 2 2
// 2 3
// 2 4
// 2 5
// 2 6