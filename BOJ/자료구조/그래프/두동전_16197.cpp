#include <iostream>
#include <queue>
#include <cstring>

#define pii pair<int, int>

using namespace std;


int N, M, result = 1e9+7;
int Map[21][21];    // 2 : 동전 위치   0 : 벽 위치   1 : 빈칸
vector< pii > startP;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void input(){
    memset(Map, -1, sizeof(Map));
    
    cin >> N >> M;
    string str;
    for(int i = 1; i <= N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            if(str[j] == 'o'){
                Map[i][j+1] = 2;
                startP.push_back({i, j+1});
            }
            else if(str[j] == '#') Map[i][j+1] = 0;
            else Map[i][j+1] = 1;
        }
    }
}

bool isOut(const pii &A){
    if(A.first < 1 || A.first > N || A.second < 1 || A.second > M) return true;
    return false;
}

void dfs(pii A, pii B, int cnt){
    if(result < cnt) return;
    if(cnt > 10){
        result = min(result, cnt);
        return;
    }
    
    // 둘 다 떨어졌으면 되돌아감
    if(isOut(A) && isOut(B)) return;
    // 하나만 떨어졌으면 result를 최소 cnt값으로 교체
    else if((isOut(A) && !isOut(B)) || (!isOut(A) && isOut(B))){
        result = min(result, cnt);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        pii An = {A.first + dr[i], A.second + dc[i]};
        pii Bn = {B.first + dr[i], B.second + dc[i]};
        if(!Map[An.first][An.second]) An = A;
        if(!Map[Bn.first][Bn.second]) Bn = B;
        
        dfs(An, Bn, cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    input();
    dfs(startP[0], startP[1], 0);
    
    if(result > 10) cout << -1;
    else cout << result;
    
    return 0;
}