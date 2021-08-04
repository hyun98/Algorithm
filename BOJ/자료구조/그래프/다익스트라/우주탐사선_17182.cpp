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

struct P{
    int planet;
    int visited;
    int cost;
};

struct cmp{
    bool operator()(P &a, P &b){
        return a.cost > b.cost;
    }
};

int N, K, check;
int Cost[11][11];
// 현재 정점, 지금까지 지나온 경로
int dp[11][1 << 10];

void input(){
    cin >> N >> K;
    int a;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Cost[i][j];
        }
    }
    check = (1 << N) - 1;
    memset(dp, -1, sizeof(dp));
}

void solve(){
    priority_queue<P, vector<P>, cmp> pq;
    pq.push({K, (1 << K), 0});
    
    while(!pq.empty()){
        int now = pq.top().planet;
        int now_cost = pq.top().cost;
        int visit = pq.top().visited;
        pq.pop();
        
        if(dp[now][visit] != -1) continue;
        dp[now][visit] = now_cost;
        
        if(visit == check){
            cout << now_cost << "\n";
            return;
        }
        
        for(int next = 0; next < N; next++){
            if(next == now) continue;
            int next_cost = now_cost + Cost[now][next];
            int visited = visit | (1 << next);
            
            if(dp[next][visited] != -1) continue;
            pq.push({next, visited, next_cost});
        }
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
