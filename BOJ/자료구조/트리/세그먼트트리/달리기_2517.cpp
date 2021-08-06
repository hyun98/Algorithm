#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define MAX 500001
typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N;
pii arr[MAX];
int tree[MAX * 4];

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
}

int getRank(int startidx, int endidx, int node, int speed){
    if(speed > endidx){
        return tree[node];
    }
    if(startidx > speed || startidx == endidx) return 0;
    int mid = (startidx + endidx) / 2;
    return getRank(startidx, mid, node*2, speed) + getRank(mid+1, endidx, node*2+1, speed);
}

void insert_runner(int startidx, int endidx, int node, int speed){
    if(speed < startidx || speed > endidx) return;
    tree[node] += 1;
    if(startidx == endidx) return;
    int mid = (startidx + endidx) / 2;
    insert_runner(startidx, mid, node*2, speed);
    insert_runner(mid+1, endidx, node*2+1, speed);
}

bool cmp(pii &a, pii &b){
    return a.second < b.second;
}

void solve(){
    sort(arr+1, arr+N+1);
    for(int i = 1; i <= N; i++){
        arr[i].first = i;
    }
    sort(arr+1, arr+N+1, cmp);
    
    for(int i = 1; i <= N; i++){
        cout << i - getRank(1, N, 1, arr[i].first) << "\n";
        insert_runner(1, N, 1, arr[i].first);
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
