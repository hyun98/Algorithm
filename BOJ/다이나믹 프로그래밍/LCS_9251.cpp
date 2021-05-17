#include <iostream>
#include <string>

using namespace std;

string first, second;
int dp[1001][1001];

void findLCS(){
    int tag = 0, maxlen = 0;
    for(int col = 0; col < first.size(); col++){
        if(first[col] == second[0] && tag == 0){
            tag++;
        }
        dp[0][col] = tag;
    }
    tag = 0;
    for(int row = 0; row < second.size(); row++){
        if(first[0] == second[row] && tag == 0){
            tag++;
        }
        dp[row][0] = tag;
    }
    
    for(int col = 1; col < first.size(); col++){
        for(int row = 1; row < second.size(); row++){
                
            if(first[col] == second[row]){
                dp[row][col] = dp[row-1][col-1] + 1;
            }
            else{
                dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
            }
            
            maxlen = max(maxlen, dp[row][col]);
        }
    }
    cout << maxlen;
}

int main(){
    cin >> first >> second;
    findLCS();
    return 0;
}
