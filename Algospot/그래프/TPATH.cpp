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

#define MAX_V 2000

int N, M;

// speed, {u, v}
vector<pair<int, pii > > Edges;
vector<int> speed;
int Node[MAX_V+1];

void input(){
    cin >> N >> M;
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        Edges.push_back({c, {a, b}});
        speed.push_back(c);
    }
    
    sort(Edges.begin(), Edges.end());
}

int findTopnode(int a){
    if(Node[a] < 0) return a;
    return Node[a] = findTopnode(Node[a]);
}

bool Union_Node(int a, int b){
    a = findTopnode(a);
    b = findTopnode(b);
    
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

int findUpperspeed(int low){
    memset(Node, -1, sizeof(Node));
    
    for(int i = 0; i < Edges.size(); i++){
        if(Edges[i].first < speed[low]) continue;
        
        Union_Node(Edges[i].second.first, Edges[i].second.second);
        
        if(findTopnode(0) == findTopnode(N-1)){
            return Edges[i].first;
        }
    }
    
    return INF;
}

void solve(){
    sort(speed.begin(), speed.end());
    
    int result = INF;
    for(int i = 0; i < speed.size(); i++){
        result = min(result, findUpperspeed(i) - speed[i]);
    }
    
    cout << result << "\n";
}

void reset(){
    speed.clear();
    Edges = vector<pair<int, pii > >();
}

int main(){
    fasti
    int test;
    cin >> test;
    while(test--){
        reset();
        input();
        solve();
    }
    
    return 0;
}
