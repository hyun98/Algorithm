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

int N, M;
vector<pii > tree[100001];
int depth[100001];
int parent[100001][18];
int max_len[100001][18];
int min_len[100001][18];

vector<pii > Query;
bool visited[100001];

void input(){
    cin >> N;
    int a, b, d;
    for(int i = 0; i < N-1; i++){
        cin >> a >> b >> d;
        tree[a].push_back({b, d});
        tree[b].push_back({a, d});
    }
    
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        Query.push_back({a, b});
    }
    
}

void tree_dfs(int now, int d){
    visited[now] = true;
    depth[now] = d;
    
    for(int i = 0; i < tree[now].size(); i++){
        int next = tree[now][i].first;
        if(visited[next]) continue;
        parent[next][0] = now;
        max_len[next][0] = min_len[next][0] = tree[now][i].second;
        tree_dfs(next, d+1);
    }
}

void show(){
    for(int i = 0; i <= 5; i++){
        for(int j = 1; j <= N; j++){
            cout << j << "'s 2^" << i << " parent : " << parent[j][i] << "\n";
            cout << "mx " << j << " : " << max_len[j][i] << "\n";
            cout << "mn " << j << " : " << min_len[j][i] << "\n";
        }
    }
}

void mkparent(){
    parent[1][0] = 0;
    max_len[1][0] = 0;
    min_len[1][0] = INF;
    
    for(int i = 1; i <= 17; i++){
        for(int j = 1; j <= N; j++){
            max_len[j][i] = max(max_len[j][i-1], max_len[parent[j][i-1]][i-1]);
            min_len[j][i] = min(min_len[j][i-1], min_len[parent[j][i-1]][i-1]);
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}

void QueryAnswer(int a, int b){
    int minans = INF;
    int maxans = 0;
    
    if(depth[a] > depth[b]) swap(a, b);
    
    for(int i = 17; i >= 0; i--){
        if(depth[b] - depth[a] >= (1 << i)){
            minans = min(minans, min_len[b][i]);
            maxans = max(maxans, max_len[b][i]);
            b = parent[b][i];
        }
    }
    if(a == b){
        cout << minans << " " <<  maxans << "\n";
        return;
    }
    
    for(int i = 17; i >= 0; i--){
        if(parent[a][i] != parent[b][i]){
            minans = min(minans, min(min_len[a][i], min_len[b][i]));
            maxans = max(maxans, max(max_len[a][i], max_len[b][i]));
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    minans = min(minans, min(min_len[a][0], min_len[b][0]));
    maxans = max(maxans, max(max_len[a][0], max_len[b][0]));
    cout << minans << " " << maxans << "\n";
}

void solve(){
    tree_dfs(1, 0);
    mkparent();
    // show();
    
    for(auto &w : Query){
        QueryAnswer(w.first, w.second);
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
