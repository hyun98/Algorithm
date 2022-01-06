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
vector<pii > node;
int dp[105][105];

void input(){
    cin >> N;
    pii temp;
    cin >> temp.first >> temp.second;
    node.push_back(temp);
    for(int i = 0; i < N; i++){
        cin >> temp.first >> temp.second;
        node.push_back(temp);
    }
    cin >> temp.first >> temp.second;
    node.push_back(temp);
}

int dist(pii &a, pii &b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(){
    for(int i = 0; i < node.size()-1; i++){
        for(int j = i+1; j < node.size(); j++){
            dp[i][j] = dp[j][i] = ((dist(node[i], node[j]) <= 1000)? 1 : 0);
        }
    }
    
    for(int i = 0; i < N+2; i++){
        for(int r = 0; r < N+2; r++){
            for(int c = 0; c < N+2; c++){
                if(dp[r][i] && dp[i][c]) dp[r][c] = 1;
            }
        }
    }
    string res = dp[0][N+1] == 1? "happy\n" : "sad\n";
    cout << res;
}

int main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        node.clear();
        input();
        solve();
    }
    
    return 0;
}
