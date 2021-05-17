#include <iostream>
#include <vector>
using namespace std;

// i -> j �� ���� ���
int moveTable[5][5] = { {0, 2, 2, 2, 2},
                        {2, 1, 3, 4, 3},
                        {2, 3, 1, 3, 4},
                        {2, 4, 3, 1, 3},
                        {2, 3, 4, 3, 1} };

vector<int> command;
// left, right, k
// ���� �޹�, �������� ��ġ�� left, right �� �� k��° ������ �� �� �ּ�
int dp[5][5][100001];

int solve(int left, int right, int idx){
    if(idx == command.size()) return 0;
    
    int &ret = dp[left][right][idx];
    if(ret != 0) return ret;
    
    ret = min(moveTable[left][command[idx]] + solve(command[idx], right, idx+1), \
              moveTable[right][command[idx]] + solve(left, command[idx], idx+1));
    return ret;
}

int main(){
    int c;
    cin >> c;
    while(c){
        command.push_back(c);
        cin >>c;
    }
    
    cout << solve(0, 0, 0);
    
    return 0;
}
