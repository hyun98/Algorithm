#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N;
vector<int> graph[100001];
deque<int> path;
bool visited[100001];

void input(){
    cin >> N;
    int u, v;
    for(int i = 0; i < N-1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i < N; i++){
        cin >> u;
        path.push_back(u);
    }
}

int bfs(){
    queue<int> que;
    set<int> tmp_set;
    
    que.push(1);
    tmp_set.insert(1);
    visited[1] = true;
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        
        for(int i = 0; i < tmp_set.size(); i++){
            int now_path = path.front();
            path.pop_front();
            
            if(tmp_set.count(now_path)) que.push(now_path);
            else return 0;
        }
        
        tmp_set.clear();
        
        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i];
            if(visited[next]) continue;
            tmp_set.insert(next);
            visited[next] = true;
        }
    }
    
    return 1;
}

int main(){
    fastio
    input();
    cout << bfs();
    
    return 0;
}
