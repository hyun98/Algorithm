#include <bits/stdc++.h>

using namespace std;

int N, K;
long long feed[100001], DP[100001]; // dp[i] = i까지 먹이를 먹은경우 최대 축적 E

void input(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> feed[i];
    }
}

void solve(){
    long long energy = 0;
    int st = 1, ed = 1;
    long long temp_sum = feed[st];
    
    while(st <= N && ed <= N){
        // DP갱신
        DP[ed] = max(DP[ed], DP[ed-1]);
        
        // 누적 합이 최소 만족도 이상인 경우
        if(temp_sum >= K){
            DP[ed] = max(DP[ed], DP[st-1] + temp_sum - K);
            if(st < ed){
                temp_sum -= feed[st];
                st++;
            }
            else if(st == ed){
                st++;
                ed++;
                temp_sum = feed[ed];
            }
        }
        else{
            ed++;
            temp_sum += feed[ed];
        }
    }
    
    cout << DP[N];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}