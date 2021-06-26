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
    
    // �߰� ���� ���
    discovered[now] = cnt++;
    int ret = discovered[now];
    
    int child = 0;
    for(int i = 0; i < adj[now].size(); i++){
        int next = adj[now][i];
        // �湮 ���ߴٸ� subtree���� �� �� �ִ� ���� ���� ������ ��ȣ�� ����
        if(discovered[next] == -1){
            child++;
            int subtree = findCutVertex(next, false);
            
            if(!isroot && subtree >= discovered[now]){
                // subtree���� now������ ���� �������� �湮 �� �� ���ٸ� �������̴�
                isCutVertex[now] = true;
            }
            ret = min(ret, subtree);
        }
        // �湮 �� ���
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
