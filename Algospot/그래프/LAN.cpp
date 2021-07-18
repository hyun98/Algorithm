#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

struct Line{
    double cost;
    int st, ed;
};

int N, M;
vector<Line> Edge;
int Node[501];

bool compare(Line &a, Line &b){
    return a.cost < b.cost;
}

int find_topnode(int a){
    if(Node[a] < 0) return a;
    return Node[a] = find_topnode(Node[a]);
}

bool Union_node(int a, int b){
    a = find_topnode(a);
    b = find_topnode(b);
    
    if(a == b) return false;
    
    if(Node[a] > Node[b]){
        Node[b] += Node[a];
        Node[a] = b;
    }
    else{
        Node[a] += Node[b];
        Node[b] = a;
    }
    
    return true;
}

double leng(double x1, double x2, double y1, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void input(){
    Edge.clear();
    memset(Node, -1, sizeof(Node));
    
    cin >> N >> M;
    double xarr[501], yarr[501];
    for(int i = 0; i < N; i++){
        cin >> xarr[i];
    }
    for(int i = 0; i < N; i++){
        cin >> yarr[i];
    }
    
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            Edge.push_back({leng(xarr[i], xarr[j], yarr[i], yarr[j]), i, j});
        }
    }
    sort(Edge.begin(), Edge.end(), compare);
    
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        Union_node(a, b);
    }
}

void solve(){
    double ans = 0;
    for(int i = 0; i < Edge.size(); i++){
        double cost = Edge[i].cost;
        int u = Edge[i].st;
        int v = Edge[i].ed;
        
        if(Union_node(u, v)){
            ans += cost;
        }
    }
    
    printf("%.10f\n", ans);
}

int main(){
    int test;
    cin >> test;
    while(test--){
        input();
        solve();
    }
    
    return 0;
}
