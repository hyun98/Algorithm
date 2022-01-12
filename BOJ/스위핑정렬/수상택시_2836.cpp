#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
typedef long long ll;
#define pii pair<ll, ll>

// typedef pair<int, int> pii;

using namespace std;

int N, M;
vector<pii> arr;

void input(){
    cin >> N >> M;
    int s, d;
    for(int i = 0; i < N; i++){
        cin >> s >> d;
        if(s > d) arr.push_back({d, s});
    }
    
    sort(arr.begin(), arr.end());
}

void solve(){
    ll move = M;
    
    int nidx = 0;
    int length = arr.size();
    
    ll left = 0;
    ll right = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].first > right){
            move += (2 * (right - left));
            left = arr[i].first;
            right = arr[i].second;
        }
        else{
            right = max(right, arr[i].second);
        }
    }
    move += (2 * (right - left));
    
    cout << move;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
