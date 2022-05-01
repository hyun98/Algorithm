#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

struct Node{
    int now;
    int left;
    int right;
};

int N;
ll K;
Node tree[200001];

void input(){
    cin >> N;
    int u, v;
    for(int i = 1; i <= N; i++){
        cin >> u >> v;
        tree[i].now = i;
        tree[i].left = u;
        tree[i].right = v;
    }
    
    cin >> K;
}

void solve(){
    int nowNode = 1;
    
    while(true){
        if(tree[nowNode].left == -1 && tree[nowNode].right == -1) break;
        else if(tree[nowNode].left == -1) nowNode = tree[nowNode].right;
        else if(tree[nowNode].right == -1) nowNode = tree[nowNode].left;
        else if(K % 2){
            nowNode = tree[nowNode].left;
            K /= 2;
            K++;
        }
        else{
            nowNode = tree[nowNode].right;
            K /= 2;
        }
    }
    
    cout << nowNode;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
