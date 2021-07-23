#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

struct Line{
    int st, ed, val;
};

int N, M, St;
int Map[51][51], Node[255];
vector<pii > Vertax;
vector<Line> Edge;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
map<pii, int> hmap;

bool cmp(Line &a, Line &b){
    return a.val < b.val;
}

int findtopnode(int a){
    if(Node[a] < 0) return a;
    return Node[a] = findtopnode(Node[a]);
}

bool Union_Node(int a, int b){
    a = findtopnode(a);
    b = findtopnode(b);
    if(a == b) return false;
    
    if(Node[a] < Node[b]){
        Node[a] += Node[b];
        Node[b] = a;
    }
    else{
        Node[b] += Node[a];
        Node[a] = b;
    }
    
    return true;
}

void input(){
    int i = 1;
    char b;
    string str;
    Vertax.push_back({0, 0});
    
    cin >> N >> M;
    
    for(int r = 0; r < N; r++){
        cin >> str;
        for(int c = 0; c < N; c++){
            b = str[c];
            switch (b){
            case '1': Map[r][c] = 0; break;
            case '0': Map[r][c] = 1; break;
            case 'S': 
                Vertax.push_back({r, c});
                St = i;
                hmap[{r, c}] = i++;
                Map[r][c] = 2;
                break;
            case 'K':
                Vertax.push_back({r, c});
                hmap[{r, c}] = i++;
                Map[r][c] = 2;
                break;
            default: break;
            }
        }
    }
    Edge.push_back({0, St, 0});
    memset(Node, -1, sizeof(Node));
}

bool BFS(int r, int c, int i){
    int cnt = -1;
    bool visited[51][51];
    memset(visited, 0, sizeof(visited));
    // 구조체 변수명이 안맞지만 그냥 씀.
    // st : r,  ed : c,  val : dist
    queue<Line> que;
    que.push({r, c, 0});
    visited[r][c] = true;
    
    while(!que.empty()){
        Line now = que.front();
        que.pop();
        
        if(Map[now.st][now.ed] == 2){
            cnt++;
            int idx = hmap[{now.st, now.ed}];
            if(idx > i){
                Edge.push_back({i, idx, now.val});
            }
        }
        
        for(int k = 0; k < 4; k++){
            int nr = now.st + dr[k];
            int nc = now.ed + dc[k];
            
            if(!Map[nr][nc] || visited[nr][nc]) continue;
            que.push({nr, nc, now.val+1});
            visited[nr][nc] = true;
        }
    }
    
    if(cnt == M) return true;
    return false;
}

void solve(){
    for(int i = 1; i <= M+1; i++){
        if(!BFS(Vertax[i].first, Vertax[i].second, i)){
            cout << -1 << "\n";
            return;
        }
    }
    
    int cnt = 0, ans = 0;
    
    sort(Edge.begin(), Edge.end(), cmp);
    
    for(int i = 1; i < Edge.size(); i++){
        int u = Edge[i].st;
        int v = Edge[i].ed;
        int dist = Edge[i].val;
        
        if(Union_Node(u, v)){
            cnt++;
            ans += dist;
        }
        if(cnt == M+1) break;
    }
    
    cout << ans << "\n";
}

int main(){
    input();
    solve();
    
    return 0;
}
