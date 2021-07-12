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

int N, M, H, Now;
int ladder[31][11];
bool is_find;

void input(){
    int a, b;
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        ladder[a][b] = 1;
    }
}

bool Riding(){
    for(int i = 1; i <= N; i++){
        int line = i;
        for(int height = 1; height <= H; height++){
            if(ladder[height][line]) line += 1;
            else if(ladder[height][line-1]) line -= 1;
        }
        if(line != i) return false;
    }
    
    return true;
}

void Recursion(int nowheight, int horizoncnt){
    if(horizoncnt == 0){
        bool tmp = true;
        // **문제의 부분**
        for(int i = 1; i <= N; i++){
            int line = i;
            for(int height = 1; height <= H; height++){
                if(ladder[height][line]) line += 1;
                else if(ladder[height][line-1]) line -= 1;
            }
            if(line != i) return;
        }
        if(tmp){
            cout << Now;
            exit(0);
        }
    }
    
    for(int i = nowheight; i <= H; i++){
        for(int r = 1; r < N; r++){
            if(ladder[i][r-1] || ladder[i][r+1] || ladder[i][r]) continue;
            
            ladder[i][r] = 1;
            Recursion(i, horizoncnt-1);
            ladder[i][r] = 0;
        }
    }
}


void solve(){
    int horizon = 0;
    while(horizon <= 3){
        Now = horizon;
        Recursion(1, horizon);
        horizon++;
    }
    
    cout << -1;
}

int main(){
    fasti
    input();
    solve();
    
    return 0;
}
