#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N;
ll arr[6];

void input(){
    cin >> N;
    for(int i = 0; i < 6; i++){
        cin >> arr[i];
    }
}

ll make_ans(ll min1, ll min2, ll min3){
    ll ret = 0;
    
    ll a3 = min3 * 4;
    ll a2 = min2 * ((N-2) * 4 + (N-1) * 4);
    ll a1 = min1 * ((N-2) * 4 + pow((N-2), 2) * 5);
    
    ret = a1 + a2 + a3;
    
    return ret;
}

void solve(){
    ll min1 = INF;
    for(int i = 0; i < 6; i++){
        min1 = min(min1, arr[i]);
    }
    
    ll min2 = INF;
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 6; j++){
            if((i + j) % 6 == 5) continue;
            min2 = min(min2, arr[i] + arr[j]);
        }
    }
    
    ll min3 = INF;
    min3 = min(min3, arr[0] + arr[1] + arr[2]);
    min3 = min(min3, arr[0] + arr[2] + arr[4]);
    min3 = min(min3, arr[0] + arr[4] + arr[3]);
    min3 = min(min3, arr[0] + arr[1] + arr[3]);
    min3 = min(min3, arr[5] + arr[1] + arr[2]);
    min3 = min(min3, arr[5] + arr[2] + arr[4]);
    min3 = min(min3, arr[5] + arr[4] + arr[3]);
    min3 = min(min3, arr[5] + arr[1] + arr[3]);
    
    cout << make_ans(min1, min2, min3);
}

int main(){
    input();
    if(N == 1){
        sort(arr, arr+6);
        ll ans = 0;
        for(int i = 0; i < 5; i++){
            ans += arr[i];
        }
        cout << ans;
    }
    else solve();
    
    return 0;
}
