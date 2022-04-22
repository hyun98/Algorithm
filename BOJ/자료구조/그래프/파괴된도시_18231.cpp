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

int N, M, K;
vector<int> adj[2001];
bool Destroy[2001];
bool visited[2001];

void input(){
    cin >> N >> M;
    int u, v;
    
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> u;
        Destroy[u] = true;
    }
}

void solve(){
    
    vector<int> answer;
    
    for(int i = 1; i <= N; i++){
        if(!Destroy[i]) continue;
        
        bool flag = true;
        vector<int> temp;
        for(auto next: adj[i]){
            if(!Destroy[next]){
                flag = false;
                break;
            }
            temp.push_back(next);
        }
        if(flag) answer.push_back(i);
    }
    
    for(auto w : answer){
        visited[w] = true;
        for(auto f: adj[w]){
            visited[f] = true;
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(visited[i] != Destroy[i]){
            cout << -1;
            return;
        }
    }
    
    cout << answer.size() << '\n';
    for(auto w : answer){
        cout << w << " ";
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
