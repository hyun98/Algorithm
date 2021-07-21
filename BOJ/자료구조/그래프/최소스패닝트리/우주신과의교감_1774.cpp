#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define pdi pair<double, int>
typedef long long ll;
#define pll pair<ll, ll>

// typedef pair<int, int> pii;

using namespace std;

struct Line{
    ll st;
    ll ed;
    double len;
};

int N, M;
pll SpaceGod[1001];
int Node[1001];
vector<Line> adj;

bool cmp(Line &a, Line &b){
    return a.len < b.len;
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
    cin >> N >> M;
    ll x, y;
    for(int i = 1; i <= N; i++){
        cin >> x >> y;
        SpaceGod[i] = {x, y};
    }
    
    memset(Node, -1, sizeof(Node));
    
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        Union_Node(x, y);
    }
}

double dist(pll &a, pll &b){
    return sqrt(pow(abs(a.first - b.first), 2) + pow(abs(a.second - b.second), 2));
}

void solve(){
    for(int i = 1; i <= N-1; i++){
        for(int j = i+1; j <= N; j++){
            if(findtopnode(i) == findtopnode(j)) continue;
            adj.push_back({i, j, dist(SpaceGod[i], SpaceGod[j])});
        }
    }
    
    sort(adj.begin(), adj.end(), cmp);
    
    int cnt = 0;
    double ans = 0;
    
    for(int i = 0; i < adj.size(); i++){
        ll u = adj[i].st;
        ll v = adj[i].ed;
        double leng = adj[i].len;
        if(Union_Node(u, v)){
            ans += leng;
            cnt++;
        }
        if(cnt == N-1-M) break;
    }
    
    printf("%.2f", ans);
}

int main(){
    input();
    solve();
    
    return 0;
}
