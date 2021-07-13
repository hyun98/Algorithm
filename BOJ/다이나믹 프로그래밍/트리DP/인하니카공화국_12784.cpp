#include <iostream>
#include <cstring>
#define INF 2e9+7

using namespace std;

int N, M, Cost[1001][1001];
bool visited[1001];

int dfs(int before, int now){
    visited[now] = true;
    int temp = 0;
    
    for(int next = 1; next <= N; next++){
        if(visited[next] || !Cost[now][next]) continue;
        temp += dfs(now, next);
    }
    if(temp) return min(Cost[before][now], temp);
    
    return Cost[before][now];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a, b, c;
        cin >> N >> M;
        
        Cost[0][1] = INF;
        
        for(int i = 0; i < M; i++){
            cin >> a >> b >> c;
            Cost[a][b] = Cost[b][a] = c;
        }
        if(M == 0) cout << 0 << "\n";
        else cout << dfs(0, 1) << "\n";
        
        memset(Cost, 0, sizeof(Cost));
        memset(visited, 0, sizeof(visited));
    }
    
    return 0;
}
