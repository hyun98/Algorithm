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
    int u, v;
    ll cost;
};

bool cmp(Edge &a, Edge &b){
    return a.cost < b.cost;
}

int V, E;
vector<Edge> lines;
int node[10001];

void input(){
    cin >> V >> E;
    int a, b;
    ll c;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        lines.push_back({a, b, c});
    }
    sort(lines.begin(), lines.end(), cmp);
    memset(node, -1, sizeof(node));
}

int topOftheNode(int a){
    if(node[a] < 0) return a;
    return node[a] = topOftheNode(node[a]);
}

bool unionNode(int a, int b){
    a = topOftheNode(a);
    b = topOftheNode(b);
    
    if(a == b) return false;
    
    if(node[a] > node[b]){
        node[b] += node[a];
        node[a] = b;
    }
    else{
        node[a] += node[b];
        node[b] = a;
    }
    
    return true;
}

void solve(){
    int cnt = 0;
    ll res = 0;
    for(int i = 0; i < lines.size(); i++){
        if(cnt == V-1) break;
        
        int lu = lines[i].u;
        int lv = lines[i].v;
        
        if(unionNode(lu, lv)){
            res += lines[i].cost;
            cnt++;
        }
    }
    
    cout << res << '\n';
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
