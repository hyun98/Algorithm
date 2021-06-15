#include <iostream>

using namespace std;

int N, Map[32][32];
double per[4];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

double result;

void solve(int cnt, int r, int c, double chance){
    if(cnt == N) return;
    
    Map[r][c] = 1;
    
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(Map[nr][nc]){
            result += (chance * (per[i]/100));
            continue;
        }
        
        solve(cnt+1, nr, nc, chance * (per[i] / 100));
    }
    
    Map[r][c] = 0;
}

int main(){
    cin >> N;
    cin >> per[0] >> per[1] >> per[2] >> per[3];
    
    solve(0, 15, 15, 1);
    
    printf("%.10lf", 1-result);
    return 0;
}
