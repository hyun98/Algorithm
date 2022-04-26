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

int N, K;
int nums[100001];
int sums[100010];

void input(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> nums[i];
    }
}

void solve(){
    int answer = -INF;
    
    for(int i = 1; i <= N; i++){
        sums[i] += (nums[i] + sums[i-1]);
        int temp = sums[i];
        if(i >= K){
            temp -= sums[i-K];
            answer = max(answer, temp);
        }
    }
    
    cout << answer;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
