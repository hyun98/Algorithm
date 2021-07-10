#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int Map[101][101];
int N, M;

void input(){
    int a, b;
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> a >> b;
        Map[a][b] = 1;
    }
}

void solve(){
    for(int i = 1; i <= N; i++){
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= N; c++){
                if(Map[r][i] && Map[i][c]) Map[r][c] = 1;
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        int res = 0;
        for(int j = 1; j <= N; j++){
            if(!Map[i][j] && !Map[j][i]) res++;
        }
        cout << res - 1 << "\n";
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
