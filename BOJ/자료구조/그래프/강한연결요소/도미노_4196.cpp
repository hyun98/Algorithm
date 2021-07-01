#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector< vector<int> > adj;
vector<int> stk;

int sccindegree[100001];
int SCCID[100001];
int Vertexcnt, SCCcnt;
int discovered[100001];

int SCC(int now){
    int ret = discovered[now] = Vertexcnt++;
    
    stk.push_back(now);
    
    for(auto &next : adj[now]){
        if(discovered[next] == -1){
            ret = min(ret, SCC(next));
        }
        else if(SCCID[next] == -1){
            ret = min(ret, discovered[next]);
        }
    }
    
    if(ret == discovered[now]){
        while(1){
            int temp = stk.back();
            stk.pop_back();
            SCCID[temp] = SCCcnt;
            if(temp == now) break;
        }
        SCCcnt++;
    }
    
    return ret;
}

void init(){
    memset(discovered, -1, sizeof(discovered));
    memset(SCCID, -1, sizeof(SCCID));
    memset(sccindegree, 0, sizeof(sccindegree));
    adj.clear();
    adj.resize(N+1, vector<int>());
    Vertexcnt = SCCcnt = 0;
    
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

void solve(){
    int result = 0;
    
    for(int i = 1; i <= N; i++){
        if(discovered[i] != -1) continue;
        SCC(i);
    }
    
    for(int i = 1; i <= N; i++){
        for(auto &w : adj[i]){
            if(SCCID[w] == SCCID[i]) continue;
            sccindegree[SCCID[w]]++;
        }
    }
    
    for(int i = 0; i < SCCcnt; i++){
        if(!sccindegree[i]) result++;
    }
    
    cout << result << "\n";
}

int main(){
    // cout.tie(0)를 넣어주면 런타임에러가 발생한다 왜??
    ios::sync_with_stdio(0), cin.tie(0);
    int test;
    cin >> test;
    while(test--){
        cin >> N >> M;
        
        init();
        solve();
        
    }
    
    return 0;
}