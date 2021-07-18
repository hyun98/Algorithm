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

int N, M, C;
int dp[51][51][51][51];
int Map[51][51];

int test[51][51];

void input(){
    cin >> N >> M >> C;
    int r, c;
    for(int i = 1; i <= C; i++){
        cin >> r >> c;
        Map[r][c] = i;
    }
    memset(dp, -1, sizeof(dp));
}

// gnum : 지금까지 지나온 오락실의 수, prev : 지나온 오락실의 마지막 번호
int path_num(int r, int c, int gnum, int prev){
    if(r > N || c > M) return 0;
    cout << "r, c, gnum, prev : " << r << " " << c << " " << gnum << " " << prev << "\n";
    if(r == N && c == M) return 1;
    
    
    int &ret = dp[r][c][gnum][prev];
    if(ret != -1) return ret;
    
    ret = 0;
    
    if(Map[r+1][c] == 0){
        ret += path_num(r+1, c, gnum, prev);
    }
    if(Map[r][c+1] == 0){
        ret += path_num(r, c+1, gnum, prev);
    }
    if(Map[r+1][c] > prev){
        ret += path_num(r+1, c, gnum+1, Map[r+1][c]);
    }
    if(Map[r][c+1] > prev){
        ret += path_num(r, c+1, gnum+1, Map[r][c+1]);
    }
    cout << "ret : " << r << " " << c << " " << gnum << " " << prev << " : " << ret << "\n";
    
    return ret;
}

void solve(){
    cout << path_num(1, 1, 0, 0);
}

int main(){
    input();
    solve();
    
    return 0;
}
