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

int N;
int tree[MAX * 4];

int make_tree(int startidx, int endidx, int node){
    if(startidx == endidx) return tree[node] = 0;
    int mid = (startidx + endidx) / 2;
    return tree[node] = make_tree(startidx, mid, node*2) + make_tree(mid+1, endidx, node*2+1);
}

// A : 2 -> 사탕 넣는 경우
void update(int startidx, int endidx, int node, int flavornum, int up){
    if(flavornum < startidx || flavornum > endidx) return;
    tree[node] += up;
    if(startidx == endidx) return;
    int mid = (startidx + endidx) / 2;
    update(startidx, mid, node*2, flavornum, up);
    update(mid+1, endidx, node*2+1, flavornum, up);
}

// A : 1 -> targetnum 순위의 사탕 꺼냄
void getQuery(int startidx, int endidx, int node, int targetnum){
    if(startidx == endidx){
        cout << startidx << "\n";
        tree[node]--;
        return;
    }
    int leftnum = tree[node*2];
    int mid = (startidx + endidx) / 2;
    
    if(targetnum <= leftnum) getQuery(startidx, mid, node*2, targetnum);
    else getQuery(mid+1, endidx, node*2+1, targetnum - leftnum);
    
    tree[node]--;
}

void solve(){
    cin >> N;
    int A, B, C;
    for(int i = 0; i < N; i++){
        cin >> A;
        if(A == 1){
            cin >> B;
            getQuery(1, MAX, 1, B);
        }
        else{
            cin >> B >> C;
            update(1, MAX, 1, B, C);
        }
    }
}

int main(){
    fastio
    solve();
    
    return 0;
}
