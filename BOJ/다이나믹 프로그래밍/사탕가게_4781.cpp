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
double m;
int dp[10001];
vector<pii > candy;

void input(){
    candy.clear();
    int c, p;
    double P;
    cin >> N >> m;
    M = (int)(m*100 + 0.5);
    if(N == 0 && M == 0) exit(0);
    for(int i = 0; i < N; i++){
        cin >> c >> P;
        p = (int)(P*100 + 0.5);
        candy.push_back({p, c});
    }
    
    memset(dp, -1, sizeof(dp));
}

int ReCur(int money){
    if(money > M) return 0;
    
    int &ret = dp[money];
    if(ret != -1) return ret;
    
    ret = 0;
    
    for(int i = 0; i < candy.size(); i++){
        pii next = candy[i];
        if(money + next.first > M) continue;
        ret = max(ret, next.second + ReCur(money+next.first));
    }
    
    return ret;
}

void solve(){
    sort(candy.begin(), candy.end());
    cout << ReCur(0) << "\n";
}

int main(){
    while(true){
        input();
        solve();
    }
    return 0;
}
