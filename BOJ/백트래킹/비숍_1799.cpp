#include <bits/stdc++.h>

using namespace std;

struct P{
    int is_blocked, color; 
};

int N, bret = 0, wret = 0;
P Board[11][11];
bool Ldiag_bs[21], Rdiag_bs[21];

inline int diagl(int r, int c){
    int ret = r + (N-1-c);
    return ret;
}
inline int diagr(int r, int c){
    int ret = r + c;
    return ret;
}

void Bishop(int r, int c, int cnt, int color){
    if(c == N){
        Bishop(r+1, 0, cnt, color);
        return;
    }
    
    if(r == N){
        if(color == 1) bret = max(bret, cnt);
        else if(color == 2) wret = max(wret, cnt);
        return;
    }
    
    if(!Board[r][c].is_blocked || Board[r][c].color != color){
        Bishop(r, c+1, cnt, color);
        return;
    }
    
    int lidx = diagl(r, c);
    int ridx = diagr(r, c);
    
    if(Ldiag_bs[lidx]){
        Bishop(r, c+1, cnt, color);
        return;
    }
    if(Rdiag_bs[ridx]){
        Bishop(r, c+1, cnt, color);
        return;
    }
    
    Ldiag_bs[lidx] = true;
    Rdiag_bs[ridx] = true;
    Bishop(r, c+1, cnt+1, color);
    Ldiag_bs[lidx] = false;
    Rdiag_bs[ridx] = false;
    Bishop(r, c+1, cnt, color);
}

void input(){
    int b, c;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Board[i][j].is_blocked;
            if((i + j) % 2) Board[i][j].color = 1;
            else Board[i][j].color = 2;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    Bishop(0, 0, 0, 1);
    Bishop(0, 0, 0, 2);
    
    cout << bret + wret;
    return 0;
}