#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Line{
    int st, ed;
    int cost;
};

int N, P, StartCost = 1001, result = 0;
int Node[10001];
int VisitCost[10001];
vector<Line> Edge;
vector<int> tree_repo;

bool compare(Line &a, Line &b){
    return a.cost < b.cost;
}

int find_topnode(int a){
    if(Node[a] < 0) return a;
    return Node[a] = find_topnode(Node[a]);
}

bool is_cycle(int a, int b){
    a = find_topnode(a);
    b = find_topnode(b);
    if(a == b) return true;
    else return false;
}

void Union_node(int a, int b){
    a = find_topnode(a);
    b = find_topnode(b);
    if(Node[a] > Node[b]){
        Node[b] += Node[a];
        Node[a] = b;
    }
    else{
        Node[a] += Node[b];
        Node[b] = a;
    }
}

void solve(){
    int va, vb, cnt = 0;
    for(int i = 0; i < Edge.size(); i++){
        if(cnt == N-1) break;
        va = Edge[i].st;
        vb = Edge[i].ed;
        if(!is_cycle(va, vb)){
            Union_node(va, vb);
            result += Edge[i].cost;
            cnt++;
        }
    }
    cout << result + StartCost;
}

void input(){
    cin >> N >> P;
    for(int i = 1; i <= N; i++){
        cin >> VisitCost[i];
        StartCost = min(StartCost, VisitCost[i]);
    }
    
    int a, b, c;
    for(int i = 0; i < P; i++){
        cin >> a >> b >> c;
        Edge.push_back({a, b, c*2 + VisitCost[a] + VisitCost[b]});
    }
    sort(Edge.begin(), Edge.end(), compare);
    memset(Node, -1, sizeof(Node));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    
    return 0;
}
