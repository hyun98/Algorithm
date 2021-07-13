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

int cost[10001];
int dp[10001][2];
int N;
bool visited[10001];
vector<int> Tree[10001];
vector<int> Path;

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> cost[i];
    }
    
    int a, b;
    for(int i = 1; i < N; i++){
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
}

void dfs(int now){
    // now가 독립집합에 포함될 때
    // 포함되지 않을 때
    dp[now][0] = 0;
    dp[now][1] = cost[now];
    
    visited[now] = true;
    
    for(int i = 0; i < Tree[now].size(); i++){
        int next = Tree[now][i];
        if(visited[next]) continue;
        
        dfs(next);
        dp[now][0] += max(dp[next][0], dp[next][1]);
        dp[now][1] += dp[next][0];
    }
}

void tracing(int now, int prev){
    if(dp[now][1] > dp[now][0] && !visited[prev]){
        Path.push_back(now);
        visited[now] = true;
    }
    
    for(int i = 0; i < Tree[now].size(); i++){
        int next = Tree[now][i];
        if(next == prev) continue;
        tracing(next, now);
    }
}

void solve(){
    dfs(1);
    memset(visited, 0, sizeof(visited));
    tracing(1, 0);
    
    sort(Path.begin(), Path.end());
    
    cout << max(dp[1][0], dp[1][1]) << "\n";
    for (auto &w : Path){
        cout << w << " ";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
