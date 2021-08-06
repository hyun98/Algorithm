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
vector<int> chain;

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void solve(){
    int prev = arr[0], cnt = 1;
    for(int i = 1; i < N; i++){
        if(arr[i] == prev){
            chain.push_back(cnt);
            cnt = 1;
        }
        else{
            cnt++;
            prev = arr[i];
        }
    }
    chain.push_back(cnt);
    
    int ans = 0;
    if(chain.size() == 1) ans = chain[0];
    else if(chain.size() == 2) ans = chain[0] + chain[1];
    else{
        for(int i = 0; i < chain.size()-2; i++){
            ans = max(ans, chain[i] + chain[i+1] + chain[i+2]);
        }
    }
    
    cout << ans << "\n";
}

int main(){
    input();
    solve();
    
    return 0;
}
