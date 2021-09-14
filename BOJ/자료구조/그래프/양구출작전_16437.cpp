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
ll ans;
vector<int> tree[123457];
ll island[123457];

void input(){
    cin >> N;
    char t;
    ll a;
    int p;
    for(int i = 2; i <= N; i++){
        cin >> t >> a >> p;
        tree[p].push_back(i);
        
        if(t == 'S') island[i] = a;
        else island[i] = -a;
    }
}

ll dfs(int now){
    if(tree[now].empty()){
        if(island[now] > 0) return island[now];
        else return 0;
    }
    
    ll sum = 0;
    sum += island[now];
    
    for(int i = 0; i < tree[now].size(); i++){
        int next = tree[now][i];
        sum += dfs(next);
    }
    
    if(sum < 0) return 0;
    return sum;
}

void solve(){
    ans = dfs(1);
    
    cout << ans << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
