#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, M, S, E;
vector<int> link[300001];
int dx[2] = {1, -1};

void input(){
    cin >> N >> M;
    cin >> S >> E;
    int x, y;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        link[x].push_back(y);
        link[y].push_back(x);
    }
}

void solve(){
    queue<pii > que;
    que.push({S, 0});
    
    bool visited[300001];
    memset(visited, 0, sizeof(visited));
    
    visited[S] = true;
    
    while(!que.empty()){
        int now = que.front().first;
        int ntime = que.front().second;
        que.pop();
        
        if(now == E){
            cout << ntime;
            return;
        }
        
        for(int i = 0; i < 2; i++){
            int nx = now + dx[i];
            if(nx < 1 || nx > N || visited[nx]) continue;
            visited[nx] = true;
            que.push({nx, ntime+1});
        }
        
        for(int i = 0; i < link[now].size(); i++){
            int nx = link[now][i];
            if(visited[nx]) continue;
            visited[nx] = true;
            que.push({nx, ntime+1});
        }
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
