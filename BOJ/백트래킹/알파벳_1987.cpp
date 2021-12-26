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

int R, C, ans;
int Map[21][21];
bool visited[21][21], visited_alpha[26];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};


void input(){
    cin >> R >> C;
    string str;
    for(int i = 0; i < R; i++){
        cin >> str;
        for(int j = 0; j < C; j++){
            Map[i][j] = str[j] - 'A';
        }
    }
}

bool is_valid(int r, int c){
    if(r < 0 || r >= R || c < 0 || c >= C) return false;
    if(visited[r][c] || visited_alpha[Map[r][c]]) return false;
    return true;
}

void dfs(int r, int c, int cnt){
    ans = max(ans, cnt);
    
    visited_alpha[Map[r][c]] = true;
    visited[r][c] = true;
    
    for(int k = 0; k < 4; k++){
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(!is_valid(nr, nc)) continue;
        dfs(nr, nc, cnt+1);
    }
    
    visited[r][c] = false;
    visited_alpha[Map[r][c]] = false;
}

void solve(){
    dfs(0, 0, 1);
    
    cout << ans;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
