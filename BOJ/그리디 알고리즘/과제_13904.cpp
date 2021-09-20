#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int, int>

using namespace std;

int N;
pii assign[1001];
int check[1001];

void input(){
    int d, w;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> d >> w;
        assign[i] = {w, d};
    }
}

void solve(){
    sort(assign, assign + N, greater<pii >());
    
    int ans = 0;
    
    for(int i = 0; i < N; i++){
        int due = assign[i].second;
        int score = assign[i].first;
        
        for(int d = due; d >= 1;d--){
            if(check[d]) continue;
            check[d] = score;
            ans += score;
            break;
        }
    }
    
    cout << ans << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
