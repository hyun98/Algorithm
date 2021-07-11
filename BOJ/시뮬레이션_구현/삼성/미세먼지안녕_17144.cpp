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

struct Dust{
    int r, c, d;
};

int R, C, T;
int Map[51][51];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

vector<Dust> Microdust;
vector<pii > Aircleaner;

void input(){
    cin >> R >> C >> T;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cin >> Map[r][c];
            if(Map[r][c] == -1){
                Aircleaner.push_back({r, c});
            }
        }
    }
}

void ready_to_spread(){
    Microdust.clear();
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(Map[r][c] > 0){
                Microdust.push_back({r, c, Map[r][c]});
                Map[r][c] = 0;
            }
        }
    }
}

void Spread_Dust(){
    for(auto &dust : Microdust){
        int cnt = 0;
        int div = dust.d/5;
        for(int k = 0; k < 4; k++){
            int nr = dust.r + dr[k];
            int nc = dust.c + dc[k];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || Map[nr][nc] == -1) continue;
            cnt++;
            Map[nr][nc] += div;
        }
        dust.d -= (cnt * div);
        Map[dust.r][dust.c] += dust.d;
    }
}

void Cleaning(){
    int tr = Aircleaner[0].first;
    int br = Aircleaner[1].first;
    
    // 위쪽 청정기
    for(int r = tr-1; r >= 1; r--){
        Map[r][0] = Map[r-1][0];
    }
    for(int c = 0; c < C-1; c++){
        Map[0][c] = Map[0][c+1];
    }
    for(int r = 0; r < tr; r++){
        Map[r][C-1] = Map[r+1][C-1];
    }
    for(int c = C-1; c >= 1; c--){
        Map[tr][c] = Map[tr][c-1];
        if(Map[tr][c] == -1) Map[tr][c] = 0;
    }
    
    // 아래쪽 청정기
    for(int r = br+1; r < R-1; r++){
        Map[r][0] = Map[r+1][0];
    }
    for(int c = 0; c < C-1; c++){
        Map[R-1][c] = Map[R-1][c+1];
    }
    for(int r = R-1; r > br; r--){
        Map[r][C-1] = Map[r-1][C-1];
    }
    for(int c = C-1; c >= 1; c--){
        Map[br][c] = Map[br][c-1];
        if(Map[br][c] == -1) Map[br][c] = 0;
    }
}

int Dust_Amount(){
    int dust = 0;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(Map[r][c] > 0) dust += Map[r][c];
        }
    }
    return dust;
}
void show(){
    cout << "----------------\n";
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cout << Map[r][c] << " ";
        }
        cout << "\n";
    }
}

void solve(){
    while(T--){
        ready_to_spread();
        Spread_Dust();
        Cleaning();
    }
    
    cout << Dust_Amount();
}

int main(){
    fasti
    input();
    solve();
    
    return 0;
}
