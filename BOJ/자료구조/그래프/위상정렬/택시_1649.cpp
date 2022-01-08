#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int N, M, A, B, K;
vector<int> adj[1001];
set<int> mustVisit;
int Cnodecnt[1001];
int route[1001];
int indegree[1001];

void input(){
    cin >> N >> M;
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    cin >> A >> B >> K;
    for(int i = 0; i < K; i++){
        cin >> u;
        mustVisit.insert(u);
    }
}

bool isInmustVisit(int node){
    if(mustVisit.find(node) != mustVisit.end()) return true;
    else return false;
}

void solve(){
    queue<int> que;
    route[A] = 1;
    
    for(int i = 1; i <= N; i++){
        if(!indegree[i]) que.push(i);
    }
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        
        // Cn 노드 방문
        if(isInmustVisit(now)) Cnodecnt[now]++;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i];
            if(Cnodecnt[next] == Cnodecnt[now]){
                route[next] += route[now];
                cout << "same\n";
                cout << "now : " << now << "\n";
                cout << "next : " << next << "\n";
                cout << "route[next] : " << route[next] << "\n";
            }
            else if(Cnodecnt[next] < Cnodecnt[now]){
                Cnodecnt[next] = Cnodecnt[now];
                route[next] = route[now];
                cout << "next < now\n";
                cout << "now : " << now << "\n";
                cout << "next : " << next << "\n";
                cout << "route[next] : " << route[next] << "\n";
            }
            if(--indegree[next]== 0) que.push(next);
        }
    }
}
// 8 12
// 1 2
// 1 3
// 1 4
// 1 5
// 2 6
// 3 6
// 4 7
// 5 7
// 6 8
// 7 9
// 8 10
// 9 10
// 1 10 4
// 6 7 8 9
int main(){
    fastio
    input();
    solve();
    cout << "Cnode[B]" << Cnodecnt[B] << "\n";
    if(Cnodecnt[B] == mustVisit.size()) cout << route[B];
    else cout << 0;
    
    return 0;
}
