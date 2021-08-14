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
int Map[1001][1001];
int visited[1001][1001];
int num[1001][1001];
int outdegree[1000001];
int vcnt, ccnt;
vector<pii > stk;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0}; // E W S N

void input(){
    cin >> N >> M;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            switch (str[j]){
            case 'E': Map[i][j] = 0; break;
            case 'W': Map[i][j] = 1; break;
            case 'S': Map[i][j] = 2; break;
            case 'N': Map[i][j] = 3; break;
            default: break;
            }
        }
    }
    memset(visited, -1, sizeof(visited));
    memset(num, -1, sizeof(num));
}

int dfs(int r, int c){
    int ret = visited[r][c] = vcnt++;
    stk.push_back({r, c});
    
    int nr = r + dr[Map[r][c]];
    int nc = c + dc[Map[r][c]];
    
    if(visited[nr][nc] == -1) ret = min(ret, dfs(nr, nc));
    else if(num[nr][nc] == -1) ret = min(ret, visited[nr][nc]);
    
    if(ret == visited[r][c]){
        while(true){
            pii temp = stk.back();
            stk.pop_back();
            num[temp.first][temp.second] = ccnt;
            if(temp.first == r && temp.second == c) break;
        }
        ccnt++;
    }
    
    return ret;
}

void solve(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(visited[r][c] != -1) continue;
            dfs(r, c);
        }
    }
    
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            int nr = r + dr[Map[r][c]];
            int nc = c + dc[Map[r][c]];
            if(num[r][c] == num[nr][nc]) continue;
            outdegree[num[r][c]]++;
        }
    }
    int res = 0;
    for(int i = 0; i < ccnt; i++){
        if(!outdegree[i]) res++;
    }
    
    cout << res << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
