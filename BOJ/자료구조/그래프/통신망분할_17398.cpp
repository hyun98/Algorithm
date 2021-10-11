#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int, int>
typedef long long ll;

using namespace std;

int N, M, Q;
ll ans;

deque<int> Q_list;
vector<pii > link_list;
bool isuse[100001];
int node[100001];

void input(){
    cin >> N >> M >> Q;
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        link_list.push_back({u, v});
    }
    for(int i = 0; i < Q; i++){
        cin >> u;
        Q_list.push_front(u);
        isuse[u] = true;
    }
    memset(node, -1, sizeof(node));
}

int findtopnode(int a){
    if(node[a] < 0) return a;
    return node[a] = findtopnode(node[a]);
}

ll Union_node(int a, int b){
    a = findtopnode(a);
    b = findtopnode(b);
    
    if(a == b) return 0;
    
    ll ret = node[a] * node[b];
    
    if(node[a] < node[b]){
        node[a] += node[b];
        node[b] = a;
    }
    else{
        node[b] += node[a];
        node[a] = b;
    }
    
    return ret;
}

void solve(){
    // 통신망이 연결됨을 확인하는 방법 : 분리 집합?
    
    // 연결을 끊었을 때 두 개로 나눠짐을 어떻게 파악하지?
    // 끊어질 때마다 처음부터 유니온 파인드 실행?? 절대 안됨
    // 세그먼트 트리??
    // 연결을 끊는다는걸 하나의 쿼리로 생각?
    
    // 1. 분리 집합의 최적화..
    // 쿼리는 최대 10만개
    // 연결도 최대 10만개
    // 아 미리 제거해놓고 제거 역순으로 다시 연결시키면서
    // 연결될 때 서로 몇개의 원소를 가지고 연결되는지 확인
    
    for(int i = 0; i < link_list.size(); i++){
        if(isuse[i+1]) continue;
        int u = link_list[i].first;
        int v = link_list[i].second;
        Union_node(u, v);
    }
    
    for(auto &q: Q_list){
        int u = link_list[q-1].first;
        int v = link_list[q-1].second;
        ans += Union_node(u, v);
    }
    
    
    cout << ans;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
