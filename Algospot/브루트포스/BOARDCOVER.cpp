#include <iostream>
#include <vector>

using namespace std;

// y, x 순서
int blockType[4][3][2] = { { {0, 0}, {0, 1}, {1, 0} },
                         { {0, 0}, {0, 1}, {1, 1} },
                         { {0, 0}, {1, 0}, {1, -1} },
                         { {0, 0}, {1, 0}, {1, 1} } };

class Board{
    int h, w, whitenum = 0, ans = 0;
    vector< vector<int> > board;

public:
    Board(int h, int w) : h(h), w(w){
        board.resize(h, vector<int>(w, 0));
    }

    void BoardMake(){
        char color;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> color;
                if(color == '#') board[i][j] = 1;
                else{
                    board[i][j] = 0;
                    whitenum++;
                }
            }
        }
    }

    bool Set(int y, int x, int type, int delta){
        bool ok = true;
        for(int i = 0; i < 3; i++){
            const int ny = y + blockType[type][i][0];
            const int nx = x + blockType[type][i][1];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w){
                ok = false;
            }
            else if((board[ny][nx] += delta) > 1){  //검사와 동시에 해당 좌표에 블럭을 놓는다
                ok = false;
            }
        }
        return ok;
    }

    void fillBoardstart(){
        if(whitenum % 3 != 0) return;

        int startx = -1, starty = -1;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == 0){
                    starty = i;
                    startx = j;
                    break;
                }
            }
            if(startx != -1) break;
        }

        if(startx == -1){
            ans++;
            return;
        }

        for(int i = 0; i < 4; i++){
            if(Set(starty, startx, i, 1)){
                fillBoardstart();
            }
            Set(starty, startx, i, -1);
        }
        return;
    }

    void printans(){
        cout << ans << "\n";
    }

};

int main(){
    int testcase, H, W;
    cin >> testcase;
    while(testcase--){
        cin >> H >> W;
        Board B(H, W);
        B.BoardMake();
        B.fillBoardstart();
        B.printans();
    }
    return 0;
}
