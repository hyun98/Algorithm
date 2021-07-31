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

int N, D, K, C;
int pickedDishes[3001];
int sushi[300001];
int dp[300001];

void input(){
    cin >> N >> D >> K >> C;
    for(int i = 0; i < N; i++){
        cin >> sushi[i];
    }
}


void solve(){
    int num = 0, res = 0;
    for(int i = 0; i < K; i++){
        if(!(pickedDishes[sushi[i]]++)) num++;
    }
    if(!pickedDishes[C]) dp[0] = num+1;
    else dp[0] = num;
    
    res = max(dp[0], res);
    
    for(int i = 1; i < N; i++){
        int sushinum = sushi[(K+i-1)%N];
        if(!(pickedDishes[sushinum]++)) num++;
        if(!(--pickedDishes[sushi[i-1]])) num--;
        
        if(!pickedDishes[C]) dp[i] = num+1;
        else dp[i] = num;
        
        res = max(dp[i], res);
    }
    
    cout << res << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}

