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

int N, D, C;
vector<pii > Node[10001];

void input(){
    for(int i = 0; i < 10001; i++){
        Node[i].clear();
    }
    
    cin >> N >> D >> C;
    int a, b, s;
    for(int i = 0; i < D; i++){
        cin >> a >> b >> s;
        Node[b].push_back({s, a});
    }
}

struct cmp{
    bool operator()(pii &a, pii &b){
        return a.first > b.first;
    }
};

void solve(){
    int cnt = 0;
    int ansTime = 0;
    
    int timeCache[10001];
    for(int i = 0; i < 10001; i++){
        timeCache[i] = INF;
    }
    // memset(timeCache, INF, sizeof(timeCache));
    
    priority_queue<pii, vector<pii >, cmp> pq;
    pq.push({0, C});
    timeCache[C] = 0;
    
    while(!pq.empty()){
        int now = pq.top().second;
        int nowTime = pq.top().first;
        pq.pop();
        
        if(nowTime > timeCache[now]) continue;
        
        for(int i = 0; i < Node[now].size(); i++){
            int next = Node[now][i].second;
            int nextTime = Node[now][i].first + nowTime;
            
            if(nextTime >= timeCache[next]) continue;
            
            timeCache[next] = nextTime;
            pq.push({nextTime, next});
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(timeCache[i] == INF) continue;
        ansTime = max(ansTime, timeCache[i]);
        cnt++;
    }
    
    cout << cnt << " " << ansTime << '\n';
    
}

int main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
    }
    
    return 0;
}
