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

int N, M, T, S, G, H;
vector<pii > adj[2001];
int candidate[2001];
int dist[2001];
vector<int> answer;

void input(){
    for(int i = 0; i < 2001; i++){
        adj[i].clear();
        dist[i] = INF;
    }
    answer.clear();
    memset(candidate, 0, sizeof(candidate));
    
    int a, b, d;
    cin >> N >> M >> T >> S >> G >> H;
    
    for(int i = 0; i < M; i++){
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    
    for(int i = 0; i < T; i++){
        cin >> a;
        candidate[a] = 1;
    }
}

struct Node{
    pii road;
    bool check; // g-h를 통과했는지
};

struct cmp{
    bool operator()(Node &a, Node &b){
        return a.road.second > b.road.second;
    }
};

void solve(){
    priority_queue<Node, vector<Node >, cmp> pq;
    pq.push({{S, 0}, false});
    dist[S] = 0;
    
    while(!pq.empty()){
        int now = pq.top().road.first;
        int nowDist = pq.top().road.second;
        bool is_check = pq.top().check;
        pq.pop();
        
        if(dist[now] < nowDist) continue;
        if(is_check && candidate[now] == 1){
            answer.push_back(now);
            candidate[now] == 2;
        }
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            int nextDist = adj[now][i].second + nowDist;
            int nextCheck = is_check;
            if((now == G && next == H) || (now == H && next == G)){
                nextCheck = true;
            }
            if(nextDist < dist[next] && (candidate[next] == 0 || candidate[next] == 1)){
                dist[next] = nextDist;
                pq.push({{next, nextDist}, nextCheck});
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    for(auto &w: answer){
        cout << w << " ";
    }
    cout << "\n";
}

int main(){
    fastio
    int test;
    cin >> test;
    
    while(test--){
        input();
        solve();
    }
    
    return 0;
}
