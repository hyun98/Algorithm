#include <iostream>

using namespace std;

int Map[9][9];

void showResult(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << Map[i][j] << " ";
        }
        cout << endl;
    }
}

bool ruleCheck(int r, int c){
    
    for(int i = 0; i < 9; i++){
        if(Map[r][i] == Map[r][c] && i != c) return false;
        if(Map[i][c] == Map[r][c] && i != r) return false;
    }
    
    for(int i = r/3 * 3; i < r/3 * 3 + 3; i++){
        for(int j = c/3 * 3; j < c/3 * 3 + 3; j++){
            if(Map[i][j] == Map[r][c] && r!=i && c!=j) return false;
        }
    }
    return true;
}

void sdokuSolver(int now){
    if(now == 81){
        showResult();
        exit(0);
    }
    
    int row = now / 9;
    int col = now % 9;
    
    if(Map[row][col] != 0){
        sdokuSolver(now+1);
    }
    else{
        for(int i = 1; i <= 9; i++){
            Map[row][col] = i;
            if(ruleCheck(row, col)) sdokuSolver(now+1);
        }
        Map[row][col] = 0;
    }
}

void input(){
    for(int i = 0; i < 9; i++){
            
        for(int j = 0; j < 9; j++){
            cin >> Map[i][j];
        }
    }
}

int main(){
    input();
    sdokuSolver(0);
    
    return 0;
}
