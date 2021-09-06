#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, graph[21][21], ans = 1e9;

void solve(int x, int y, int d1, int d2) {
    vector<int> v;
    int visit[6];
    bool flag[21][21] = {false};
    for(int i=0; i<=d1; i++) flag[x+i][y-i] = true;
    for(int i=0; i<=d2; i++) flag[x+i][y+i] = true;
    for(int i=0; i<=d2; i++) flag[x+d1+i][y-d1+i] = true;
    for(int i=0; i<=d1; i++) flag[x+d2+i][y+d2-i] = true;
    memset(visit, 0, sizeof(visit));
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
        if(flag[i][j]) continue;
        if(1<=i && i<x+d1 && 1<=j && j<=y) visit[1] += graph[i][j];
        else if(1<=i && i<=x+d2 && y<j && j<=n) visit[2] += graph[i][j];
        else if(x+d1<=i && i<=n && 1<=j && j<y-d1+d2) visit[3] += graph[i][j];
        else if(x+d2<i && i<=n && y-d1+d2<=j && j<=n) visit[4] += graph[i][j];
        else visit[5] += graph[i][j];
    }
    for(int i=1; i<=5; i++) v.push_back(visit[i]);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << flag[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << visit[1] << " " << visit[2] << " " << visit[3] << " " << visit[4] << " " << visit[5] << '\n';
    sort(v.begin(), v.end());
    ans = min(ans, abs(v[0]-v[4])); 
    cout << ans << '\n';
}

void dfs(int x, int y, int d1, int d2) {
    if(x+d1+d2>n || y+d2>n || y-d1<1) return;
    solve(x, y, d1, d2);
    dfs(x, y, d1+1, d2);
    dfs(x, y, d1, d2+1);
    dfs(x, y, d1+1, d2+1);
}

void init() {
    memset(graph, 0, sizeof(graph));
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> graph[i][j];
        }
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
        dfs(i, j, 1, 1);
    }
}

int main() {
    init();
    cout << ans << '\n';
}