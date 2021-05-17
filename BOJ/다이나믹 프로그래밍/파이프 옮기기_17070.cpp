#include <iostream>
#include <cstring>
using namespace std;

int N;
int House[18][18];
int dp[18][18][3];

void init(){
    cin >> N;
    memset(House, -1, sizeof(House));
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> House[i][j];
        }
    }
}

//before -> 가로 : 0, 세로 : 1, 대각선 : 2
// row, col에서 N, N으로 갈 수 있는 경우를 반환
int pipe(int before, int row, int col){

    if(row == N && col == N){
        return 1;
    }
    int &ret = dp[row][col][before];
    if(ret != -1) return ret;
    ret = 0;
    
//    cout << "현재 " << row << ", " << col;
    if(before == 0){
        if(House[row+1][col] == 0 && House[row][col+1] == 0 && House[row+1][col+1] == 0){   // 대각선 이동가능
            ret += pipe(2, row+1, col+1);
        } 
        if(House[row][col+1] == 0){     // 가로 이동 가능
            ret += pipe(0, row, col+1);
        }
        
    }
    else if(before == 1){
        if(House[row+1][col] == 0 && House[row][col+1] == 0 && House[row+1][col+1] == 0){   // 대각선 이동가능
            ret += pipe(2, row+1, col+1);
        }
        if(House[row+1][col] == 0){     // 세로 이동 가능
            ret += pipe(1, row+1, col);
        }
    }
    else{
        if(House[row+1][col] == 0 && House[row][col+1] == 0 && House[row+1][col+1] == 0){   // 대각선 이동가능
            ret += pipe(2, row+1, col+1);
        } 
        if(House[row][col+1] == 0){     // 가로 이동 가능
            ret += pipe(0, row, col+1);
        }
        if(House[row+1][col] == 0){     // 세로 이동 가능
            ret += pipe(1, row+1, col);
        }
    }
    return ret;
}

int main(){
    init();
    cout << pipe(0, 1, 2);
    
    return 0;
}
