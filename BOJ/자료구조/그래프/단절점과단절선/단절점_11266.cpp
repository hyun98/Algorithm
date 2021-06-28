#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int V, E;
vector<int> adj[10001];
int cnt = 0;
int discovered[10001];
bool isCutVertex[10001];

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

int findCutVertex(int now, bool isroot){
    
    // 현재 정점의 방문순서 기록
    discovered[now] = cnt++;
    int ret = discovered[now];
    
    int child = 0;
    for(int i = 0; i < adj[now].size(); i++){
        int next = adj[now][i];
        // 다음 정점을 방문한적 없다면
        if(discovered[next] == -1){
            child++;
            int subtree = findCutVertex(next, false);
            
            if(!isroot && subtree >= discovered[now]){
                // 현재 정점이 root가 아니고
                // subtree에서 탐색할 수 있는 최상위 정점이 현재 정점 이후에 발견된 정점이라면 
                // 현재 정점은 cut vertex가 된다.
                isCutVertex[now] = true;
            }
            ret = min(ret, subtree);
        }
        // 다음 정점을 방문한 경우
        else{
            ret = min(ret, discovered[next]);
        }
    }
    
    if(isroot && child >= 2) isCutVertex[now] = true;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    for(int i = 1; i <= V; i++){
        if(discovered[i] != -1) continue;
        findCutVertex(i, true);
    }
    
    vector<int> res;
    for(int i = 1; i <= V; i++){
        if(isCutVertex[i]) res.push_back(i);
    }
    cout << res.size() << "\n";
    for(auto &w : res){
        cout << w << " ";
    }
    return 0;
}
