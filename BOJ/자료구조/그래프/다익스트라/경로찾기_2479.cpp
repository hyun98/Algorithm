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

int N, K, A, B;
int arr[1001][1001];
int dist[1001];
int parent[1001];
vector<pii > graph[1001];

void input(){
    cin >> N >> K;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < K; j++){
            arr[i][j] = str[j];
        }
    }
    
    cin >> A >> B;
}

int HammingDist(int u, int v){
    int d = 0;
    for(int i = 0; i < K; i++){
        if(arr[u-1][i] != arr[v-1][i]) d++;
    }
    return d;
}

void make_graph(){
    for(int i = 1; i <= N-1; i++){
        for(int j = i+1; j <= N; j++){
            int dist = HammingDist(i, j);
            if(dist == 1){
                graph[i].push_back({dist, j});
                graph[j].push_back({dist, i});
            }
        }
    }
}

bool Dijkstra(){
    for(int i = 0; i < 1001; i++){
        dist[i] = INF;
    }
    
    priority_queue<pii, vector<pii >, greater<pii > > pq;
    pq.push({0, A});
    dist[A] = 0;
    
    while(!pq.empty()){
        int now = pq.top().second;
        int now_dist = pq.top().first;
        pq.pop();
        
        if(now == B) return true;
        
        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].second;
            int next_dist = graph[now][i].first + now_dist;
            
            if(next_dist < dist[next]){
                parent[next] = now;
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }
    
    return false;
}

void solve(){
    make_graph();
    bool isfound = Dijkstra();
    
    if(!isfound){
        cout << -1;
        return;
    }
    
    vector<int> path;
    path.push_back(B);
    for(int p = parent[B]; p != A; p = parent[p]){
        path.push_back(p);
    }
    path.push_back(A);
    
    for(int i = path.size()-1; i >= 0; i--){
        cout << path[i] << " ";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
