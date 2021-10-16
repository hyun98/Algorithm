#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

using namespace std;

int N;
priority_queue<pii > info;
bool check[10001];

void input(){
    cin >> N;
    int p, d;
    for(int i = 0; i < N; i++){
        cin >> p >> d;
        info.push({p, d});
    }
}

void solve(){
    int earn = 0;
    
    while(!info.empty()){
        int money = info.top().first;
        int nowd = info.top().second;
        
        while(nowd){
            if(!check[nowd]){
                earn += money;
                check[nowd] = true;
                break;
            }
            nowd--;
        }
        info.pop();
    }
    
    cout << earn;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
