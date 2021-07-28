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

int N, M, S, P;
bool is_rest[MAX];
bool is_sccrest[MAX];
int discovered[MAX];
int sccnum[MAX];

ll sccmoney[MAX];
ll money[MAX];
ll sccmaxmoney[MAX];

vector<ll> adj[MAX];
vector<int> sccgraph[MAX];
vector<int> stk;

int sccCounter, vertaxCounter;

void input(){
    cin >> N >> M;
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= N; i++){
        cin >> money[i];
    }
    cin >> S >> P;
    for(int i = 0; i < P; i++){
        cin >> u;
        is_rest[u] = true;
    }
    
    memset(discovered, -1, sizeof(discovered));
    memset(sccnum, -1, sizeof(sccnum));
    memset(sccmaxmoney, -1, sizeof(sccmaxmoney));
}

int SCC(int now){
    int ret = discovered[now] = vertaxCounter++;
    stk.push_back(now);
    
    for(int i = 0; i < adj[now].size(); i++){
        int next = adj[now][i];
        
        if(discovered[next] == -1){
            ret = min(ret, SCC(next));
        }
        else if(sccnum[next] == -1){
            ret = min(ret, discovered[next]);
        }
    }
    
    if(ret == discovered[now]){
        ll m = 0;
        bool in_sccrest = false;
        while(true){
            int temp = stk.back();
            stk.pop_back();
            sccnum[temp] = sccCounter;
            m += money[temp];
            if(is_rest[temp]) in_sccrest = true;
            if(temp == now) break;
        }
        sccmoney[sccCounter] = m;
        if(in_sccrest) is_sccrest[sccCounter] = true;
        sccCounter++;
    }
    
    return ret;
}

void make_sccgraph(){
    for(int i = 1; i <= N; i++){
        for(auto &w : adj[i]){
            if(sccnum[w] == sccnum[i]) continue;
            sccgraph[sccnum[i]].push_back(sccnum[w]);
        }
    }
}

ll getmaxmoney(int nowscc){
    ll &ret = sccmaxmoney[nowscc];
    if(ret != -1) return ret;
    
    if(sccgraph[nowscc].empty()){
        if(is_sccrest[nowscc]) return ret = sccmoney[nowscc];
        else return ret = 0;
    }
    
    ret = sccmoney[nowscc];
    ll temp = 0;
    
    for(int i = 0; i < sccgraph[nowscc].size(); i++){
        int nextscc = sccgraph[nowscc][i];
        temp = max(temp, getmaxmoney(nextscc));
    }
    
    if(temp == 0 && !is_sccrest[nowscc]) return ret = 0;

    return ret += temp;
}

void solve(){
    for(int i = 1; i <= N; i++){
        if(discovered[i] == -1){
            SCC(i);
        }
    }
    
    make_sccgraph();
    
    ll res = getmaxmoney(sccnum[S]);
    cout << res << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
