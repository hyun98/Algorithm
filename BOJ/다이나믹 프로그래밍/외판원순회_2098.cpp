#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e9 + 7;

int N;
int Map[17][17];

int dp[16][1 << 16];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
}

int TSP(int now, int visited){
    // 1 << N : 10000000000000000
    // (1 << N) - 1 : 01111111111111111
    // 모두 방문 했을 경우
    if(visited == (1 << N) - 1){
        if(Map[now][0] != 0) return Map[now][0];
        return INF;
    }
    
    int &ret = dp[now][visited];
    if(ret != -1) return ret;
    ret = INF;
    
    
    for(int next = 0; next < N; next++){
        // 이미 방문했거나 || 갈 수 없으면
        if(visited & (1 << next) || Map[now][next] == 0) continue;
        int temp = Map[now][next] + TSP(next, visited + (1 << next));
        ret = min(ret, temp);
    }
    
    return ret;
}

int main(){
    input();
    // 1 -> 0000000000000001
    cout << TSP(0, 1);
    
    return 0;
}
