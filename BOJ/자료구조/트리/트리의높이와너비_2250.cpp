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


int N;
int tree[10001][2];
int childNodes[10001][2];
int leftNodes[10001]; // index
int rightNodes[10001];
bool visited[10001];

vector<int> levelNodes[10001];
pii answer = {1, 1};

void input(){
    cin >> N;
    int n, l, r;
    for(int i = 0; i < N; i++){
        cin >> n >> l >> r;
        tree[n][0] = (l != -1? l : -1);
        tree[n][1] = (r != -1? r : -1);
    }
}

int dfs(int now){
    if(now == -1) return 0;
    if(visited[now]) return childNodes[now][0] + childNodes[now][1] + 1;
    
    visited[now] = true;
    
    childNodes[now][0] += dfs(tree[now][0]);
    childNodes[now][1] += dfs(tree[now][1]);
    
    return childNodes[now][0] + childNodes[now][1] + 1;
    
}

void findSide(int now, int prev, bool flag, int depth){
    if(now == -1) return;
        
    // 현재 노드가 부모의 오른쪽
    if(flag){
        leftNodes[now] = leftNodes[prev] + childNodes[now][0] + 1;
        rightNodes[now] = N - leftNodes[now] - 1;
    }
    // 현재 노드가 부모의 왼쪽
    else{
        rightNodes[now] = rightNodes[prev] + childNodes[now][1] + 1;
        leftNodes[now] = N - rightNodes[now] - 1;
    }
    
    levelNodes[depth].push_back(leftNodes[now]+1);
    
    findSide(tree[now][0], now, false, depth+1);
    findSide(tree[now][1], now, true, depth+1);
}


void solve(){
    int root;
    
    for(int i = 1; i <= N; i++){
        if(visited[i]) continue;
        dfs(i);
    }
    for(int i = 1; i <= N; i++){
        if(childNodes[i][0] + childNodes[i][1] == N-1){
            root = i;
            break;
        }
    }
    
    leftNodes[root] = childNodes[root][0];
    rightNodes[root] = childNodes[root][1];
    levelNodes[1].push_back(leftNodes[root]+1);
    findSide(tree[root][0], root, false, 2);
    findSide(tree[root][1], root, true, 2);
    
    for(int d = 1; d <= N; d++){
        if(levelNodes[d].empty()) continue;
        if(levelNodes[d].size() == 1) continue;
        
        sort(levelNodes[d].begin(), levelNodes[d].end());
        int width = levelNodes[d].back() - levelNodes[d][0] + 1;
        if(answer.second < width) answer = {d, width};
    }
    
    cout << answer.first << " " << answer.second;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
