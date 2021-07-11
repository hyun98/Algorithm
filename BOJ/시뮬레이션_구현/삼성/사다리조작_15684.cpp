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

int N, M, H;
int ladder[31][11][11];
bool is_find;

void input(){
    int a, b;
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        ladder[a][b][b+1] = 1;
        ladder[a][b+1][b] = 1;
    }
}

void Recursion(int horizon){
    if(horizon == 0){
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            if(Riding(i) == i){
                cnt++;
            }
        }
        if(cnt == N){
            is_find = true;
            return;
        }
    }
    
    for(int i = 1; i <= H; i++){
        for(int r = 1; r <= N; r++){
            if(ladder[i][r][r+1] || ladder[i][r-1][r] || ladder[i][r+1][r+2]) continue;
        }
    }
    
}

int Riding(int line){
    for(int height = 1; height <= H; height++){
        if(line-1 > 0){
            if(ladder[height][line-1][line]){
                line = line-1;
                continue;
            }
        }
        if(line+1 <= N){
            if(ladder[height][line][line+1]){
                line = line+1;
                continue;
            }
        }
    }
    
    return line;
}

void solve(){
    int horizon = 0;
    while(horizon <= 3){
        
        
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            if(Riding(i) == i){
                cnt++;
            }
        }
        if(cnt == N) break;
        horizon++;
    }
    
    cout << horizon;
}

int main(){
    input();
    solve();
    
    return 0;
}
