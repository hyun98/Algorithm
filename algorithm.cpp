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
vector<int> state;

void input(){
    cin >> N;
    string str;
    for(int i = 0; i < N; i++){
        state.push_back(str[i] - 'a');
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

void solve(){
    
}

int main(){
    input();
    solve();
    
    return 0;
}
