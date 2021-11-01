#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N, L, P;
int info[1000001];

void input(){
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        info[a] = b;
    }
    cin >> L >> P;
    
}

void solve(){
    priority_queue<int> pq;
    int now_fuel = P;
    int ans = 0;
    
    for(int i = 1; i < L; i++){
        now_fuel--;
        if(info[i]) pq.push(info[i]);
        
        if(!now_fuel){
            if(pq.empty()){
                cout << -1;
                return;
            }
            else{
                ans++;
                now_fuel += pq.top();
                pq.pop();
            }
        }
    }
    
    cout << ans;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
