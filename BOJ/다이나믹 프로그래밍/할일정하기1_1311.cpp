#include <bits/stdc++.h>
#define INF 1e9+7
using namespace std;

int N;
int cost[21][21];
int dp[20][1 << 20];


int Recur(int now, int visited){
    
}

void input(){
    int a, b, c;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        cost[a][b] = c;
    }
    memset(dp, -1, sizeof(dp));
}

int main(){
    input();
    
    return 0;
}
