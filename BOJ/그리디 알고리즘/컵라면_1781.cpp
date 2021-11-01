#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int N;
// first : 데드라인
// second : 컵라면 수
vector<pii > arr;
bool check[200001];

void input(){
    cin >> N;
    int d, c;
    for(int i = 0; i < N; i++){
        cin >> d >> c;
        arr.push_back({d, c});
    }
}

// 데드라인 오름차순, 컵라면 수 내림차순
bool cmp(pii &a, pii &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void solve(){
    sort(arr.begin(), arr.end(), cmp);
    
    priority_queue<int> pq;
    
    int ans = 0;
    int arridx = N-1;
    
    for(int dead = N; dead >= 1; dead--){
        while(arridx >= 0 && arr[arridx].first >= dead){
            pq.push(arr[arridx--].second);
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    
    cout << ans << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
