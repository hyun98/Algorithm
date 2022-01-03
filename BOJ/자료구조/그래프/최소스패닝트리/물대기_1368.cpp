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
    int src;
    int dst;
    int cost;
};

bool cmp(Edge &a, Edge &b){
    return a.cost < b.cost;
}

int N, ans = 0;
int non_cost[301];
vector<Edge> paddy;
int node[301];

void input(){
    int c;
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> non_cost[i];
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> c;
            Edge newEdge;
            if(i == j){
                newEdge.src = 0;
                newEdge.dst = i;
                newEdge.cost = non_cost[i];
            }
            else{
                newEdge.src = i;
                newEdge.dst = j;
                newEdge.cost = c;
            }
            paddy.push_back(newEdge);
        }
    }
    
    memset(node, -1, sizeof(node));
}

int findtopnode(int a){
    if(node[a] < 0) return a;
    return node[a] = findtopnode(node[a]);
}

bool Union_Node(int a, int b){
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

void solve(){
    sort(paddy.begin(), paddy.end(), cmp);
    
    int nodeCnt = 0;
    
    for(int i = 0; i < paddy.size(); i++){
        int u = paddy[i].src;
        int v = paddy[i].dst;
        int c = paddy[i].cost;
        if(Union_Node(u, v)) ans += c;
    }
    
    cout << ans;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
