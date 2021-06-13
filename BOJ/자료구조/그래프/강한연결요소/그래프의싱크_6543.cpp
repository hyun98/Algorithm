#include <bits/stdc++.h>

#define pii pair<int, int>
using namespace std;

int V, E, dtime = 1;
vector<int> Graph[5001];
vector<int> rev_Graph[5001];
vector<int> SCC[5001];
vector<int> rev_search_seq;
int SCC_id[5001];

bool visited[10001], rev_visited[10001];

void dfs(int now){
    
    visited[now] = true;
    
    for(int i = 0; i < Graph[now].size(); i++){
        int next = Graph[now][i];
        if(visited[next]) continue;
        
        dfs(next);
    }
    
    rev_search_seq.push_back(now);
}

void rev_dfs(int now, int id){
    
    rev_visited[now] = true;
    SCC[id].push_back(now);
    SCC_id[now] = id;
    
    for(int i = 0; i < rev_Graph[now].size(); i++){
        int next = rev_Graph[now][i];
        if(rev_visited[next]){
            if(SCC_id[next] != id){
                SCC[SCC_id[next]].clear();
            }
            continue;
        }
        
        rev_dfs(next, id);
    }
    
}

void solve(){
    for(int i = 1; i <= V; i++){
        if(visited[i]) continue;
        dfs(i);
    }
    
    int scc_id = 0;
    
    for(int i = rev_search_seq.size()-1; i >= 0; i--){
        int now = rev_search_seq[i];
        if(rev_visited[now]) continue;
        rev_dfs(now, scc_id);
        scc_id++;
    }
    
    vector<int> res;
    
    for(int i = 0; i < V; i++){
        for(auto &w : SCC[i]){
            res.push_back(w);
        }
    }
    
    sort(res.begin(), res.end());
    
    for(auto &w : res){
        cout << w << " ";
    }
    cout << "\n";
}

void init(){
    for(int i = 0; i < 5001; i++){
        Graph[i].clear();
        rev_Graph[i].clear();
        SCC[i].clear();
    }
    rev_search_seq.clear();
    memset(SCC_id, 0, sizeof(SCC_id));
    memset(visited, 0, sizeof(visited));
    memset(rev_visited, 0, sizeof(rev_visited));
}

void input(){
    int a, b;
    while(true){
        cin >> V;
        if(!V) break;
        cin >> E;
        for(int i = 0; i < E; i++){
            cin >> a >> b;
            Graph[a].push_back(b);
            rev_Graph[b].push_back(a);
        }
        
        solve();
        
        init();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    return 0;
}
