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

int N, M, S, E, maxcost;
vector<pii > adj[100001];
bool visited[100001];

void input(){
    int a, b, c;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
        maxcost = max(c, maxcost);
    }
    cin >> S >> E;
}

bool BFS(int restrict){
    queue<int> que;
    que.push(S);
    visited[S] = true;
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        
        if(now == E) return true;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].second;
            int nextcost = adj[now][i].first;
            
            if(visited[next] || nextcost < restrict) continue;
            visited[next] = true;
            que.push(next);
        }
    }
    return false;
}

void solve(){
    int lo = 0, hi = maxcost;
    while(lo <= hi){
        memset(visited, 0, sizeof(visited));
        int mid = (lo+hi)/2;
        if(BFS(mid)) lo = mid+1;
        else hi = mid-1;
    }
    cout << hi;
}

int main(){
    fasti
    input();
    solve();
    
    return 0;
}
