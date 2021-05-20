#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct P{
    int src, dest;
};

int N, dp[101];
vector<P> elec;

bool cmp(P a, P b){
    return a.src < b.src;
}

void input(){
    int a, b;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        elec.push_back({a, b});
    }
    memset(dp, 0, sizeof(dp));
    //전깃줄을 왼쪽 시작점을 기준으로 정렬
    sort(elec.begin(), elec.end(), cmp);
}

// @ top - down
int noncross_cnt(int now){
    
    int &ret = dp[now];
    if(ret != 0) return ret;
    
    ret = 1;
    int mcnt = 0;
    for(int i = now; i < N; i++){
        if(elec[now].dest < elec[i].dest){
            cout << " now dest " << elec[now].dest << " next dest :" << elec[i].dest << " \n ";
            mcnt = max(noncross_cnt(i), mcnt);
        }
    }    
    return ret += mcnt;
}

void solve(){
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, noncross_cnt(i));
    }
    cout << N - ans;
}

int main(){
    input();
    solve();
    
    return 0;
}
