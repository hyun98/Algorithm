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

int V, E, T;
pii crackdown[501];
int Graph[501][501];
int res[501][501];
pii output[1001];

void input(){
    int a, b, c;
    cin >> V >> E;
    for(int i = 1; i <= V; i++){
        cin >> a;
        crackdown[i] = {a, i};
    }
    
    for(int r = 1; r <= V; r++){
        for(int c = 1; c <= V; c++){
            Graph[r][c] = INF;
            res[r][c] = INF;
        }
    }
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        Graph[a][b] = c;
        Graph[b][a] = c;
    }
    
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> a >> b;
        output[i] = {a, b};
    }
}

void solve(){
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i == j) res[i][j] = 0;
            else res[i][j] = Graph[i][j];
        }
    }
    
    sort(crackdown+1, crackdown+V+1);
    
    for(int i = 1; i <= V; i++){
        int via = crackdown[i].second;
        int delay = crackdown[i].first;
        for(int r = 1; r <= V; r++){
            for(int c = 1; c <= V; c++){
                Graph[r][c] = min(Graph[r][c], Graph[r][via] + Graph[via][c]);
                res[r][c] = min(res[r][c], Graph[r][via] + delay + Graph[via][c]);
            }
        }
    }
    
    for(int i = 0; i < T; i++){
        cout << res[output[i].first][output[i].second] << "\n";
    }
    
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
