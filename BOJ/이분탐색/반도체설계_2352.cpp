#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N;
int arr[40001];
vector<int> res;

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

void solve(){
    res.push_back(arr[1]);
    int cnt = 1;
    
    for(int i = 2; i <= N; i++){
        if(res.back() < arr[i]){
            res.push_back(arr[i]);
            cnt++;
        }
        else{
            int idx = (lower_bound(res.begin(), res.end(), arr[i]) - res.begin());
            res[idx] = arr[i];
        }
    }
    
    cout << cnt << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
