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

int ans;
// {능력, 포지션}
vector<pii > player[11];
bool visited[11];

void input(){
    for(int i = 0; i < 11; i++){
        player[i].clear();
        visited[i] = false;
    }
    ans = 0;
    
    int a;
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            cin >> a;
            if(!a) continue;
            player[i].push_back({a, j});
        }
    }
}

void dfs(int cnt, int sum){
    if(cnt == 11){
        ans = max(ans, sum);
        
        return;
    }
    
    for(int i = 0; i < player[cnt].size(); i++){
        int score = player[cnt][i].first;
        int position = player[cnt][i].second;
        
        if(visited[position]) continue;
        
        visited[position] = true;
        
        dfs(cnt+1, sum + score);
        
        visited[position] = false;
        
    }
}

void solve(){
    dfs(0, 0);
    
    cout << ans << "\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        input();
        solve();
    }
    
    return 0;
}
