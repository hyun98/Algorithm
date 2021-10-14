#include <iostream>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7

using namespace std;

int N;
int def[100001];
int state[100001];
int fstate[100001];

void input(){
    cin >> N;
    string str;
    cin >> str;
    for(int i = 0; i < N; i++){
        state[i] = str[i] - '0';
        def[i] = state[i];
    }
    cin >> str;
    for(int i = 0; i < N; i++){
        fstate[i] = str[i] - '0';
    }
}

void turn_state(int idx){
    state[idx] = (state[idx] == 0)?1:0;
    if(idx == 0) state[idx+1] = (state[idx+1] == 0)?1:0;
    else if(idx == N-1) state[idx-1] = (state[idx-1] == 0)?1:0;
    else{
        state[idx-1] = (state[idx-1] == 0)?1:0;
        state[idx+1] = (state[idx+1] == 0)?1:0;
    }
}

int solve(bool first){
    // i번째 전구는 항상 i+1번째 전구의 스위치로 결정하도록 한다
    
    int cnt = 0;
    if(first){
        turn_state(0);
        cnt = 1;
    }
    for(int i = 1; i < N; i++){
        if(fstate[i-1] != state[i-1]){
            turn_state(i);
            cnt++;
        }
    }
    
    for(int i = 0; i < N; i++){
        if(state[i] != fstate[i]) return INF;
    }
    return cnt;
}

int main(){
    fastio
    input();
    int ans1 = solve(1);
    for(int i = 0; i < N; i++){
        state[i] = def[i]; 
    }
    int ans2 = solve(0);
    
    if(ans1 == INF && ans2 == INF) cout << -1;
    else cout << min(ans1, ans2);
    
    return 0;
}
