#include <iostream>
#include <cstring>

using namespace std;

string first, second, LCS = "";
int dp[1001][1001];

void findLCS(){
    memset(dp, 0, sizeof(dp));
    
    for(int row = 1; row <= first.size(); row++){
        for(int col = 1; col <= second.size(); col++){
            if(first[row-1] == second[col-1]){
                dp[row][col] = dp[row-1][col-1] + 1;
            }
            else dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
        }
    }
    cout << dp[first.size()][second.size()] << "\n";
    
    int f_idx = second.size();
    for(int row = first.size(); row >= 1; row--){
        for(int col = f_idx; col >= 1; col--){
            if(dp[row][col] == dp[row-1][col]){
                f_idx = col;
                break;
            }
            else if(dp[row][col] == dp[row][col-1]) continue;
            else{
                LCS = first[row-1] + LCS;
            }
        }
    }
    cout << LCS;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> first >> second;
    findLCS();
    return 0;
}
