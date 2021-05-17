#include <iostream>
#include <cstring>

using namespace std;

string first, second, LCS = "";
int dp[1001][1001];

void findLCS(){
    // dp �迭�� ��� 0���� �ʱ�ȭ
    memset(dp, 0, sizeof(dp));
    
    // LCSǥ�� ���ϴ� ����
    for(int row = 1; row <= first.size(); row++){
        for(int col = 1; col <= second.size(); col++){
            if(first[row-1] == second[col-1]){
                // ���� ���� ���ڰ� ������ �� ���ڿ����� 
                // �ش� �� ���ڸ� ���ϱ� ���� LCS�� ���̿� 1�� ���Ѵ�
                dp[row][col] = dp[row-1][col-1] + 1;
            }
            // ���ڰ� �ٸ��ٸ� first[row-1]������ ���ڿ� + second[col] ������ ���ڿ� ���� LCS����
            // first[row]������ ���ڿ� + second[col+1] ������ ���ڿ� ���� LCS�� �� ū���� ����
            else dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
        }
    }
    cout << dp[first.size()][second.size()] << "\n";
    
    int f_idx = second.size();
    for(int row = first.size(); row >= 1; row--){
        for(int col = f_idx; col >= 1; col--){
            if(dp[row][col] == dp[row-1][col]){
                // �ٷ� �� dp���� ������ ���� �� ���� �����Ѵ�
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
