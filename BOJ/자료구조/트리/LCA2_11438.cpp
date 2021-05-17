#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > input_node;
int N, M, *depth, parent[100001][18];
bool *visit;

int Search_LCA(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);

    //높이를 동일하게 맞추는 작업
    for(int i = 17; i >= 0; i--){
        if(depth[b] - depth[a] >= (1 << i)){
            b = parent[b][i];
        }
    }
    if(a == b) return a;

    for(int i = 17; i >= 0; i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

void solve(){
    int a, b;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        cout << Search_LCA(a, b) << "\n";
    }
}

void make_tree(int now, int d){
    if(visit[now]) return;
    visit[now] = true;
    depth[now] = d;
    for(int i = 0; i < input_node[now].size(); i++){
        int next = input_node[now][i];
        if(visit[next]) continue;
        parent[next][0] = now;
        make_tree(next, d+1);
    }
}

void make_parent(){
    parent[1][0] = 0;
    for(int i = 1; i <= 17; i++){
        for(int j = 1; j <= N; j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
//            cout << "parent[" << j << "][" << i << "] : " << parent[j][i] << "\n";
        }
    }
}

void input(){
    int top, child, a, b;
    cin >> N;
    visit = new bool[N+1] {false};
    input_node.resize(N+1, vector<int>());
    depth = new int[N+1];
    for(int i = 0; i < N-1; i++){
        cin >> top >> child;
        input_node[top].push_back(child);
        input_node[child].push_back(top);
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    make_tree(1, 0);
    make_parent();
    solve();
    return 0;
}
