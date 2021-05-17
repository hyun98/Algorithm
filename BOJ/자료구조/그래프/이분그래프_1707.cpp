#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct P{
    int color = -1;
    vector<int> link;
};

int K, V, E;
bool is_Bipart = true;
bool visited[20001];
vector<P> Bipart;

void input(){
    int a, b;
    cin >> V >> E;
    Bipart.resize(V+1);
    for(int i = 0; i < E; i++){
        cin >> a >> b;
        Bipart[a].link.push_back(b);
        Bipart[b].link.push_back(a);
    }
}

void reset(){
    Bipart.clear();
    for(int i = 0; i < 20001; i++){
        visited[i] = false;
    }
    is_Bipart = true;
}

void BFS(int v){
    queue<P> que;
    P init = Bipart[v];
    init.color = 0;
    que.push(init);
    visited[v] = true;
    
    while(!que.empty()){
        P now = que.front();
        que.pop();
        
        for(int i = 0; i < now.link.size(); i++){
            int next = now.link[i];
            if(Bipart[next].color == now.color){
                is_Bipart = false;
                break;
            }
            if(visited[next]) continue;
            else{
                visited[next] = true;
                Bipart[next].color = !now.color;
                que.push(Bipart[next]);
            }
        }
        
        if(!is_Bipart) break;
    }
    
}

void solve(){
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            BFS(i);
        }
    }
    
    if(is_Bipart) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    cin >> K;
    while(K--){
        input();
        solve();
        reset();
    }
    
    return 0;
}
