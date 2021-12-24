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

int R, C, cnt;
int Map[21][21];
bool visited[21][21], temp[21][21];
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
    if(visited[r][c] || temp[r][c]) return false;
}

void dfs(pii now){
    
    for(int k = 0; k < 4; k++){
        
    }
    
}

void solve(){
    dfs({0, 0})
}

int main(){
    input();
    solve();
    
    return 0;
}
