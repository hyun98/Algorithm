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

struct BALL{
    int mass, speed, dir;
};

int N, M, K;
vector<BALL> Map[51][51];
vector<BALL> tMap[51][51];
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void input(){
    cin >> N >> M >> K;
    int r, c, m, s, d;
    for(int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        Map[r-1][c-1].push_back({m, s, d});
    }
}

void Move(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(auto &w: Map[i][j]){
                int nr = i + (w.speed % N) * dr[w.dir];
                int nc = j + (w.speed % N) * dc[w.dir];
                if(nr < 0)       nr = N + nr;
                else if(nr >= N) nr %= N;
                if(nc < 0)       nc = N + nc;
                else if(nc >= N) nc %= N;
                
                tMap[nr][nc].push_back({w.mass, w.speed, w.dir});
            }
            Map[i][j].clear();
        }
    }
}

void Divide(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(tMap[i][j].size() < 2) continue;
            int sum_mass = 0;
            int sum_speed = 0;
            int prev_dir = -1;
            bool issame = true;
            for(auto &w: tMap[i][j]){
                sum_mass += w.mass;
                sum_speed += w.speed;
                if(prev_dir == -1) prev_dir = w.dir;
                else if(prev_dir % 2 != w.dir % 2) issame = false;
            }
            int div_cnt = tMap[i][j].size();
            tMap[i][j].clear();
            if(sum_mass / 5 == 0) continue;
            for(int k = 0; k < 4; k++){
                if(issame) tMap[i][j].push_back({sum_mass/5, sum_speed/div_cnt, k*2});
                else       tMap[i][j].push_back({sum_mass/5, sum_speed/div_cnt, k*2 + 1});
            }
        }
    }
}

void CopyM(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Map[i][j] = tMap[i][j];
            tMap[i][j].clear();
        }
    }
}

int Sum_of_Mass(){
    int sum_of_mass = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(auto &w: Map[i][j]){
                sum_of_mass += w.mass;
            }
        }
    }
    return sum_of_mass;
}

void solve(){
    while(K--){
        Move();
        Divide();
        CopyM();
    }
    cout << Sum_of_Mass() << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
