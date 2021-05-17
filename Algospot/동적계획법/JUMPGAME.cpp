#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Board{
    int n;
    int board[100][100];
    int memo[100][100];
public:
    Board(){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
                memo[i][j] = -1;
            }
        }
    }
    // �ش� ��� ���� �����Ѵٴ� flag�� ǥ��  0
    // �ش� ��� ���� �����Ѵٴ� flag�� ǥ��  1
    // default : �ش� ���� ���� ���� �ʾ��� -1
    int find_Path(int r, int c){
        if(r == n-1 && c == n-1) return 1;
        if(r >= n || c >= n) return 0;

        // ������ �� ���� �ִٸ� 1�� ��ȯ, �� �� ������ 0��ȯ
        if(memo[r][c] != -1) return memo[r][c];
        int next = board[r][c];

        // �� ������ ��� ������ �Ѿ�ų� ���� ������ ������ ��� ���� ���� �������� ������ �� ���ٴ� ���� 0�� ��ȯ
        // �� ������ �� �ϳ����̶� �������� �����ϰų�, ���������� �� �� �ִ� �濡 �����Ѵٸ� ���� ���� �������� ������ �� �ִٴ� ���� 1�� ��ȯ
        return memo[r][c] = (find_Path(r+next, c) || find_Path(r, c+next));
    }
};

void start(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        Board b1;

        if(b1.find_Path(0, 0) == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    start();

    return 0;
}
