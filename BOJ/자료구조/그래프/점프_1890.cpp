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
int Map[101][101];
long long Cache[101][101];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
        }
    }
    memset(Cache, -1, sizeof(Cache));
}

long long dfs(pii now){
    if(now.first == N-1 && now.second == N-1){
        return 1;
    }
    if(!Map[now.first][now.second]){
        return 0;
    }
    
    long long &ret = Cache[now.first][now.second];
    if(ret != -1) return ret;
    
    ret = 0;
    int jump = Map[now.first][now.second];
    
    pii npii1 = {now.first + jump, now.second};
    pii npii2 = {now.first, now.second + jump};
    
    return ret = dfs(npii1) + dfs(npii2);
}

void solve(){
    dfs({0, 0});
    cout << Cache[0][0];
}

int main(){
    input();
    solve();
    
    return 0;
}
