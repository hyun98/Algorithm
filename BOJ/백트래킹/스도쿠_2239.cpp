#include <iostream>

using namespace std;

int Map[10][10];

void input(){
    string line;
    for(int i = 0; i < 9; i++){
        cin >> line;
        for(int j = 0; j < 9; j++){
            Map[i][j] = line[j] - '0';
        }
    }
}

void show_Map(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << Map[i][j];
        }
        cout << "\n";
    }
}

// Map에 1~9까지의 숫자를 넣어보고 룰에 어긋나면 false 반환
inline bool check_rule(int r, int c){
    // row, col check
    for(int i = 0; i < 9; i++){
        // row check
        if(Map[r][c] == Map[r][i] && i != c) return false;
        // col check
        if(Map[r][c] == Map[i][c] && i != r) return false;
    }
    
    int sr = (r / 3) * 3;
    int sc = (c / 3) * 3;
    
    // box check
    for(int i = sr; i < sr + 3; i++){
        for(int j = sc; j < sc + 3; j++){
            if(i == r && j == c) continue;
            if(Map[r][c] == Map[i][j]) return false;
        }
    }
    
    return true;
}

void solve(int r, int c){
    if(r == 9){
        show_Map();
        exit(0);
    }
    
    if(c == 9){
        solve(r + 1, 0);
        return;
    }
    
    if(Map[r][c] == 0){
        for(int i = 1; i <= 9; i++){
            Map[r][c] = i;
            if(check_rule(r, c)) solve(r, c+1);
        }
        Map[r][c] = 0;
    }
    
    else solve(r, c+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve(0, 0);
    
    return 0;
}
