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

int H, W;
int Map[501];
int ans;

void input(){
    cin >> H >> W;
    for(int i = 1; i <= W; i++){
        cin >> Map[i];
    }
}

void solve(){
    bool leftBlock = false;
    
    for(int h = 1; h <= H; h++){
        int water = 0;
        for(int w = 1; w <= W; w++){
            if(Map[w] >= h){
                leftBlock = true;
                ans += water;
                water = 0;
            }
            if(Map[w] < h && leftBlock){
                water++;
            }
        }
        leftBlock = false;
    }
    
    cout << ans << '\n';
}

int main(){
    input();
    solve();
    
    return 0;
}
