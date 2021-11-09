#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cctype>
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

int N;
int lengthSum;
vector<Edge> Line;
int node[51];

bool cmp(Edge &a, Edge &b){
    return a.cost < b.cost;
}

int convertAlphaToInt(char a){
    if(isupper(a)) return a - 'A' + 27;
    else           return a - 'a' + 1;
}

void input(){
    cin >> N;
    string str;
    int mcost = 0;
    
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < N; j++){
            if(str[j] == '0') continue;
            mcost = convertAlphaToInt(str[j]);
            lengthSum += mcost;
            Line.push_back({i, j, mcost});
        }
    }
    memset(node, -1, sizeof(node));
}

int findtopnode(int a){
    if(node[a] < 0) return a;
    return node[a] = findtopnode(node[a]);
}

bool unionNode(int a, int b){
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
    sort(Line.begin(), Line.end(), cmp);
    
    int useLength = 0;
    int useLan = 0;
    for(int i = 0; i < Line.size(); i++){
        int u = Line[i].src;
        int v = Line[i].dst;
        int c = Line[i].cost;
        
        if(unionNode(u, v)){
            useLength += c;
            useLan++;
        }
        if(useLan == N-1) break;
    }
    
    if(useLan != N-1) cout << -1;
    else{
        cout << lengthSum - useLength;
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
