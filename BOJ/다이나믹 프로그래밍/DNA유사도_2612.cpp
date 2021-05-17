#include <bits/stdc++.h>

using namespace std;

struct Point{
    int r = 0, c = 0;
};

int str1_len, str2_len, max_score = 0, er, ec;
string str1, str2;
int dp[1001][1001];
Point sdp[1001][1001];

void init_DP(){
    for(int r = 1; r <= str1_len; r++){
        for(int c = 1; c <= str2_len; c++){
            int temp = dp[r-1][c-1];
            if(str1[r-1] == str2[c-1]){
                dp[r][c] = 3;
                sdp[r][c] = {r, c};
                temp += 3;
            }
            else{
                dp[r][c] = 0;
                temp -= 2;
            }
            
            if(temp > dp[r][c]){
                dp[r][c] = temp;
                sdp[r][c] = sdp[r-1][c-1];
            }
            if(dp[r][c] < dp[r-1][c] - 2){
                dp[r][c] = dp[r-1][c] - 2;
                sdp[r][c] = sdp[r-1][c];
            }
            if(dp[r][c] < dp[r][c-1] - 2){
                dp[r][c] = dp[r][c-1] - 2;
                sdp[r][c] = sdp[r][c-1];
            }
            
            if(dp[r][c] > max_score){
                max_score = dp[r][c];
                er = r;
                ec = c;
            }
        }
    }
}

void solve(){
    cout << max_score << "\n";
    cout << str1.substr(sdp[er][ec].r-1, er - (sdp[er][ec].r-1)) << "\n";
    cout << str2.substr(sdp[er][ec].c-1, ec - (sdp[er][ec].c-1));
    
}

int main(){
    cin >> str1_len >> str1;
    cin >> str2_len >> str2;
    
    init_DP();
    solve();
    
    return 0;
}
