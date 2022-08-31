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

int N, M;
int Map[501][501];

int Top[501][501];
int Front[501]; // 1 ~ M
int Right[501]; // 1 ~ N

void input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }
    
    for(int i = 0; i < M; i++){
        cin >> Front[i];
    }
    for(int i = N-1; i >= 0; i--){
        cin >> Right[i];
    }
}

void printMap(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cout << Map[r][c] << " ";
        }
        cout << '\n';
    }
}

void solve(){
    // 앞부분 채우기
    for(int c = 0; c < M; c++){
        for(int r = 0; r < N; r++){
            if(Map[r][c] != 0){
                Map[r][c] = max(Map[r][c], Front[c]);
            }
        }
    }
    
    bool isMap = false;
    for(int r = 0; r < N; r++){
        int temp = 0;
        for(int c = 0; c < M; c++){
            if(Map[r][c] != 0){
                temp = max(temp, Map[r][c]);
                Map[r][c] = min(Map[r][c], Right[r]);
                isMap = true;
            }
        }
        if(temp < Right[r] && temp != 0){
            cout << "-1";
            return;
        }
    }
    
    if(!isMap) cout << -1;
    else printMap();
    
}

int main(){
    input();
    solve();
    
    return 0;
}
