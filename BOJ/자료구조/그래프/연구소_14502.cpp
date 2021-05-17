#include <iostream>
#include <queue>

using namespace std;

int M, N, result = 0;
int dx[4] = {0, 1, 0, -1}; //up, right, down, left
int dy[4] = {-1, 0, 1, 0};

struct P{
    int y, x;
};

class LAB{
    int lab[8][8];

public:
    int safezone = 0;
    LAB(int tlab[][8]){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                lab[i][j] = tlab[i][j];
            }
        }
    }

    void find_safezone(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(lab[i][j] == 0) safezone++;
            }
        }
    }

    void BFS(){
        queue<P> que;
        bool visit[8][8] = {false, };

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(lab[i][j] == 2){
                    que.push({i, j});
                }
            }
        }
        while(!que.empty()){
            P next = que.front();
            que.pop();
            visit[next.y][next.x] = true;
            for(int k = 0; k < 4; k++){
                int nx = next.x + dx[k];
                int ny = next.y + dy[k];
                if(nx >= 0 && nx < M && ny >= 0 && ny < N && !visit[ny][nx]){
                    if(lab[ny][nx] == 0){
                        lab[ny][nx] = 2;
                        que.push({ny, nx});
                        visit[ny][nx] = true;
                    }
                }
            }
        }
        find_safezone();
    }
};

void wall(int deep, int lab[][8]){

    if(deep == 3){
        LAB testlab(lab);
        testlab.BFS();
        result = max(result, testlab.safezone);
        return;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(lab[i][j] == 0){
                lab[i][j] = 1;
                deep += 1;
                wall(deep, lab);
                deep -= 1;
                lab[i][j] = 0;
            }
        }
    }
}

void solve(){
    cin >> N >> M;
    int lab[8][8], deep;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> lab[i][j];
        }
    }

    wall(0, lab);
}

int main(){
    solve();
    cout << result;

    return 0;
}
