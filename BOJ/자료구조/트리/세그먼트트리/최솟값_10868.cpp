#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define MAX 100001
typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int arr[MAX];
int tree[MAX * 4];
int N, M;

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

int make_tree(int startidx, int endidx, int node){
    if(startidx == endidx){
        return tree[node] = arr[startidx];
    }
    int mid = (startidx + endidx) / 2;
    return tree[node] = min(make_tree(startidx, mid, node*2), \
                            make_tree(mid+1, endidx, node*2+1));
}

int findmin(int startidx, int endidx, int targetlidx, int targetridx, int node){
    if(targetlidx > endidx || targetridx < startidx) return INF;
    if(targetlidx <= startidx && endidx <= targetridx) return tree[node];
    
    int mid = (startidx + endidx) / 2;
    int t1 = findmin(startidx, mid, targetlidx, targetridx, node*2);
    int t2 = findmin(mid+1, endidx, targetlidx, targetridx, node*2+1);
    
    return min(t1, t2);
}

void solve(){
    make_tree(1, N, 1);
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        cout << findmin(1, N, a, b, 1) << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
