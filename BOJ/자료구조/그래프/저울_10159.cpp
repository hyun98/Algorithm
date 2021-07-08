#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;

int indegree[101], comp[101];
vector<int> Items[101];
bool visited[101];

void input(){
    int a, b;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        Items[a].push_back(b);
        indegree[b]++;
    }
}

int dfs(int now, int d){
    if(!Items[now].size()){
        comp[now] += d;
        return d;
    }
    
//    visited[now] = true;
    
    for(int i = 0; i < Items[now].size(); i++){
        int next = Items[now][i];
//        if(visited[next]) continue;
        comp[now] += dfs(next, d+1);
    }
    
    comp[now] -= (Items[now].size()-1);
    
    return comp[now];
}

void solve(){
    for(int i = 1; i <= N; i++){
        if(indegree[i]) continue;
//        memset(visited, 0, sizeof(visited));
        dfs(i, 0);
    }
    
    for(int i = 1; i <= N; i++){
        cout << abs(N - (comp[i] + 1)) << "\n";
    }
    
}

int main(){
    input();
    solve();
    
    return 0;
}
