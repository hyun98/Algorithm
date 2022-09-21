#include <bits/stdc++.h>

using namespace std;

int N, K, L, X[101];
int r = 0, c = 0, d = 0, z = 0, result = 0;
// ���� ��, ��, ����, ȸ�� ,����� �ð�
char C[101];
int board[100][100] = {0, };
const int drow[] = {0, 0, 1, -1}, dcol[] = {1, -1, 0, 0};   //0:right,  1:left,  2:bottom,  3:top
const int lft[] = {3, 2, 0, 1}, rht[] = {2, 3, 1, 0};

queue<pair<int, int>> snake;

void solve(){
    board[r][c] = 1;    //�� ù ����
    snake.push({r, c});

    while(true){
        r += drow[d], c += dcol[d];
        result++;
        if(r < 0 || r >= N || c < 0 || c >= N || board[r][c] == 1){
        // ���� �Ӹ��� ��� �� ��ǥ�� board�� ������� + �ڽ��� ����� �ε����� ��
            cout << result;
            return;
        }
        //
        if(board[r][c] == 0){   //��� x, �ڽ��� �� x
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
        
        // dir : 0, 1, 2, 3 (인덱스)
        if(NextDir = "LEFT"){
            dir = lft[dir];
        }
        else{
            dir = rht[dir];
        }
    }
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        int row, col;
        cin >> row >> col;
        board[row-1][col-1] = 2;    //��� ����
    }

    cin >> L;
    for(int i = 0; i < L; i++){
        cin >> X[i] >> C[i];
    }
    solve();
    return 0;
}
