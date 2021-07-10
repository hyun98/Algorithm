#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M, S, E;
vector<pii > City[1001];
vector<int> dist;
int tracing[1001];

void input(){
    cin >> N >> M;
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        City[a].push_back({c, b});
    }
    cin >> S >> E;
    dist.resize(N+1, INF);
}

void Djikstra(){
    priority_queue<pii, vector<pii>, greater<pii> > heap;
    dist[S] = 0;
    heap.push({0, S});
    
    while(!heap.empty()){
        int min_cost = heap.top().first;
        int now = heap.top().second;
        heap.pop();
        
        if(now == E) break;
        if(min_cost > dist[now]) continue;
        
        for(int i = 0; i < City[now].size(); i++){
            int next = City[now][i].second;
            int next_cost = City[now][i].first + min_cost;
            
            if(dist[next] > next_cost){
                dist[next] = next_cost;
                heap.push({next_cost, next});
                tracing[next] = now;
            }
        }
    }
}

void solve(){
    Djikstra();
    
    vector<int> res;
    int last = E;
    while(last){
        res.push_back(last);
        last = tracing[last];
    }
    cout << dist[E] << "\n";
    cout << res.size() << "\n";
    for (int i = res.size()-1; i >= 0; i--){
        cout << res[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    solve();
    
    return 0;
}
