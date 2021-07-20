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

struct Planet{
    int x, y, z, idx;
};

struct Line{
    int cost, st, ed;
};

int N;
Planet planets[100001];
vector<Line> Edge;
int Node[100001];

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

bool cmp(Line &a, Line &b){
    return a.cost < b.cost;
}
bool cmpX(Planet &a, Planet &b){
    return a.x < b.x;
}
bool cmpY(Planet &a, Planet &b){
    return a.y < b.y;
}
bool cmpZ(Planet &a, Planet &b){
    return a.z < b.z;
}

void input(){
    cin >> N;
    int a, b, c;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        planets[i].x = a;
        planets[i].y = b;
        planets[i].z = c;
        planets[i].idx = i;
    }
    memset(Node, -1, sizeof(Node));
}

void solve(){
    sort(planets, planets + N, cmpX);
    for(int i = 1; i < N; i++){
        Edge.push_back({abs(planets[i-1].x - planets[i].x), planets[i-1].idx, planets[i].idx});
    }
    sort(planets, planets + N, cmpY);
    for(int i = 1; i < N; i++){
        Edge.push_back({abs(planets[i-1].y - planets[i].y), planets[i-1].idx, planets[i].idx});
    }
    sort(planets, planets + N, cmpZ);
    for(int i = 1; i < N; i++){
        Edge.push_back({abs(planets[i-1].z - planets[i].z), planets[i-1].idx, planets[i].idx});
    }
    sort(Edge.begin(), Edge.end(), cmp);
    for(auto &w : Edge){
    }
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < Edge.size(); i++){
        int u = Edge[i].st;
        int v = Edge[i].ed;
        int cost = Edge[i].cost;
        if(Union_Node(u, v)){
            cnt++;
            ans += cost;
        }
        if(cnt == N-1) break;
    }
    
    cout << ans;
}

int main(){
    input();
    solve();
    
    return 0;
}
