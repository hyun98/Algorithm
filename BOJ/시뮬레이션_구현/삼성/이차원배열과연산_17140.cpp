#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int Map[201][201];
int SubMap[201][201];
int R, C, K;

int nowR, nowC, subR, subC;

void input(){
    cin >> R >> C >> K;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> Map[i][j];
        }
    }
    nowR = 3; nowC = 3;
}

void R_Op(int row){
    int counting[101] = {0, };
    vector<pii > temp;
    int max_num = 0;
    // 현재 row에 있는 숫자 counting
    for(int i = 1; i <= nowC; i++){
        counting[Map[row][i]]++;
        max_num = max(max_num, Map[row][i]);
    }
    
    for(int i = 1; i <= max_num; i++){
        if(counting[i]) temp.push_back({counting[i], i});
    }
    sort(temp.begin(), temp.end());
    
    int tsize = temp.size();
    for(int i = 0; i < tsize; i++){
        SubMap[row][i*2+1] = temp[i].second;
        SubMap[row][i*2+2] = temp[i].first;
    }
    
    subC = max(subC, tsize*2);
}

void C_Op(int col){
    int counting[101] = {0, };
    vector<pii > temp;
    int max_num = 0;
    // 현재 col에 있는 숫자 counting
    for(int i = 1; i <= nowR; i++){
        counting[Map[i][col]]++;
        max_num = max(max_num, Map[i][col]);
    }
    
    for(int i = 1; i <= max_num; i++){
        if(counting[i]) temp.push_back({counting[i], i});
    }
    sort(temp.begin(), temp.end());
    
    int tsize = temp.size();
    for(int i = 0; i < tsize; i++){
        SubMap[i*2+1][col] = temp[i].second;
        SubMap[i*2+2][col] = temp[i].first;
    }
    
    subR = max(subR, tsize*2);
}

inline void copyMap(){
    memset(Map, 0, sizeof(Map));
    for(int r = 1; r <= nowR; r++){
        for(int c = 1; c <= nowC; c++){
            Map[r][c] = SubMap[r][c];
        }
    }
    memset(SubMap, 0, sizeof(SubMap));
}

void show(){
    cout << "----Mapshow----\n";
    for(int r = 1; r <= nowR; r++){
        for(int c = 1; c <= nowC; c++){
            cout << Map[r][c] << " ";
        }
        cout << "\n";
    }
}
void subshow(){
    cout << "----SubMapshow----\n";
    for(int r = 1; r <= nowR; r++){
        for(int c = 1; c <= nowC; c++){
            cout << SubMap[r][c] << " ";
        }
        cout << "\n";
    }
}

void solve(){
    int cnt = 0;
    
    while(cnt <= 100){
        if(Map[R][C] == K){
            cout << cnt;
            return;
        }
        
        if(nowR >= nowC){
            for(int i = 1; i <= nowR; i++){
                R_Op(i);
            }
            nowC = subC;
        }
        else{
            for(int i = 1; i <= nowC; i++){
                C_Op(i);
            }
            nowR = subR;
        }
        
        copyMap();
        cnt++;
    }
    
    cout << -1;
}

int main(){
    input();
    solve();
    
    return 0;
}
