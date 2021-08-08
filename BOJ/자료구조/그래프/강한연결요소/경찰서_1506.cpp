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
int cost[101];
vector<int> adj[101];
int discovered[101];
int sccnum[101];
vector<int> stk;
int scccounter, vertexcounter, answer;

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cost[i];
    }
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int k = 0; k < N; k++){
            if(str[k] == '1') adj[i].push_back(k);
        }
    }
    memset(discovered, -1, sizeof(discovered));
    memset(sccnum, -1, sizeof(sccnum));
}

int SCC(int now){
    int ret = discovered[now] = vertexcounter++;
    stk.push_back(now);
    
    for(auto &next: adj[now]){
        if(discovered[next] == -1)  ret = min(ret, SCC(next));
        else if(sccnum[next] == -1) ret = min(ret, discovered[next]);
    }
    
    if(ret == discovered[now]){
        int tempcost = INF;
        while(true){
            int temp = stk.back();
            stk.pop_back();
            tempcost = min(tempcost, cost[temp]);
            sccnum[temp] = scccounter;
            if(temp == now) break;
        }
        answer += tempcost;
        scccounter++;
    }
    
    return ret;
}

void solve(){
    for(int i = 0; i < N; i++){
        if(sccnum[i] != -1) continue;
        SCC(i);
    }
    
    cout << answer << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
