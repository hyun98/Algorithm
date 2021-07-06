#include <iostream>
#include <vector>

using namespace std;

struct Coord{
    int r, c;
};

int N, M, cnt;
vector<string> Map;
Coord redM, blueM, Hole;

void input(){
    string str;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> str;
        Map.push_back(str);
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Map[i][j] == 'R') redM = {i, j};
            else if(Map[i][j] == 'B') blueM = {i, j};
            else if(Map[i][j] == 'O') Hole = {i, j};
        }
    }
}


int move_left(Coord &marvel, int s, vector<string> &tmap){
    int tcnt = 0;
    Coord before = marvel;
    for(int i = marvel.c-1; i >= 0; i--){
        char now = tmap[marvel.r][i];
        if(now == '#' || now == 'B' || now == 'R'){
            marvel = {marvel.r, i+1};
            tmap[before.r][before.c] = '.';
            if(s == 0) tmap[marvel.r][marvel.c] = 'R';
            else tmap[marvel.r][marvel.c] = 'B';
            
            return tcnt;
        }
        else if(now == 'O') return -tcnt-1;
        tcnt++;
    }
}

int slope_left(Coord &red, Coord &blue, vector<string> &tmap){
    int holein = false;
    
    if(red.r == blue.r){
        if(red.c < blue.c){
            if(move_left(red, 0, tmap) >= 0){
                if(move_left(blue, 1, tmap) < 0) return 0;
                else return 1;
            }
            else return 2;
        }
        else{
            if(move_left(blue, 1, tmap) >= 0){
                if(move_left(red, 0, tmap) < 0) return 2;
                else return 1;
            }
            else return 0;
        }
    }
    else{
        int rmcnt = move_left(red, 0, tmap);
        int bmcnt = move_left(blue, 1, tmap);
        if(rmcnt >= 0 && bmcnt >= 0) return 1;
        else if(rmcnt < 0 && bmcnt < 0){
            if(abs(rmcnt) < abs(bmcnt)) return 2;
            else return 0;
        }
        else if(bmcnt < 0) return 0;
        else if(rmcnt < 0) return 2;
    }
    return 1;
}
int slope_top(){
    
}
int slope_down(){
    
}


void show(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << Map[i][j] << "";
        }
        cout << "\n";
    }
}

void solve(vector<string> amap, Coord redm, Coord bluem, int mcnt){
    
    
    slope_left()
    
    int k = slope_left(nowred, nowblue, amap);
    
    if(k == 0){
        cout << "blue in hole first\n";
    }
    if(k == 1){
        show();
    }
    if(k == 2){
        cout << "hone in\n";
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
