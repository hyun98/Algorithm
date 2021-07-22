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
vector<int> book[2];

void input(){
    cin >> N >> M;
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(a > 0) book[0].push_back(a);
        else book[1].push_back(a);
    }
}

int bring(int select, int t){
    int ret = 0;
    for(int i = 0; i < book[select].size(); i+=M){
        ret += abs(book[select][i]*2);
    }
    if(t == 1){
        ret -= abs(book[select][0]);
    }
    return ret;
}

void solve(){
    sort(book[0].begin(), book[0].end(), greater<int>());
    sort(book[1].begin(), book[1].end());
    
    int p = 0, n = 0, ans = 0;
    if(!book[0].empty()) p = book[0][0];
    if(!book[1].empty()) n = book[1][0];
    
    if(p > abs(n)){
        ans += bring(1, 0);
        ans += bring(0, 1);
    }
    else{
        ans += bring(0, 0);
        ans += bring(1, 1);
    }
    
    cout << ans;
}

int main(){
    fasti
    input();
    solve();
    
    return 0;
}
