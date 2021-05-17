#include <bits/stdc++.h>

using namespace std;

int N, K, L, X[101];
int r = 0, c = 0, d = 0, z = 0, result = 0;
// 뱀의 행, 열, 방향, 회전 ,결과값 시간
char C[101];
int board[100][100] = {0, };
const int drow[] = {0, 0, 1, -1}, dcol[] = {1, -1, 0, 0};   //0:right,  1:left,  2:bottom,  3:top
const int lft[] = {3, 2, 0, 1}, rht[] = {2, 3, 1, 0};

queue<pair<int, int>> snake;

void solve(){
    board[r][c] = 1;    //뱀 첫 시작
    snake.push({r, c});

    while(true){
        r += drow[d], c += dcol[d];
        result++;
        if(r < 0 || r >= N || c < 0 || c >= N || board[r][c] == 1){
        // 뱀의 머리의 행과 열 좌표가 board를 벗어났을때 + 자신의 몸통과 부딪혔을 때
            cout << result;
            return;
        }
        //
        if(board[r][c] == 0){   //사과 x, 자신의 몸 x
            int nx = snake.front().first, ny = snake.front().second;
            snake.pop();
            board[nx][ny] = 0;
        }
        board[r][c] = 1;
        snake.push({r, c});
        if(result == X[z]){
            if(C[z] == 'L'){
                d = lft[d];
            }
            else{
                d = rht[d];
            }
            z++;
        }
    }
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        int row, col;
        cin >> row >> col;
        board[row-1][col-1] = 2;    //사과 존재
    }

    cin >> L;
    for(int i = 0; i < L; i++){
        cin >> X[i] >> C[i];
    }
    solve();
    return 0;
}
