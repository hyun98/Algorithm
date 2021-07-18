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

int N, x, y, L;
int arr[21];
// int dp[21][21];

// 1번문, 2번문, 벽장 순서 인덱스
int cache[21][21][21];

void input(){
    cin >> N >> x >> y >> L;
    for(int i = 0; i < L; i++){
        cin >> arr[i];
    }
    if(x > y) swap(x, y);
    memset(cache, -1, sizeof(cache));
}

int recur(int a, int b, int tag){
    if(tag == L-1){
        return min(abs(arr[tag]-a), abs(arr[tag]-b));
    }
    
    // cache에 벽장문 순서 인덱스는 왜 필요한 걸까?
    // 벽장문 1,6이 열려있다고 가정.
    // 이때 3번째 순서에서 1, 6이 열려있는 경우와 5번째 순서에서 1,6이 열려있는 경우는 당연히 다를 수 밖에없다.
    // 따라서 현재 몇 번째 벽장문을 열어야 하는지 + 현재 열려있는 벽장문 2개
    // 위 정보로 cache를 구성해야 한다.
    int &ret = cache[a][b][tag];
    if(ret != -1) return ret;
    
    ret = 0;
    
    ret += min(abs(arr[tag] - a) + recur(arr[tag], b, tag+1), \
                abs(b - arr[tag]) + recur(a, arr[tag], tag+1));
    
    
    return ret;
}

void solve(){
    cout << recur(x, y, 0);
}

int main(){
    input();
    solve();
    
    return 0;
}
