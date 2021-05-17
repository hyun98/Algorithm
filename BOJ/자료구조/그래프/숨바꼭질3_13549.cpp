#include<iostream>
#include<queue>
 
#define INF 999999999

using namespace std;
 
int N, K;
int mincnt[100001];
 
void solve(){
    queue<int> que;
    que.push(N);
    mincnt[N] = 0;
 
    while (que.empty() == 0){
        int now = que.front();
        que.pop();
 
        if (now == K){
            cout << mincnt[K];
            break;
        }
        
        if (now + 1 < 100001 && mincnt[now + 1] > mincnt[now] + 1){
            mincnt[now + 1] = mincnt[now] + 1;
            que.push(now + 1);
        }
        if (now - 1 >= 0 && mincnt[now - 1] > mincnt[now] + 1){
            mincnt[now - 1] = mincnt[now] + 1;
            que.push(now - 1);
        }
        if (now * 2 < 100001 && mincnt[now * 2] > mincnt[now]){
            mincnt[now * 2] = mincnt[now];
            que.push(now * 2);
        }
    }
}
 
int main(void){
    cin >> N >> K;
    for(int i = 0; i < 100001; i++){
        mincnt[i] = 1e9+7;
    }
    solve();
 
    return 0;
}