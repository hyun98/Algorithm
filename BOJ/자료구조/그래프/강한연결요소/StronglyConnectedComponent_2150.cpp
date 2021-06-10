#include <bits/stdc++.h>

//#define pii pair<int, int>
using namespace std;

int V, E, dtime = 1;
vector<int> Graph[10001];
vector<int> rev_Graph[10001];
vector< vector<int> > SCC;
//pii df_time[10001];
vector<int> rev_search_seq;

bool visited[10001], rev_visited[10001];

void input(){
    int a, b;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> a >> b;
        Graph[a].push_back(b);
        rev_Graph[b].push_back(a);
    }
}

void dfs(int now){
    
    visited[now] = true;
//    df_time[now].first = dtime++;
    
    for(int i = 0; i < Graph[now].size(); i++){
        int next = Graph[now][i];
        if(visited[next]) continue;
        
        dfs(next);
        
    }
//    df_time[now].second = dtime++;
    rev_search_seq.push_back(now);
}

void rev_dfs(int now, vector<int> &temp){
    
    rev_visited[now] = true;
    temp.push_back(now);
    
    for(int i = 0; i < rev_Graph[now].size(); i++){
        int next = rev_Graph[now][i];
        if(rev_visited[next]) continue;
        
        rev_dfs(next, temp);
    }
    
}

void solve(){
    for(int i = 1; i <= V; i++){
        if(visited[i]) continue;
        dfs(i);
    }
    
//    for(auto &w : rev_search_seq){
//        cout << w << "\n";
//    }
    
    vector<int> temp;
    for(int i = rev_search_seq.size()-1; i >= 0; i--){
        int now = rev_search_seq[i];
        if(rev_visited[now]) continue;
        rev_dfs(now, temp);
        SCC.push_back(temp);
        temp.clear();
    }
    
    for(auto &w : SCC){
        sort(w.begin(), w.end());
    }
    sort(SCC.begin(), SCC.end());
    
    
    cout << SCC.size() << "\n";
    
    for(auto &w : SCC){
        for(auto &k : w){
            cout << k << " ";
        }
        cout << "-1\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    solve();
    
    return 0;
}
