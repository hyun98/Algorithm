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

int N, C, W;
int wood[51];
int Cache[10001];
long long maxmoney;

void input(){
    cin >> N >> C >> W;
    for(int i = 0; i < N; i++){
        cin >> wood[i];
        maxmoney += wood[i]*W;
    }
}

void solve(){
    long long ans = 0, tans;
    int cut, money, ttans;
    for(int i = 1; i <= 10000; i++){
        tans = 0;
        for(int k = 0; k < N; k++){
            money = wood[k] / i;
            cut = (wood[k] - 0.5) / i;
            ttans = i * money * W - cut * C;
            if(ttans > 0){
                tans += ttans;
            }
        }
        ans = max(tans, ans);
    }
    
    cout << ans;
}

int main(){
    input();
    solve();
    
    return 0;
}

