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

int N;
int arr[100001];
vector<int> res;

void input(){
    cin >> N;
    int a;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void solve(){
    res.push_back(arr[0]);
    int cnt = 1;
    
    for(int i = 1; i < N; i++){
        if(res.back() < arr[i]){
            res.push_back(arr[i]);
            cnt++;
        }
        else{
            int idx = upper_bound(res.begin(), res.end(), arr[i]) - res.begin();
            res[idx] = arr[i];
        }
    }
    cout << N - cnt;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
