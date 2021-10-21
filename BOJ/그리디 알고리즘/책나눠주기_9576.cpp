#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int, int>

using namespace std;

bool cmp(pii &a, pii &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int N, M;
vector<pii > bound;

void input(){
    int a, b;
    
    bound.clear();
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        bound.push_back({a, b});
    }
}

void solve(){
    sort(bound.begin(), bound.end(), cmp);
    
    int cnt = 0;
    bool check[1001];
    memset(check, 0, sizeof(check));
    
    for(int i = 0; i < bound.size(); i++){
        for(int j = bound[i].first; j <= bound[i].second; j++){
            if(check[j]) continue;
            cnt++;
            check[j] = true;
            break;
        }
    }
    
    cout << cnt << "\n";
}

int main(){
    fastio
    int T;
    cin >> T;
    while(T--){
        input();
        solve();
    }
    
    return 0;
}
