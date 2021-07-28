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
int wins[13], match[101][13];
int capacity[121][121], flow[121][121];
int Xmatchcnt;

void input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> wins[i];
    }
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
    memset(match, 0, sizeof(match));
    Xmatchcnt = 0;
    
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        match[i][0] = u;
        match[i][1] = v;
        if(!u || !v) Xmatchcnt++;
    }
}

int networkFlow(int source, int sink){
    int total_flow = 0;
    
    while(true){
        vector<int> visited(2+N+M, -1);
        queue<int> que;
        visited[source] = source;
        que.push(source);
        
        while(!que.empty() && visited[sink] == -1){
            int now = que.front();
            que.pop();
            
            for(int next = 0; next < 2+N+M; next++){
                if(capacity[now][next] - flow[now][next] > 0 && visited[next] == -1){
                    que.push(next);
                    visited[next] = now;
                }
            }
        }
        if(visited[sink] == -1) break;
        
        int amount = INF;
        for(int p = sink; p != source; p = visited[p]){
            amount = min(amount, capacity[visited[p]][p] - flow[visited[p]][p]);
        }
        
        for(int p = sink; p != source; p = visited[p]){
            flow[visited[p]][p] += amount;
            flow[p][visited[p]] -= amount;
        }
        
        total_flow += amount;
    }
    
    return total_flow;
}

int winWith(int max_win){
    // 0번 선수는 최대 승리가능 수까지 승리 가능
    capacity[2+M][1] = max_win - wins[0];
    
    // 다른 선수는 최대 승리가능한 수 직전까지 승리가능
    for(int i = 1; i < N; i++){
        capacity[2+M+i][1] = max_win - 1 - wins[i];
        
        // 0번 선수의 단독우승 또는 우승이 불가능한 경우
        if(capacity[2+M+i][1] < 0) return -1;
    }
    
    return networkFlow(0, 1);
}

void solve(){
    // source(0), sink(1), 2~2+M-1 까지 경기, 2+M ~ 2+M+N-1까지 선수
    for(int i = 0; i < M; i++){
        // source(0) 에서 경기로
        capacity[0][i+2] = 1;
        
        // 경기(i+2)에서 선수로
        for(int j = 0; j < 2; j++){
            capacity[i+2][2 + M + match[i][j]] = 1;
        }
    }
    
    int remain_flow = M;
    
    // 승리 하한은 0번 선수가 앞으로의 경기에서 승리x
    // 승리 상한은 0번 선수가 앞으로의 경기에서 모두 승리
    for(int max_win = wins[0]; max_win <= wins[0] + Xmatchcnt; max_win++){
        int new_flow = winWith(max_win);
        if(new_flow == -1) continue;
        
        remain_flow -= new_flow;
        if(remain_flow == 0){
            cout << max_win << "\n";
            return;
        }
    }
    
    cout << -1 << "\n";
}

int main(){
    int C;
    cin >> C;
    while(C--){
        input();
        solve();
    }
    return 0;
}
