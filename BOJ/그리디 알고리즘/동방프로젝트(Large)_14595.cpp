#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int, int>

using namespace std;

int N, M;
vector<pii > events;

void input(){
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        events.push_back({x, y});
    }
}

void solve(){
    sort(events.begin(), events.end());
    
    int ans = 0;
    int x = 0, y = 0;
    
    for(int i = 0; i < M; i++){
        if(events[i].first > y){
            ans += (events[i].first - y);
            x = events[i].first;
            y = max(y, events[i].second);
        }
        else{
            y = max(y, events[i].second);
        }
    }
    ans += (N - y);
    
    cout << ans;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
