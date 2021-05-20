#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K;
vector<string> DP[12];

void solve(){
    DP[1].push_back("1");
    
    for(int i = 2; i <= N; i++){
        for(int flag = 1; flag <= 3; flag++){
            if(i < flag) break;
            
            char add = flag + '0';
            string input = "";
            input += add;
            
            if(i > flag){
                for(auto w : DP[i - flag]){
                    DP[i].push_back(input + "+" + w);
                }
            }
            
            if(i == flag) DP[i].push_back(input);
        }
    }
    
    if(DP[N].size() < K) cout << -1;
    else cout << DP[N][K-1];
}

int main(){
    cin >> N >> K;
    solve();
    
    return 0;
}