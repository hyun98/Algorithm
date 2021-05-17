#include <iostream>
#include <cstring>

using namespace std;

string first, second, LCS = "";
int dp[1001][1001];

void findLCS(){
    // dp 배열을 모두 0으로 초기화
    memset(dp, 0, sizeof(dp));
    
    // LCS표를 구하는 과정
    for(int row = 1; row <= first.size(); row++){
        for(int col = 1; col <= second.size(); col++){
            if(first[row-1] == second[col-1]){
                // 만약 같은 문자가 나오면 두 문자열에서 
                // 해당 두 문자를 비교하기 전의 LCS의 길이에 1을 더한다
                dp[row][col] = dp[row-1][col-1] + 1;
            }
            // 문자가 다르다면 first[row-1]까지의 문자열 + second[col] 까지의 문자열 간의 LCS값과
            // first[row]까지의 문자열 + second[col+1] 까지의 문자열 간의 LCS값 중 큰값을 저장
            else dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
        }
    }
    cout << dp[first.size()][second.size()] << "\n";
    
    int f_idx = second.size();
    for(int row = first.size(); row >= 1; row--){
        for(int col = f_idx; col >= 1; col--){
            if(dp[row][col] == dp[row-1][col]){
                // 바로 위 dp값이 같으면 현재 열 값을 유지한다
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
