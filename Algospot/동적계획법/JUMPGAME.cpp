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
    // 해당 길로 가면 실패한다는 flag를 표시  0
    // 해당 길로 가면 성공한다는 flag를 표시  1
    // default : 해당 길은 아직 가지 않았음 -1
    int find_Path(int r, int c){
        if(r == n-1 && c == n-1) return 1;
        if(r >= n || c >= n) return 0;

        // 끝까지 간 적이 있다면 1을 반환, 갈 수 없으면 0반환
        if(memo[r][c] != -1) return memo[r][c];
        int next = board[r][c];

        // 양 갈래길 모두 범위를 넘어가거나 실패 지점에 도달할 경우 현재 길은 목적지에 도달할 수 없다는 뜻인 0을 반환
        // 양 갈래길 중 하나만이라도 목적지에 도달하거나, 목적지까지 갈 수 있는 길에 도착한다면 현재 길은 목적지에 도달할 수 있다는 뜻인 1을 반환
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
