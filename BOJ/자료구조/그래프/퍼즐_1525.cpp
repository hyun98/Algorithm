#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7

typedef long long ll;
#define pli pair<ll, int>

using namespace std;


ll start, answer, offset = 15;
ll Checker[9];
set<ll> Check;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void input(){
    ll a;
    for(int i = 0; i < 9; i++){
        cin >> a;
        a = (a << i*4);
        start += a;
    }
    
    for(ll i = 1; i <= 9; i++){
        answer += (i % 9 << (i-1)*4);
    }
    
    for(int i = 0; i < 9; i++){
        Checker[i] = (offset << i*4);
    }
}

int find_zero_loc(ll puzzle){
    ll k;
    for(int i = 0; i < 9; i++){
        k = Checker[i]&puzzle;
        if(k >> i*4 == 0){
            return i;
        }
    }
    return -1;
}

// loc1(zero)과 loc2에 있는 숫자를 swap
ll set_puzzle(ll puzzle, int loc1, int loc2){
    ll num = (Checker[loc2]&puzzle) >> loc2*4;
    
    puzzle &= ~(offset << loc2*4);
    puzzle |= (num << loc1*4);
    
    return puzzle;
}

void show(int state){
    cout << "=========\n";
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            ll k = Checker[3*r+c]&state;
            cout << (k >> 4*(3*r+c)) << " ";
        }
        cout << "\n";
    }
}

void solve(){
    queue<pli > que;
    que.push({start, 0});
    Check.insert(start);
    
    while(!que.empty()){
        pli now = que.front();
        que.pop();
        
        if(now.first == answer){
            cout << now.second << "\n";
            return;
        }
        
        int zero = find_zero_loc(now.first);
        int r = zero / 3;
        int c = zero % 3;
        
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= 3 || nc < 0 || nc >= 3) continue;
            
            ll next = set_puzzle(now.first, zero, nr*3 + nc);
            if(Check.count(next) > 0) continue;
            
            Check.insert(next);
            que.push({next, now.second+1});
        }
    }
    
    cout << -1 << "\n";
}

int main(){
    input();
    solve();
    
    return 0;
}
