#include <iostream>

using namespace std;
#define line cout << "===========================\n";
int room[51][51], row, col, now_r, now_c, \
d, d_r[4]={-1, 0, 1, 0}, d_c[4]={0, 1, 0, -1}, d_left[4]={3, 0, 1, 2}, cnt = 0, clean = 0, \
d_back[4] = {2, 3, 0, 1};

void rob_move(){
    while(true){
        if(room[now_r][now_c] == 0){
            room[now_r][now_c] = 2;
            clean++;
            //로봇의 청소 움직임을 볼 수 있음.
//            line
//            for(int i = 0; i < row; i++){
//                for(int j = 0; j < col; j++){
//                    cout <<room[i][j] <<" ";
//                }
//                cout <<"\n";
//            }
        }
        if(room[now_r + d_r[d_left[d]]][now_c + d_c[d_left[d]]] == 0){
            now_r += d_r[d_left[d]];
            now_c += d_c[d_left[d]];
            d = d_left[d];
            cnt = 0;
            continue;
        }
        else{
            d = d_left[d];
            cnt++;
        }
        if(cnt == 4){
            if(room[now_r + d_r[d_back[d]]][now_c + d_c[d_back[d]]] == 1){
                cout << clean;
                return;
            }
            else{
                now_r += d_r[d_back[d]];
                now_c += d_c[d_back[d]];
                cnt = 0;
                continue;
            }
        }
    }
}

void input(){
    cin >> row >> col;
    cin >> now_r >> now_c >> d;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> room[i][j];
        }
    }
}

int main(){
    input();
    rob_move();
    return 0;
}
