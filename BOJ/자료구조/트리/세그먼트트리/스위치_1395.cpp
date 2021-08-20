#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define NUM 100001
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M;

// first : 켜짐  second : 꺼짐
pii tree[NUM * 4];
int lazy[NUM * 4];


int make_tree(int startidx, int endidx, int node){
    if(startidx == endidx) return tree[node].second = 1;
    int mid = (startidx + endidx) / 2;
    return tree[node].second = make_tree(startidx, mid, node*2) + \
                               make_tree(mid+1, endidx, node*2+1);
}

void reverse_lazy(int startidx, int endidx, int node){
    if(lazy[node] % 2){
        swap(tree[node].first, tree[node].second);
        lazy[node] = 0;
        if(startidx != endidx){
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return;
    }
}

// lidx 스위치부터 ridx 스위치까지 뒤집기
void reverse_query(int startidx, int endidx, int lidx, int ridx, int node){
    reverse_lazy(startidx, endidx, node);
    if(lidx > endidx || ridx < startidx) return;
    if(lidx <= startidx && endidx <= ridx){
        swap(tree[node].first, tree[node].second);
        lazy[node] = 0;
        if(startidx != endidx){
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return;
    }
    
    int mid = (startidx + endidx) / 2;
    reverse_query(startidx, mid, lidx, ridx, node*2);
    reverse_query(mid+1, endidx, lidx, ridx, node*2+1);
    tree[node].first = tree[node*2].first + tree[node*2+1].first;
    tree[node].second = tree[node*2].second + tree[node*2+1].second;
}

// lidx 스위치부터 ridx 스위치 중에서 켜져있는 스위치의 개수를 반환
int get_query(int startidx, int endidx, int lidx, int ridx, int node){
    reverse_lazy(startidx, endidx, node);
    if(lidx > endidx || ridx < startidx) return 0;
    if(lidx <= startidx && endidx <= ridx) return tree[node].first;
    
    int mid = (startidx + endidx) / 2;
    return get_query(startidx, mid, lidx, ridx, node*2) + \
           get_query(mid+1, endidx, lidx, ridx, node*2+1);
}

void solve(){
    make_tree(1, N, 1);
    
    int o, s, t;
    for(int i = 0; i < M; i++){
        cin >> o >> s >> t;
        if(o == 0) reverse_query(1, N, s, t, 1);
        else cout << get_query(1, N, s, t, 1) << "\n";
    }
}

int main(){
    fastio
    cin >> N >> M;
    solve();
    
    return 0;
}
