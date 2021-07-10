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

int N, L;
int arr[5000001];
deque<pii > DQ;

void input(){
    cin >> N >> L;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

void solve(){
    for(int i = 1; i <= N; i++){
        if(!DQ.empty()){
            if(DQ.front().second < i-L+1) DQ.pop_front();
        }
        while(!DQ.empty() && DQ.back().first > arr[i]){
            DQ.pop_back();
        }
        DQ.push_back({arr[i], i});
        cout << DQ.front().first << " ";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
