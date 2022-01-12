#include <iostream>

using namespace std;

int N, paper[129][129], wp = 0, bp = 0;

void divide(int N, int row, int col){
    if(N == 0) return;

    bool white = false, blue = false;
    for(int i = row; i < row + N; i++){
        for(int j = col; j < col + N; j++){
            if(paper[i][j] == 0) white = true;
            else blue = true;
        }
    }
    if(white && blue){
        divide(N/2, row, col+N/2) ;          //2 사분면
        divide(N/2, row, col);               //1
        divide(N/2, row+N/2, col);           //3
        divide(N/2, row+N/2, col+N/2);       //4
    }
    else if(white) wp++;
    else if(blue) bp++;
}

void input(){
    cin >> N;
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            cin >> paper[row][col];
        }
    }
}

int main(){
    input();
    divide(N, 0, 0);
    cout << wp << "\n" << bp;
    
    return 0;
}
