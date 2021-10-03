#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N;
vector<int> height;
vector<int> stk;

void input(){
    cin >> N;
    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        height.push_back(y);
    }
}

void solve(){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int now = height[i];
        while(!stk.empty() && stk.back() > now){
            // 0인 경우 더해주면 안됨
            if(stk.back()) cnt++;
            stk.pop_back();
        }
        if(!stk.empty() && stk.back() == now) continue;
        
        stk.push_back(now);
    }
    // 남은 건물 더해주기
    while(!stk.empty()){
        if(stk.back()) cnt++;
        stk.pop_back();
    }
    cout << cnt;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
