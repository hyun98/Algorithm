#include <iostream>

using namespace std;

int N, Map[2200][2200], result[3];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
        }
    }
}

void solve(int n, int row, int col){
    int color = Map[row][col];
    bool all = true;

    for(int i = row; i < row + n; i++){
        for(int j = col; j < col + n; j++){
            if(Map[i][j] != color){
                all = false;
                solve(n/3, row, col);
                solve(n/3, row, col + n/3);
                solve(n/3, row, col + 2*n/3);
                solve(n/3, row + n/3, col);
                solve(n/3, row + n/3, col + n/3);
                solve(n/3, row + n/3, col + 2*n/3);
                solve(n/3, row + 2*n/3, col);
                solve(n/3, row + 2*n/3, col + n/3);
                solve(n/3, row + 2*n/3, col + 2*n/3);
                return;
            }
        }
    }

    if     (color == -1 && all) result[0]++;
    else if(color ==  0 && all) result[1]++;
    else if(color ==  1 && all) result[2]++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve(N, 0, 0);
    cout << result[0] << "\n" << result[1] << "\n" << result[2];

    return 0;
}
