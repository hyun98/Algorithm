#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e13+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, H;
int top[500001];
int bottom[500001];

void input(){
    cin >> N >> H;
    int h;
    for(int i = 0; i < N; i++){
        cin >> h;
        // 석순
        if(i % 2 == 0) bottom[h]++;
        // 종유석
        else top[H - h + 1]++;
    }
}

void solve(){
    for(int i = 1; i <= H; i++){
        top[i] += top[i-1];
        bottom[H-i] += bottom[H-i+1];
    }
    
    ll ans = INF;
    int cnt = 0;
    for(int i = 1; i <= H; i++){
        if(top[i] + bottom[i] < ans){
            cnt = 1;
            ans = top[i] + bottom[i];
        }
        else if(top[i] + bottom[i] == ans){
            cnt++;
        }
    }
    
    cout << ans << " " << cnt;
}

int main(){
    input();
    solve();
    
    return 0;
}
