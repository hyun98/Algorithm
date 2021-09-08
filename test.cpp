#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
 
int n, m;
vector<int> son[100001];
vector<int> tree, lazy, left, right;
 
void preorder(int node, int &cnt){
    left[node] = ++cnt;
    for(int s :son[node]){
        preorder(s, cnt);
    }
    right[node] = cnt;
}
 
void update_lazy(int node, int start, int end){
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(start != end){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
 
void update_range(int node, int start, int end, int l, int r, int w){
    update_lazy(node, start, end);
    if(l > end || r < start) return;
    if(l <= start && end <= r){
        tree[node] += w;
        if(start != end){
            lazy[node * 2] += w;
            lazy[node * 2 + 1] += w;
        }
        return;
    }
    update_range(node * 2, start, (start + end) / 2, l, r, w);
    update_range(node * 2 + 1, (start + end) / 2 + 1, end, l, r, w);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
 
int value(int node, int start, int end, int idx){
    update_lazy(node, start, end);
    if(start > idx || idx > end) return 0;
    if(start == end && start == idx) return tree[node];
    return value(node * 2, start, (start + end)/2, idx) + value(node * 2 + 1, (start + end)/2 + 1, end, idx);
}
 
int main(){
    int t;
    scanf("%d %d", &n, &m);
    left.resize(n+1);
    right.resize(n+1);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1)) - 1;
    tree.resize(tree_size);
    lazy.resize(tree_size);
    scanf("%d", &t);
    for(int i=2; i<=n; i++){
        scanf("%d", &t);
        son[t].push_back(i);
    }
    int cnt = 0;
    preorder(1, cnt);
 
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d", &a, &b);
        if(a == 1){
            scanf("%d", &c);
            update_range(1, 0, n-1, left[b] - 1, right[b] - 1, c);
        }
        else if(a == 2){
            printf("%d\n", value(1, 0, n-1, left[b] -1));
        }
    }
    return 0;
}
