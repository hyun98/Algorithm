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

using namespace std;

int N, K;
int st = INF;
int ed;
int arr[1000001];
int pSum[1000002];

void input(){
    cin >> N >> K;
    
    int s, e;
    for(int i = 0; i < N; i++){
        cin >> s >> e;
        /**
         * @brief 누적합 구하는 기술
         * 시작점을 1, 끝점을 -1로 잡아서 arr에 합산한다.
         */
        arr[s] += 1;
        arr[e] -= 1;
        ed = max(ed, e);
        st = min(st, s);
    }
    
    /**
     * @brief 누적합 구하는 기술
     * st 값을 지정해 놓고 1, -1 들이 합산된 arr에 대한 누적합을 구한다.
     * 시작점과 끝점을 가진 선분이 겹쳐있는 경우, 각 구간에 대해 몇 겹인지 알 수 있다.
     */
    pSum[st] = arr[st];
    for(int i = st; i < ed; i++){
        pSum[i+1] = pSum[i] + arr[i+1];
    }
}

void solve(){
    int l = 0;
    int r = 0;
    
    int inner = 0;
    
    while(r <= ed && l <= r){
        
        if(inner == K){
            cout << l << " " << r << '\n';
            return;
        }
        
        if(inner < K){
            inner += pSum[r++];
        }
        else if(inner > K){
            inner -= pSum[l++];
        }
    }
    cout << 0 << " " << 0;
}

int main(){
    input();
    solve();
    
    return 0;
}
