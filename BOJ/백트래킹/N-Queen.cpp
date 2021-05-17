#include <iostream>
using namespace std;

int N;
int qr[16], qc[16];

// r, c 좌표에 퀸을 놓으려고 한다
int Queen(int r, int c){
    
    for(int i = 0; i < r; i++){
        if(qr[i] == r) return 0; // i번째 행에 퀸이 있는 경우
        if(qc[i] == c) return 0; // i번째 열에 퀸이 있는 경우
        if(abs(qr[i] - r) == abs(qc[i] - c)) return 0; // 대각선 겹침
    }
    
    if(r == N-1) return 1;
    
    // 조건을 모두 통과했으면 r, c에 퀸을 놓는다
    qr[r] = r;
    qc[r] = c;
    
    int ret = 0;
    for(int i = 0; i < N; i++){
        ret += Queen(r+1, i);
    }
    return ret;
}

int main(){
    cin >> N;
    int r = 0;
    
    for(int i = 0; i < N; i++){
        r += Queen(0, i);
    }
    
    cout << r << endl;
    return 0;
}
