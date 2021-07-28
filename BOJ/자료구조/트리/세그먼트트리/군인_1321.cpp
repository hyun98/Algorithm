#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define MAX 500001

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;


int N, M;
ll arr[MAX];
ll tree[MAX * 4];

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

ll make_tree(int startnode, int endnode, int nownode){
    if(startnode == endnode) return tree[nownode] = arr[startnode]; 
    int mid = (startnode + endnode) / 2;
    return tree[nownode] = make_tree(startnode, mid, nownode*2) + \
                           make_tree(mid+1, endnode, nownode*2+1);
}

void update(int startnode, int endnode, int targetnode, int nownode, ll val){
    if(targetnode < startnode || targetnode > endnode) return;
    tree[nownode] += val;
    if(startnode == endnode) return;
    int mid = (startnode + endnode) / 2;
    
    update(startnode, mid, targetnode, nownode*2, val);
    update(mid+1, endnode, targetnode, nownode*2+1, val);
}

void arrangement(int startnode, int endnode, int nownode, ll soldiernum){
    if(startnode == endnode){
        cout << startnode << "\n";
        return;
    }
    ll left_barracks = tree[nownode*2];
    int mid = (startnode + endnode) / 2;
    
    if(soldiernum <= left_barracks){
        arrangement(startnode, mid, nownode*2, soldiernum);
    }
    else{
        arrangement(mid+1, endnode, nownode*2+1, soldiernum - left_barracks);
    }
}

void solve(){
    make_tree(1, N, 1);
    cin >> M;
    int s, i;
    ll v;
    for(int k = 0; k < M; k++){
        cin >> s;
        switch (s){
        case 1:
            cin >> i >> v;
            update(1, N, i, 1, v);
            break;
        case 2:
            cin >> i;
            arrangement(1, N, 1, i);
            
        default: break;
        }
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
