#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str1, str2;
int dp[4005][4005];

void find_LCS(){
    int result = 0;
    
    for(int row = 1; row <= str1.size(); row++){
        for(int col = 1; col <= str2.size(); col++){
            if(str1[row-1] == str2[col-1]){
                dp[row][col] = dp[row-1][col-1]+1;
            }
            result = max(result, dp[row][col]);
        }
    }
//    for(int i = 0; i <= str1.size(); i++){
//        for(int j = 0; j <= str2.size(); j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << result;
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> str1 >> str2;
    memset(dp, 0, sizeof(dp));
    find_LCS();
    
    return 0;
}
