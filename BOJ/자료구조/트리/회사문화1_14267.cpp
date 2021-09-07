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
vector<int> tree[100001];
int compliment[100001];
int result[100001];

void input(){
    cin >> N >> M;
    int s;
    for(int i = 1; i <= N; i++){
        cin >> s;
        if(s == -1) continue;
        tree[s].push_back(i);
    }
    
    int i, w;
    for(int j = 1; j <= M; j++){
        cin >> i >> w;
        compliment[i] += w;
    }
}

void preorder(int node, int sum){
    sum += compliment[node];
    
    result[node] = sum;
    
    for(int i = 0; i < tree[node].size(); i++){
        int next = tree[node][i];
        preorder(next, sum);
    }
}

void solve(){
    preorder(1, 0);
    for(int i = 1; i <= N; i++){
        cout << result[i] << " ";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
