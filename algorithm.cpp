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

int N;
int dp[1001][1001];
vector<int> coke;

void input(){
    cin >> N;
    int c;
    for(int i = 0; i < N; i++){
        cin >> c;
        coke.push_back(c);
    }
    
    memset(dp, -1, sizeof(dp));
}

int solve(int st, int ed){
    if(st >= ed) return 0;
    
    int &ret = dp[st][ed];
    if(ret != -1) return ret;
    
    ret = 0;
    
    for(int i = st; i <= ed; i++){
        int cnt = 0;
        if(coke[st] == coke[i] && st != i){
            cnt = (solve(st+1, i-1) + solve(i+1, ed) + 1);
            ret = max(ret, cnt);
        }
        if(coke[i] == coke[ed] && i != ed){
            cnt = (solve(st, i-1) + solve(i+1, ed-1) + 1);
            ret = max(ret, cnt);
        }
        else{
            cnt = (solve(st, i) + solve(i, ed));
            ret = max(ret, cnt);
        }
    }
    
    return ret;
}

int main(){
    input();
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            solve(i, j);
            // cout << "dp["<<i<<"]["<<j<<"] : "<< dp[i][j] << "\n";
        }
    }
    
    cout << dp[0][N-1] << "\n";
    
    return 0;
}
