#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Board{
    int map[21][21];
};

int N, max_value = 0;
Board start;
stack<Board> bstack;

void init(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> start.map[i][j];
        }
    }
    bstack.push(start);
}

void move_top(Board& nowboard){
    queue<int> que;
    for(int c = 0; c < N; c++){
        for(int r = 0; r < N; r++){
            if(nowboard.map[r][c]){
                que.push(nowboard.map[r][c]);
                
            }
            nowboard.map[r][c] = 0;
        }
        
        int ridx = 0;
        
        while(!que.empty()){
            int now = que.front();
            que.pop();
            
            if(nowboard.map[ridx][c] == 0){
                nowboard.map[ridx][c] = now;
            }
            else if(nowboard.map[ridx][c] == now){
                nowboard.map[ridx][c] *= 2;
                ridx++;
            }
            else{
                ridx++;
                nowboard.map[ridx][c] = now;
            }
        }
    }
}
void move_down(Board& nowboard){
    for(int c = 0; c < N; c++){
        queue<int> que;
        for(int r = N-1; r >= 0; r--){
            if(nowboard.map[r][c]){
                que.push(nowboard.map[r][c]);
            }
            nowboard.map[r][c] = 0;
        }
        
        int ridx = N-1;
        
        while(!que.empty()){
            int now = que.front();
            que.pop();
            
            if(nowboard.map[ridx][c] == 0){
                nowboard.map[ridx][c] = now;
            }
            else if(nowboard.map[ridx][c] == now){
                nowboard.map[ridx][c] *= 2;
                ridx--;
            }
            else{
                ridx--;
                nowboard.map[ridx][c] = now;
            }
        }
    }
}
void move_left(Board& nowboard){
    for(int r = 0; r < N; r++){
        queue<int> que;
        for(int c = 0; c < N; c++){
            if(nowboard.map[r][c]){
                que.push(nowboard.map[r][c]);
            }
            nowboard.map[r][c] = 0;
        }
        
        int cidx = 0;
        
        while(!que.empty()){
            int now = que.front();
            que.pop();
            
            if(nowboard.map[r][cidx] == 0){
                nowboard.map[r][cidx] = now;
            }
            else if(nowboard.map[r][cidx] == now){
                nowboard.map[r][cidx] *= 2;
                cidx++;
            }
            else{
                cidx++;
                nowboard.map[r][cidx] = now;
            }
        }
    }
}
void move_right(Board& nowboard){
    for(int r = 0; r < N; r++){
        queue<int> que;
        for(int c = N-1; c >= 0; c--){
            if(nowboard.map[r][c]){
                que.push(nowboard.map[r][c]);
            }
            nowboard.map[r][c] = 0;
        }
        
        int cidx = N-1;
        
        while(!que.empty()){
            int now = que.front();
            que.pop();
            
            if(nowboard.map[r][cidx] == 0){
                nowboard.map[r][cidx] = now;
            }
            else if(nowboard.map[r][cidx] == now){
                nowboard.map[r][cidx] *= 2;
                cidx--;
            }
            else{
                cidx--;
                nowboard.map[r][cidx] = now;
            }
        }
    }
}
void Board_move(int dir, Board& nowboard){
    switch (dir)
    {
    case 0: move_top(nowboard); break;
    case 1: move_down(nowboard); break;
    case 2: move_left(nowboard); break;
    case 3: move_right(nowboard); break;
    
    default: break;
    }
}

void find_maxvalue(Board& nowboard){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            max_value = max(max_value, nowboard.map[r][c]);
        }
    }
}

void DFS(int move){
    Board nowboard;
    
    if(move == 5){
        find_maxvalue(bstack.top());
        return;
    }

    // 상하좌우로 움직이는 경우
    for(int i = 0; i < 4; i++){
        nowboard = bstack.top();
        Board_move(i, nowboard);
        bstack.push(nowboard);
        DFS(move+1);
        bstack.pop();
    }
}

int main(){
    init();
    DFS(0);
    cout << max_value;
    return 0;
}