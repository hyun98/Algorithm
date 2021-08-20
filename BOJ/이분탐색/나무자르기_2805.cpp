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
int height[1000001];
int max_height;

void input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> height[i];
        max_height = max(max_height, height[i]);
    }
}

int bin_search(int lo, int hi){
    int mid;
    
    int res = mid;
    ll cutting;
    
    while(lo <= hi){
        mid = (lo + hi) / 2;
        cutting = 0;
        
        for(int i = 0; i < N; i++){
            cutting += ((height[i] - mid) >= 0? height[i] - mid : 0);
        }
        
        if(cutting < M){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
            res = max(res, mid);
        }
    }
    
    return res;
}

void solve(){
    cout << bin_search(0, max_height);
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
