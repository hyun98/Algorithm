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

int N, M;
int Node[1001];
vector<int> graph[1001];

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
    memset(Node, -1, sizeof(Node));
    cin >> N >> M;
    char C;
    int p, q;
    for(int i = 0; i < M; i++){
        cin >> C >> p >> q;
        if(C == 'F'){
            Union_Node(p, q);
        }
        else{
            graph[p].push_back(q);
            graph[q].push_back(p);
        }
    }
}

void dfs(int now, int prev, int depth){
    
    for(int i = 0; i < graph[now].size(); i++){
        int next = graph[now][i];
        
        if(now == prev) continue;
        if(depth == 1){
            Union_Node(prev, next);
        }
        else dfs(next, now, depth+1);
    }
}

void solve(){
    for(int i = 1; i <= N; i++){
        dfs(i, 0, 0);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(Node[i] < 0){
            ans++;
        }
    }
    cout << ans;
}

int main(){
    input();
    solve();
    
    return 0;
}
