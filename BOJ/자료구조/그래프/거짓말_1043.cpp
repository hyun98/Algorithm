#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N, M;
vector<int> party[101];
vector<int> truemanlist;
bool trueman[101];
bool visited[101];

void input(){
    cin >> N >> M;
    int a, b;
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> b;
        truemanlist.push_back(b+50);
        trueman[b+50] = 1;
    }
    
    for(int i = 0; i < M; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            party[i].push_back(b + 50);
            party[b+50].push_back(i);
        }
    }
}

void dfs(int now){
    trueman[now] = true;
    visited[now] = true;
    
    for(int i = 0; i < party[now].size(); i++){
        int next = party[now][i];
        if(visited[next]) continue;
        dfs(next);
    }
}

void solve(){
    for(int i = 0; i < truemanlist.size(); i++){
        int now = truemanlist[i];
        dfs(now);
    }
    
    int ans = 0;
    for(int i = 0; i < M; i++){
        if(!trueman[i]) ans++;
    }
    
    cout << ans << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
