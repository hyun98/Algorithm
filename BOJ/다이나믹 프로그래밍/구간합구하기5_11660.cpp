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

int Map[1025][1025];
int DP[1025][1025];
int N, M;
vector<pii > oper[2];

void input(){
    cin >> N >> M;
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            cin >> Map[r][c];
        }
    }
    
    int x1, y1, x2, y2;
    for(int i = 0; i < M; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        oper[0].push_back({x1, y1});
        oper[1].push_back({x2, y2});
    }
}

void init(){
    for(int i = 1; i <= N; i++){
        DP[1][i] = DP[1][i-1] + Map[1][i];
    }
    
    for(int r = 2; r <= N; r++){
        for(int c = 1; c <= N; c++){
            DP[r][c] = DP[r-1][c] + DP[r][c-1] + Map[r][c] - DP[r-1][c-1];
        }
    }
}

void solve(){
    vector<int> res;
    
    int r1, c1, r2, c2;
    for(int i = 0; i < M; i++){
        r1 = oper[0][i].first;
        c1 = oper[0][i].second;
        r2 = oper[1][i].first;
        c2 = oper[1][i].second;
        
        res.push_back(DP[r2][c2] - DP[r1-1][c2] - DP[r2][c1-1] + DP[r1-1][c1-1]);
    }
    
    for(auto &w : res){
        cout << w << "\n";
    }
}

int main(){
    fastio
    input();
    init();
    solve();
    
    return 0;
}
