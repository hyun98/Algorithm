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

int OriginMap[16][16];
int Map[16][16];
int N, M, D;
int answer;

void input(){
    cin >> N >> M >> D;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> Map[r][c];
            OriginMap[r][c] = Map[r][c];
        }
    }
}

inline int dist(int r1, int c1, int r2, int c2){
    return abs(r1-r2) + abs(c1-c2);
}

struct T{
    int r, c, d;
};

bool cmp(T &a, T &b){
    if(a.d == b.d) return a.c < b.c;
    else return a.d < b.d;
}

void copyMap(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            Map[r][c] = OriginMap[r][c];
        }
    }
}

int attack(vector<int> &archerCols){
    int ret = 0;
    
    int archerRow = N;
    while(archerRow >= 1){
        vector<pii> ex;
        for(auto &archerCol: archerCols){
            vector<T> target;
            for(int r = 0; r < archerRow; r++){
                for(int c = 0; c < M; c++){
                    if(!Map[r][c]) continue;
                    if(dist(r, c, archerRow, archerCol) > D) continue;
                    target.push_back({r, c, dist(r, c, archerRow, archerCol)});
                }
            }
            if(target.empty()) continue;
            sort(target.begin(), target.end(), cmp);
            ex.push_back({target[0].r, target[0].c});
        }
        
        for(auto &e: ex){
            if(Map[e.first][e.second] == 1){
                Map[e.first][e.second] = 0;
                ret++;
            }
        }
        
        archerRow--;
    }
    
    return ret;
}

void archerCombination(int n, int i, vector<int> &archerCol){
    if(n == 3){
        copyMap();
        answer = max(answer, attack(archerCol));
        return;
    }
    
    for(int k = i; k < M; k++){
        archerCol.push_back(k);
        archerCombination(n+1, k+1, archerCol);
        archerCol.pop_back();
    }
}


void solve(){
    vector<int> archerCol;
    archerCombination(0, 0, archerCol);
    cout << answer;
}

int main(){
    input();
    solve();
    
    return 0;
}
