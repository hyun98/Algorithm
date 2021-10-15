#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7

using namespace std;

int N;
int baseMap[21][21];
int tempMap[21][21];

void input(){
    cin >> N;
    string line;
    for(int i = 0; i < N; i++){
        cin >> line;
        for(int j = 0; j < N; j++){
            if(line[j] == 'H') baseMap[i][j] = 1;
            else baseMap[i][j] = 0;
        }
    }
}

void copy_map(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tempMap[i][j] = baseMap[i][j];
        }
    }
}

void turncoin(int state){
    for(int i = 0; i < N; i++){
        // i번째 행을 뒤집는 경우
        if((state >> i) & 1){
            for(int j = 0; j < N; j++){
                tempMap[i][j] = !tempMap[i][j];
            }
        }
    }
}

int makeMinHead(){
    int ans = 0;
    for(int i = 0; i < N; i++){
        int headcnt = 0;
        for(int j = 0; j < N; j++){
            if(tempMap[j][i]) headcnt++;
        }
        if(N - headcnt > headcnt) ans += headcnt;
        else ans += (N - headcnt);
    }
    return ans;
}

void solve(){
    int ans = INF;
    for(int i = 0; i < (1 << N); i++){
        copy_map();
        turncoin(i);
        ans = min(ans, makeMinHead());
    }
    
    cout << ans;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
