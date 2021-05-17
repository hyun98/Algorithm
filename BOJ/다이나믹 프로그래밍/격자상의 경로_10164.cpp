#include <iostream>

using namespace std;

int dp[16][16];
int N, M, K;

int vias[2];
int dr[2] = {0, 1};
int dc[2] = {1, 0};

void input(){
    int cnt = 1;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            dp[i][j] = -1;
            if(cnt == K){
                vias[0] = i;
                vias[1] = j;
            }
            cnt++;
        }
    }
}

//void show(){
//    for(int i = 0; i < N; i++){
//        for(int j = 0; j < M; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//}

int Move(int row, int col, int m){
    int& ret = dp[row][col];
    if(ret != -1) return ret;
    ret = 0;
    
    if(m == 0 && row == vias[0] && col == vias[1]) return ret = 1;
    if(m == 1 && row == N-1     && col == M-1)     return ret = 1;
    
    for(int i = 0; i < 2; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];
        

        if(m == 0 && nr <= vias[0] && nc <= vias[1]) ret += Move(nr, nc, m);
        if(m == 1 && nr <  N       && nc < M)        ret += Move(nr, nc, m);
    }
    return ret;
}


void solve(){
    int vresult, result;
    vresult = Move(0, 0, 0);
//    show();
    dp[vias[0]][vias[1]] = -1;
    result = Move(vias[0], vias[1], 1);
//    show();
    
    cout << vresult * result;
}

int main(){
    input();
    solve();
    
    return 0;
}
