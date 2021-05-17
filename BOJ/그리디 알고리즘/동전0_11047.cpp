#include <iostream>
#include <queue>
using namespace std;

int N, K, c, cnt = 0, temp;
priority_queue<int> coin;

void solve(){
    while(K){
        if(coin.top() <= K){
            cnt += (K / coin.top());
            K = K % coin.top();
            coin.pop();
        }
        else{
            coin.pop();
        }
    }
}

void input(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> c;
        coin.push(c);
    }
}

int main(){
    input();
    solve();
    cout << cnt;

    return 0;
}
