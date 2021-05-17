#include <bits/stdc++.h>

using namespace std;

int N, M, x, y, K, nowr, nowc;
int Map[21][21];
// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
int Operation[1001];

// 아래면 : 1, 북쪽으로가는면 : 2, 동쪽으로가는면 : 3, 서쪽으로가는면 : 4, 남쪽으로가는면 : 5, 현재윗면 : 6
int dice_idx[7] = {0,1,2,3,4,5,6};
int dice[7];
int dr[5] = {0, 0, 0, -1, 1}, dc[5] = {0, 1, -1, 0, 0};

void Move(int op){
    int temp = dice_idx[1];
    switch (op){
        case 1: 
            dice_idx[1] = dice_idx[3];
            dice_idx[3] = dice_idx[6];
            dice_idx[6] = dice_idx[4];
            dice_idx[4] = temp;
            break;
            
        case 2:
            dice_idx[1] = dice_idx[4];
            dice_idx[4] = dice_idx[6];
            dice_idx[6] = dice_idx[3];
            dice_idx[3] = temp;
            break;
        
        case 3:
            dice_idx[1] = dice_idx[2];
            dice_idx[2] = dice_idx[6];
            dice_idx[6] = dice_idx[5];
            dice_idx[5] = temp;
            break;
            
        case 4:
            dice_idx[1] = dice_idx[5];
            dice_idx[5] = dice_idx[6];
            dice_idx[6] = dice_idx[2];
            dice_idx[2] = temp;
            break;
        
        default: break;
    }
}

void solve(){
    int r = x;
    int c = y;
    for(int i = 0; i < K; i++){
        int nr = r + dr[Operation[i]];
        int nc = c + dc[Operation[i]];
        if(nr >= N || nr < 0 || nc >= M || nc < 0) continue;
        Move(Operation[i]);
        if(Map[nr][nc] == 0){
            Map[nr][nc] = dice[dice_idx[1]];
        }
        else{
            dice[dice_idx[1]] = Map[nr][nc];
            Map[nr][nc] = 0;
        }
        cout << dice[dice_idx[6]] << "\n";
        r = nr;
        c = nc;
    }
}

void input(){
    cin >> N >> M >> x >> y >> K;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        cin >> Operation[i];
    }
}

int main(){
    input();
    solve();
    
    return 0;
}