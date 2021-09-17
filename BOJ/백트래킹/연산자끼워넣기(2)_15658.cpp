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

int N, maxans = -INF, minans = INF;
int op[4];
vector<int> arr;

void input(){
    cin >> N;
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
    }
    arr.push_back(1);
    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }
}

void dfs(int cnt, int sum, int add, int sub, int mul, int div){
    if(cnt == N){
        maxans = max(maxans, sum);
        minans = min(minans, sum);
        return;
    }
    
    if(add) dfs(cnt+1, sum+arr[cnt], add-1, sub, mul, div);
    if(sub) dfs(cnt+1, sum-arr[cnt], add, sub-1, mul, div);
    if(mul) dfs(cnt+1, sum*arr[cnt], add, sub, mul-1, div);
    if(div) dfs(cnt+1, sum/arr[cnt], add, sub, mul, div-1);
}

void solve(){
    dfs(1, arr[0], op[0], op[1], op[2], op[3]);
    cout << maxans << "\n" << minans << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
