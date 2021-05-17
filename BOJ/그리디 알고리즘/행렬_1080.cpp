#include <iostream>
#include <string>

using namespace std;

int N, M;
int Matrix_A[51][51];
int Matrix_B[51][51];

void input(){
    string in;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> in;
        for(int j = 0; j < in.size(); j++){
            Matrix_A[i][j] = in[j] - '0';
        }
    }
    for(int i = 0; i < N; i++){
        cin >> in;
        for(int j = 0; j < in.size(); j++){
            Matrix_B[i][j] = in[j] - '0';
        }
    }
}

void cover(int r, int c){
    for(int i = r; i < r + 3; i++){
        for(int j = c; j < c + 3; j++){
            if(Matrix_A[i][j]) Matrix_A[i][j] = 0;
            else Matrix_A[i][j] = 1;
        }
    }
}

void solve(){
    int cnt = 0;
    
    for(int i = 0; i < N-2; i++){
        for(int j = 0; j < M-2; j++){
            if(Matrix_A[i][j] != Matrix_B[i][j]){
                cover(i, j);
                cnt++;
            }
        }
    }
    bool fail = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Matrix_A[i][j] != Matrix_B[i][j]){
                fail = true;
            }
        }
    }
    if(fail) cout << -1;
    else cout << cnt;
}

int main(){
    input();
    solve();
    
    return 0;
}