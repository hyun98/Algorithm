#include <iostream>

using namespace std;

int Map[101][101];
int N, L;

void input(){
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
        }
    }
}

int row_road(){
    int road_count = 0;
    int bheight, cnt;
    bool downslide;
    
    for(int r = 0; r < N; r++){
        bheight = Map[r][0];
        cnt = 1;
        downslide = false;
        for(int c = 1; c < N; c++){
//            cout << c << " ";
            if(Map[r][c] == bheight){
                cnt++;
            }
            else if(bheight + 1 == Map[r][c]){
                if(cnt >= L){
                    cnt = 1;
                    bheight = Map[r][c];
                }
                else{
                    cnt = -1;
                    break;
                }
            }
            else if(Map[r][c] + 1 == bheight){
                if(downslide){
                    break;
                }
                downslide = true;
                bheight = Map[r][c];
                cnt = 1;
            }
            else{
                cnt = -1;
                break;
            }
            if(downslide && cnt >= L){
                cnt = 0;
                downslide = false;
            }
        }
        if(!downslide && cnt >= 0){
            road_count++;
//            cout << "r : " << r << "\n";
        }
    }
    
    return road_count;
}

int col_road(){
    int road_count = 0;
    int bheight, cnt;
    bool downslide = false;
    
    for(int c = 0; c < N; c++){
        bheight = Map[0][c];
        cnt = 1;
        downslide = false;
        for(int r = 1; r < N; r++){
            if(Map[r][c] == bheight){
                cnt++;
            }
            else if(bheight + 1 == Map[r][c]){
                if(cnt >= L){
                    cnt = 1;
                    bheight = Map[r][c];
                }
                else{
                    cnt = -1;
                    break;
                }
            }
            else if(Map[r][c] + 1 == bheight){
                if(downslide) break;
                downslide = true;
                bheight = Map[r][c];
                cnt = 1;
            }
            else{
                cnt = -1;
                break;
            }
            if(downslide && cnt >= L){
                cnt = 0;
                downslide = false;
            }
        }
        
        if(!downslide && cnt >= 0){
            road_count++;
//            cout << "c : " << c << "\n";
        }
    }
    
    return road_count;
}

void solve(){
    // 같은 높이가 연속해서 나타나면 몇 개 나타났는지 기록,
    // 높이가 1증가하고 지금까지 지나온 길이가 L이상이면 경사로 가능
    // 높이가 1감소하면 그때부터 동일한 높이가 몇 개 나타나는지 기록,
    // 연속으로 L개 나타난 순간 경사로 가능, 새로 카운팅
    // 아직 경사로 가능하다고 판단하기 전에 높이가 달라지면 해당 행/열은 길 안됨, 다음 행/열로 넘어간다
    
//    cout << row_road() << "\n";
//    cout << col_road();
    cout << row_road() + col_road();
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    input();
    solve();
    
    return 0;
}
