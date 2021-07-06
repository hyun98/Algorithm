#include <iostream>
#include <vector>

using namespace std;

struct Wheel{
    int tooth[8];
};

// N극 0, S극 1
Wheel Saw[4];
int K;
vector<pair<int, int> > Rinfo;

void input(){
    string str;
    for(int i = 0; i < 4; i++){
        cin >> str;
        for(int k = 0; k < 8; k++){
            Saw[i].tooth[k] = str[k] - '0';
        }
    }
    int a, b;
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        Rinfo.push_back({a, b});
    }
}

void RotateWheel(int wheelnum, int dir, int lr){
    int now3 = Saw[wheelnum].tooth[2];
    int now9 = Saw[wheelnum].tooth[6];
    int nextdir = (dir == 1? -1 : 1);
    
    // **** 현재 바퀴 회전 ****
    int temp[8];
    if(dir == 1){
        for(int i = 1; i <= 8; i++){
            temp[i % 8] = Saw[wheelnum].tooth[i-1];
        }
    }
    else if(dir == -1){
        for(int i = 7; i >= 0; i--){
            temp[(i+7) % 8] = Saw[wheelnum].tooth[i];
        }
    }
    for(int i = 0; i < 8; i++){
        Saw[wheelnum].tooth[i] = temp[i];
    }
    
    
    // **** 근처의 바퀴가 영향을 받는지 확인하고 회전시키는 함수 호출 ****
    if(wheelnum == 0){
        if(lr >= 0 && now3 != Saw[1].tooth[6]) RotateWheel(1, nextdir, 1);
    }
    else if(wheelnum == 1){
        if(lr >= 0 && now3 != Saw[2].tooth[6]) RotateWheel(2, nextdir, 1);
        if(lr <= 0 && now9 != Saw[0].tooth[2]) RotateWheel(0, nextdir, -1);
    }
    else if(wheelnum == 2){
        if(lr >= 0 && now3 != Saw[3].tooth[6]) RotateWheel(3, nextdir, 1);
        if(lr <= 0 && now9 != Saw[1].tooth[2]) RotateWheel(1, nextdir, -1);
    }
    else if(wheelnum == 3){
        if(lr <= 0 && now9 != Saw[2].tooth[2]) RotateWheel(2, nextdir, -1);
    }
}

void Solve(){
    
    for(int i = 0; i < K; i++){
        int wheelnum = Rinfo[i].first;
        int dir = Rinfo[i].second;
        RotateWheel(wheelnum-1, dir, 0);
    }
    
    int res = 0;
    
    if(Saw[0].tooth[0]) res += 1;
    if(Saw[1].tooth[0]) res += 2;
    if(Saw[2].tooth[0]) res += 4;
    if(Saw[3].tooth[0]) res += 8;
    
    cout << res;
}

int main(){
    input();
    Solve();
    
    return 0;
}