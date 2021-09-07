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
int city[101][101];
int parent[101][101];

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j) continue;
            city[i][j] = INF;
            parent[i][j] = INF;
        }
    }
    int u, v, c;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        city[u][v] = min(city[u][v], c);
        parent[u][v] = u;
    }
}

void solve(){
    for(int k = 1; k <= N; k++){
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= N; c++){
                if(city[r][k] == INF || city[k][c] == INF) continue;
                if(city[r][k] + city[k][c] < city[r][c]){
                    city[r][c] = city[r][k] + city[k][c];
                    parent[r][c] = parent[k][c];
                }
            }
        }
    }
    
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            if(r == c || city[r][c] == INF){
                cout << 0 << " ";
                continue;
            }
            cout << city[r][c] << " ";
        }
        cout << "\n";
    }
    
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            if(r == c || parent[r][c] == INF) cout << 0;
            else{
                vector<int> route;
                route.push_back(c);
                for(int dest = c; r != parent[r][dest]; dest = parent[r][dest]){
                    route.push_back(parent[r][dest]);
                }
                route.push_back(r);
                cout << route.size() << " ";
                for(int i = route.size()-1; i >= 0; i--){
                    cout << route[i] << " ";
                }
            }
            cout << "\n";
        }
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
