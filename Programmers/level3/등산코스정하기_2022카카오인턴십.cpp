#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int, int>
#define INF 1e9

using namespace std;

struct Route {
    int intensity;
    int now;
};

vector<pii > adj[50001];
bool isGate[50001];
bool isSummit[50001];
int dist[50001];

void init(
    vector<vector<int>> &paths, 
    vector<int> &gates, 
    vector<int> &summits){
    
    for(auto path: paths){
        adj[path[0]].push_back({path[1], path[2]});
        adj[path[1]].push_back({path[0], path[2]});
    }
    
    for(auto gate: gates){
        isGate[gate] = true;
    }
    
    for(auto summit: summits){
        isSummit[summit] = true;
    }
}

struct cmp {
    bool operator()(Route &r1, Route &r2){
        return r1.intensity > r2.intensity;
    }
};

void solve(vector<int> &gates){
    priority_queue<Route, vector<Route>, cmp> pq;
    
    for(int i = 0; i < 50001; i++){
        dist[i] = INF;
    }
    
    for(auto gate: gates){
        dist[gate] = 0;
        pq.push({0, gate});
    }
    
    while(!pq.empty()){
        int nowIntensity = pq.top().intensity;
        int now = pq.top().now;
        pq.pop();
        
        if(dist[now] < nowIntensity || isSummit[now]) continue;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            int nextIntensity = max(nowIntensity, adj[now][i].second);
            
            if(dist[next] <= nextIntensity) continue;
            dist[next] = min(dist[next], nextIntensity);
            
            pq.push({nextIntensity, next});
        }
        
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    init(paths, gates, summits);
    
    solve(gates);
    
    sort(summits.begin(), summits.end());
    int minSummit, minIntensity = INF;
    for(auto summit: summits){
        if(minIntensity > dist[summit]){
            minSummit = summit;
            minIntensity = dist[summit];
        }
    }
    
    answer.push_back(minSummit);
    answer.push_back(minIntensity);
    
    return answer;
}