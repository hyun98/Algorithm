#include <iostream>
#include <queue>
using namespace std;

struct P{
    int r, c;
};

int N, M, Maze[101][101], depth[101][101];
bool check[101][101];

void range(int r, int c, int row, int col, queue<P> &que){
    if(Maze[r][c] == 0) return;
    if(check[r][c]) return;
    if(r < 1 || r > N) return;
    else if(c < 1 || c > M) return;
    else{
        P temp; temp.r = r; temp.c = c;
        depth[r][c] = depth[row][col] + 1;
        check[r][c] = true;
        que.push(temp);
    }
}

void bfs(){
    queue<P> que;
    P temp; temp.r = 1; temp.c = 1;
    que.push(temp);
    depth[1][1] = 1;

    while(que.size() > 0){
        P now = que.front();
        que.pop();
        range(now.r+1, now.c, now.r, now.c, que);
        range(now.r, now.c+1, now.r, now.c, que);
        range(now.r-1, now.c, now.r, now.c, que);
        range(now.r, now.c-1, now.r, now.c, que);
    }

}

void input(){
    string inp;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> inp;
        for(int j = 0; j < inp.length(); j++){
            Maze[i][j+1] = inp[j]-'0';
            check[i][j+1] = false;
        }
    }
}

int main(){
    input();
    bfs();
    cout << depth[N][M];
    return 0;
}
