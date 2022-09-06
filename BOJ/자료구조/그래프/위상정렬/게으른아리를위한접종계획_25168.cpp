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
int indegree[100001];
vector<pii > adj[10001];
int injectionDay[10001];

void input(){
    cin >> N >> M;
    int S, E, W;
    for(int i = 0; i < M; i++){
        cin >> S >> E >> W;
        adj[S].push_back({E, W});
        indegree[E]++;
    }
}

void solve(){
    
    queue<int> que;
    
    for(int i = 1; i <= N; i++){
        if(!indegree[i]){
            injectionDay[i] = 1;
            que.push(i);
        }
    }
    
    while(!que.empty()){
        int now = que.front();
        
        que.pop();
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            int waitDay = adj[now][i].second;
            
            if(waitDay >= 7){
                injectionDay[next] = injectionDay[now] + waitDay + 1;
            }
            else {
                injectionDay[next] = max(injectionDay[next], injectionDay[now] + waitDay);
            }
            
            if(--indegree[next] == 0){
                que.push(next);
            }
        }
        
    }
    
    int answer = 0;
    
    for(int i = 1; i <= N; i++){
        answer = max(injectionDay[i], answer);
    }
    
    cout << answer;
}

int main(){
    input();
    solve();
    
    return 0;
}
