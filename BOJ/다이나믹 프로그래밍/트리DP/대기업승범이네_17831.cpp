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

int dp[200001][2];
int ability[200001];
int N;
vector<int> adj[200001];

void input(){
    cin >> N;
    int m;
    for(int i = 2; i <= N; i++){
        cin >> m;
        adj[m].push_back(i);
    }
    for(int i = 1; i <= N; i++){
        cin >> ability[i];
    }
    memset(dp, -1, sizeof(dp));
}

int dfs(int now, int mto){
    int &ret = dp[now][mto];
    if(ret != -1) return ret;
    
    ret = 0;
    if(adj[now].empty()) return ret;
    
    if(mto){
        int smte = 0;
        int smto = 0;
        for(auto &next : adj[now]){
            int mte = dfs(next, 0);
            int mto = dfs(next, 1);
            if(mto > mte) smto += mto;
            else          smte += mte;
        }
        
        for(auto &next : adj[now]){
            int mte = dfs(next, 0);
            int mto = dfs(next, 1);
            if(mto > mte) ret = max(ret, smte + smto - mto + ability[now]*ability[next] + mte);
            else          ret = max(ret, smte + smto + ability[now]*ability[next]);
        }
    }
    else{
        for(auto &next : adj[now]){
            ret += max(dfs(next, 0), dfs(next, 1));
        }
    }
    
    return ret;
}

void solve(){
    cout << max(dfs(1, 0), dfs(1, 1)) << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
