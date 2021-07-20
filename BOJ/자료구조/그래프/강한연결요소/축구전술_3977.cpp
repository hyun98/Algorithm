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
vector< vector<int> > adj;
int discovered[100001];
int SCCID[100001];
int sccindegree[100001];
int Vcnt;
int SCCcnt;

void init(){
    cin >> N >> M;
    
    memset(discovered, -1, sizeof(discovered));
    memset(SCCID, -1, sizeof(SCCID));
    memset(sccindegree, 0, sizeof(sccindegree));
    adj.clear();
    adj.resize(N+1, vector<int>());
    Vcnt = SCCcnt = 0;
    
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

vector<int> stk;

int findSCC(int now){
    int ret = discovered[now] = Vcnt++;
    stk.push_back(now);
    
    for(auto &next : adj[now]){
        if(discovered[next] == -1){
            ret = min(ret, findSCC(next));
        }
        else if(SCCID[next] == -1){
            ret = min(ret, discovered[next]);
        }
    }
    
    if(discovered[now] == ret){
        while(true){
            int temp = stk.back();
            stk.pop_back();
            SCCID[temp] = SCCcnt;
            if(temp == now) break;
        }
        SCCcnt++;
    }
    
    return ret;
}

void solve(){
    for(int i = 0; i < N; i++){
        if(discovered[i] != -1) continue;
        findSCC(i);
    }
    
    for(int i = 0; i < N; i++){
        for(auto &w : adj[i]){
            if(SCCID[w] == SCCID[i]) continue;
            sccindegree[SCCID[w]]++;
        }
    }
    
    vector<int> temp;
    for(int i = 0; i < SCCcnt; i++){
        if(!sccindegree[i]){
            temp.push_back(i);
        }
    }
    if(temp.size() > 1 || temp.empty()){
        cout << "Confused\n";
    }
    else{
        for(int i = 0; i < N; i++){
            if(SCCID[i] == temp[0]){
                cout << i << "\n";
            }
        }
    }
    cout << "\n";
}

int main(){
    fasti
    int test;
    cin >> test;
    while(test--){
        init();
        solve();    
    }
    
    return 0;
}
