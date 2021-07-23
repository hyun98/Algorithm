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

int N, T;
int arr[51];

void input(){
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void solve(){
    int temp = 0, ans = 0;
    for(int i = 0; i < N; i++){
        temp += arr[i];
        if(temp <= T) ans++;
        else break;
    }
    cout << ans;
}

int main(){
    input();
    solve();
    
    return 0;
}
