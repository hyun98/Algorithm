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

int N, test, t;
int house[1001][256];

void input(){
    memset(house, 0, sizeof(house));
    int H;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> H;
        for(int k = 1; k <= H; k++){
            house[i][k] = 1;
        }
    }
}

void solve(){
    int res = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= 255; j++){
            if(!house[i][j]) break;
            
            if(!house[i-1][j] && !house[i-2][j] && !house[i+1][j] && !house[i+2][j]){
                res += 1;
            }
        }
    }
    
    cout << "#" << t << " " << res << "\n";
}

int main(int argc, char** argv){
    t = 1;
    test = 10;
    while(t <= test){
        input();
        solve();
        t++;
    }
    
    return 0;
}
