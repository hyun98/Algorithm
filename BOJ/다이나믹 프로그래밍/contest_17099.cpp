#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P{
    int st, ed, reward;
};

int N;
vector<P> ctest;
int dp[300001];

bool cmp(P &a, P &b){
    if(a.st == b.st) return a.ed <= b.ed;
    else return a.st < b.st;
}

void input(){
    cin >> N;
    int s, e, r;
    for(int i = 0; i < N; i++){
        cin >> s >> e >> r;
        ctest.push_back({s, e, r});
    }
    sort(ctest.begin(), ctest.end(), cmp);
}

void solve(){
    dp[N-1] = ctest[N-1].reward;
    int bst = ctest[N-1].st;
    int ned;
    
    for(int i = N-2; i >= 0; i--){
        dp[i] = ctest[i].reward;
        ned = ctest[i].ed;
        //겹치는 경우
        if(bst <= ned){
            if(dp[i] > dp[i+1]){
                bst = ctest[i].st;
            }
            dp[i] = max(dp[i], dp[i+1]);
        }
        else{
            bst = ctest[i].st;
            dp[i] = max(dp[i], dp[i+1]+dp[i]);
        }
    }
    cout << dp[0];
}

int main(){
    input();
    solve();
    
    return 0;
}