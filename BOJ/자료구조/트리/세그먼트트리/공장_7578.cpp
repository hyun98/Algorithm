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

int N;
int Aline[500001];
pii Bline[1000001];
ll tree[4 * 500001];

void input(){
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a;
        Aline[i] = a;
    }
    for(int i = 1; i <= N; i++){
        cin >> b;
        Bline[b] = {b, i};
    }
}

void update(int startidx, int endidx, int targetidx, int node){
    if(startidx > targetidx || targetidx > endidx) return;
    if(startidx == endidx){
        tree[node] = 1;
        return;
    }
    int mid = (startidx + endidx) / 2;
    update(startidx, mid, targetidx, node*2);
    update(mid+1, endidx, targetidx, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll getQuery(int startidx, int endidx, int left, int right, int node){
    if(left <= startidx && endidx <= right) return tree[node];
    if(right < startidx || left > endidx) return 0;
    int mid = (startidx + endidx) / 2;
    
    return getQuery(startidx, mid, left, right, node*2) + \
           getQuery(mid+1, endidx, left, right, node*2+1);
}


void solve(){
    ll answer = 0;
    for(int i = 0; i < N; i++){
        answer += getQuery(1, N, Bline[Aline[i]].second, N, 1);
        update(1, N, Bline[Aline[i]].second, 1);
    }
    
    cout << answer;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
