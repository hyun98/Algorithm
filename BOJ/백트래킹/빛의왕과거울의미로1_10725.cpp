#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

struct PII {
    int r, c, dir;
};

int N, M, x, y;
int Map[9][9];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
PII bnumber[34];

pii Qnum[11];
int Qn = 0;

void input(){
    cin >> N >> M >> x >> y;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            if(str[j] == '/'){ // 1
                Map[i][j] = 1;
            }
            else if(str[j] == '\\'){ // 2
                Map[i][j] = 2;
            }
            else if(str[j] == '.'){ // 3
                Map[i][j] = 3;
            }
            else{ // ? == 4
                Map[i][j] = 4;
                Qnum[Qn++] = {i, j};
            }
        }
    }
    
    int num = 1;
    for(int c = 0; c < M; c++){
        bnumber[num++] = {0, c, 2};
    }
    for(int r = 0; r < N; r++){
        bnumber[num++] = {r, 0, 0};
    }
    for(int r = 0; r < N; r++){
        bnumber[num++] = {r, M-1, 1};
    }
    for(int c = 0; c < M; c++){
        bnumber[num++] = {N-1, c, 3};
    }
    
}

int opposite(int d){
    if(d == 0) return 1;
    else if(d == 1) return 0;
    else if(d == 2) return 3;
    else return 2;
}

int slash(int d){
    if(d == 0) return 3;
    else if(d == 1) return 2;
    else if(d == 2) return 1;
    else return 0;
}

int backslash(int d){
    if(d == 0) return 2;
    else if(d == 1) return 3;
    else if(d == 2) return 0;
    else return 1;
}


int searchAllCase(int r, int c, int dir){
    if(r == bnumber[y].r + dr[opposite(bnumber[y].dir)] && c == bnumber[y].c + dc[opposite(bnumber[y].dir)]){
        return 1;
    }
    
    if(r < 0 || r >= N || c < 0 || c >= M) return 0;
    
    
    int cnt = 0;
    
    if(Map[r][c] == 3){
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        cnt += searchAllCase(nr, nc, dir);
    }
    else if(Map[r][c] == 2){
        int newdir = backslash(dir);
        int nr = r + dr[newdir];
        int nc = c + dc[newdir];
        cnt += searchAllCase(nr, nc, newdir);
    }
    else{
        int newdir = slash(dir);
        int nr = r + dr[newdir];
        int nc = c + dc[newdir];
        cnt += searchAllCase(nr, nc, newdir);
    }
    
    return cnt;
}

int visited[11];
int ANS;
void backtracking(int n){
    if(n == Qn){
        ANS += searchAllCase(bnumber[x].r, bnumber[x].c, bnumber[x].dir);
        ANS %= 10007;
        return;
    }
    
    for(int i = 1; i <= 3; i++){
        int qr = Qnum[n].first;
        int qc = Qnum[n].second;
        Map[qr][qc] = i;
        backtracking(n+1);
    }
}

void solve(){
    backtracking(0);
    cout << ANS % 10007;
}

int main(){
    input();
    solve();
    
    return 0;
}
