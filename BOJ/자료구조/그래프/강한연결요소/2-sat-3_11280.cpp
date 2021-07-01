#include <iostream>
#include <vector>
#include <cstring>

#define offset 10000

using namespace std;

int N, M;

vector<int> Vertex[20002];
int SCCnum[20002];
vector<int> stk;
int discovered[20002];

int sccCounter, vertexCounter;

int opp(int v){
    if(v < offset) return v + offset;
    else return v - offset;
}

void input(){
    cin >> N >> M;
    int u, v, a, b;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        v = (v < 0? abs(v) + offset : v);
        u = (u < 0? abs(u) + offset : u);
        Vertex[opp(u)].push_back(v);
        Vertex[opp(v)].push_back(u);
    }
    
    memset(discovered, -1, sizeof(discovered));
    memset(SCCnum, -1, sizeof(SCCnum));
}

int SCC(int now){
    int ret = discovered[now] = vertexCounter++;
    stk.push_back(now);
    
    for(int i = 0; i < Vertex[now].size(); i++){
        int next = Vertex[now][i];
        
        if(discovered[next] == -1){
            ret = min(ret, SCC(next));
        }
        else if(SCCnum[next] == -1){
            ret = min(ret, discovered[next]);
        }
    }
    
    if(ret == discovered[now]){
        while(true){
            int temp = stk.back();
            stk.pop_back();
            SCCnum[temp] = sccCounter;
            if(temp == now) break;
        }
        sccCounter++;
    }
    
    return ret;
}

int solve(){
    
    for(int i = 1; i <= 2*N; i++){
        if(discovered[i] != -1) continue;
        SCC(i);
    }
    
    for(int i = 1; i <= N; i++){
        if(SCCnum[i] == SCCnum[i+offset]) return 0;
    }
    return 1;
}

int main(){
    input();
    cout << solve();
    
    return 0;
}