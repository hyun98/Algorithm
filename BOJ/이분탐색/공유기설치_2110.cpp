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

int N, C;
int arr[200001];

void input(){
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
}

void solve(){
    int lo = 1;
    int hi = arr[N-1];    
    int result = 0;
    
    while(lo <= hi){
        int cnt = 1;
        int mid = (lo + hi) / 2;
        int st = arr[0];
        
        for(int i = 1; i < N; i++){
            if(arr[i] - st >= mid){
                st = arr[i];
                cnt++;
            }
        }
        
        if(cnt >= C){
            result = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    
    cout << result;
}

int main(){
    fasti
    input();
    solve();
    
    return 0;
}
