#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, par[1001], cnt = 0;
vector<int> conn[1001];

void print() {
    for(int i=1; i<=n; i++) {
        if(par[i] == i) cnt++;
    }
    cout << cnt << '\n';
}

int find(int start) {
    if(start == par[start]) return start;
    return par[start] = find(par[start]);
}

void uni(int x, int y) {
    if(x == y) return;
    if(x > y) par[x] = y;
    else par[y] = x;
}

void dfs(int s, int e, int cnt) {
    for(int i=0; i<conn[s].size(); i++) {
        int next = conn[s][i];
        if(next == e) continue;
        if(cnt == 1) {
            int x = find(e), y = find(next);
            uni(x, y);
            return;
        }
        else dfs(next, s, cnt+1);
    }
}

void rival_connect() {
    for(int i=1; i<=n; i++) dfs(i, 0, 0);
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<=1000; i++) par[i] = i;
    for(int i=0; i<m; i++) {
        char z;
        int x, y;
        cin >> z >> x >> y;
        int xx = find(x), yy = find(y);
        if(z == 'E') {
            conn[x].push_back(y);
            conn[y].push_back(x);
        }
        else uni(xx, yy);
    }

}

int main() {
    init();
    rival_connect();
    print();
}