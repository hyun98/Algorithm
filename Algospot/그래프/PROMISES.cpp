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

int V, M, N;
int highway[201][201];

void init(){
    cin >> V >> M >> N;
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(i == j) highway[i][j] = 0;
            else highway[i][j] = INF;
        }
    }
    
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        highway[a][b] = min(highway[a][b], c);
        highway[b][a] = min(highway[b][a], c);
    }
    
    for(int i = 0; i < V; i++){
        for(int r = 0; r < V; r++){
            for(int c = 0; c < V; c++){
                highway[r][c] = min(highway[r][c], highway[r][i] + highway[i][c]);
            }
        }
    }
}

bool is_valid(int a, int b, int c){
    if(highway[a][b] <= c) return false;
    
    for(int r = 0; r < V; r++){
        for(int c = 0; c < V; c++){
            highway[r][c] = min(highway[r][c], \
                            min(highway[r][a] + c + highway[b][c], \
                                highway[r][b] + c + highway[a][c]));
        }
    }
    
    return true;
}

void solve(){
    int ans = 0;
    
    int a, b, c;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        if(!is_valid(a, b, c)) ans++;
    }
    
    cout << ans << "\n";
}

int main(){
    fasti
    int test;
    cin >> test;
    
    while(test--){
        init();
        solve();
    }
    
    return 0;
}
