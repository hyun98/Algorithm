#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define pii pair<int, int>

using namespace std;

int V, E;
vector<int> adj[100001];
int cnt = 0;
int discovered[100001];
vector< pii > CutEdges;

void input(){
    cin >> V >> E;
    int u, v;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(discovered, -1, sizeof(discovered));
}

int findCutEdge(int now, int parent){
    
    // 발견 순서를 기록
    discovered[now] = cnt++;
    // 현재 정점에서 갈 수 있는 최대 조상의 번호
    int ret = discovered[now];
    
    for(int i = 0; i < adj[now].size(); i++){
        int next = adj[now][i];
        if(next == parent) continue;
        // next가 현재 정점의 부모가 아니고 아직 방문한적 없다면
        if(discovered[next] == -1){
            int subtree = findCutEdge(next, now);
            
            if(subtree > discovered[now]){
                // 현재 정점이 subtree에서 탐색할 수 있는 모든 정점의 조상 노드라면 단절선과 연결되어 있다는 뜻이다.
                CutEdges.push_back({min(now, next), max(now, next)});
            }
            ret = min(ret, subtree);
        }
        // next가 현재 정점의 부모인 경우
        else{
            ret = min(ret, discovered[next]);
        }
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    for(int i = 1; i <= V; i++){
        if(discovered[i] != -1) continue;
        findCutEdge(i, 0);
    }
    
    cout << CutEdges.size() << "\n";
    sort(CutEdges.begin(), CutEdges.end());
    for(auto &w : CutEdges){
        cout << w.first << " " << w.second << "\n";
    }
    return 0;
}
