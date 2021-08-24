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

struct Edge{
    int u, v, d;
};

int N, M;
int mapcnt;
int Map[11][11];
int Mapnum[11][11];
int dist[7][7];
int node[7];
vector<pii > Island[7];
vector<Edge> adj;

int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            dist[i][j] = INF;
        }
    }
    memset(node, -1, sizeof(node));
}

void find_map_num(int r, int c){
    mapcnt++;
    queue<pii > que;
    que.push({r, c});
    Mapnum[r][c] = mapcnt;
    
    
    while(!que.empty()){
        pii now = que.front();
        Island[mapcnt].push_back({now.first, now.second});
        que.pop();
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || Mapnum[nr][nc] || !Map[nr][nc]) continue;
            Mapnum[nr][nc] = mapcnt;
            que.push({nr, nc});
        }
    }
}

void link_island(int mnum){
    for(int i = 0; i < Island[mnum].size(); i++){
        pii now = Island[mnum][i];
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            int len = 0;
            int dest = mnum;
            while(Mapnum[nr][nc] != mnum && nr >= 0 && nr < N && nc >= 0 && nc < M){
                if(Mapnum[nr][nc]){
                    dest = Mapnum[nr][nc];
                    break;
                }
                nr += dr[k];
                nc += dc[k];
                len++;
            }
            if(mnum != dest && len >= 2){
                dist[mnum][dest] = min(dist[mnum][dest], len);
            }
        }
    }
}

int findtopnode(int a){
    if(node[a] < 0) return a;
    return node[a] = findtopnode(node[a]);
}

bool union_node(int a, int b){
    a = findtopnode(a);
    b = findtopnode(b);
    
    if(a == b) return false;
    if(node[a] < node[b]){
        node[a] += node[b];
        node[b] = a;
    }
    else{
        node[b] += node[a];
        node[a] = b;
    }
    
    return true;
}

bool cmp(Edge &a, Edge &b){
    return a.d < b.d;
}

void solve(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(Map[r][c] && !Mapnum[r][c]) find_map_num(r, c);
        }
    }
    
    for(int i = 1; i <= mapcnt; i++){
        link_island(i);
    }
    
    for(int i = 1; i <= mapcnt - 1; i++){
        for(int j = i+1; j <= mapcnt; j++){
            if(dist[i][j] != INF){
                adj.push_back({i, j, dist[i][j]});
            }
        }
    }
    
    sort(adj.begin(), adj.end(), cmp);
    
    int res = 0, cnt = 0;;
    for(int i = 0; i < adj.size(); i++){
        int u = adj[i].u;
        int v = adj[i].v;
        int d = adj[i].d;
        if(union_node(u, v)){
            res += d;
            cnt++;
        }
        if(cnt == mapcnt - 1) break;
    }
    
    if(cnt == mapcnt - 1) cout << res << "\n";
    else cout << -1;
    
}

int main(){
    input();
    solve();
    
    return 0;
}
