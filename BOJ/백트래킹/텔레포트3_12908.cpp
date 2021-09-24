#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e15+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int xs, ys, xe, ye;
ll ans = INF;
vector<pii > telpo;
bool visited[7];

void input(){
    cin >> xs >> ys >> xe >> ye;
    int x, y;
    for(int i = 0; i < 6; i++){
        cin >> x >> y;
        telpo.push_back({x, y});
    }
}

void dfs(int x, int y, ll time){
    if(x == xe && y == ye){
        ans = min(ans, time);
        return;
    }
    
    // 텔포로 갈 때
    for(int i = 0; i < 6; i++){
        if(visited[i]) continue;
        visited[i] = true;
        ll temp_time = abs(telpo[i].first - x) + abs(telpo[i].second - y);
        if(i % 2){
            visited[i-1] = true;
            dfs(telpo[i-1].first, telpo[i-1].second, time + 10 + temp_time);
            visited[i-1] = false;
        }
        else{
            visited[i+1] = true;
            dfs(telpo[i+1].first, telpo[i+1].second, time + 10 + temp_time);
            visited[i+1] = false;
        }
        visited[i] = false;
    }
    
    // 목적지로 걸어갈 때
    dfs(xe, ye, time + abs(xe - x) + abs(ye - y));
}

void solve(){
    dfs(xs, ys, 0);
    
    cout << ans;
}

int main(){
    input();
    solve();
    
    return 0;
}
