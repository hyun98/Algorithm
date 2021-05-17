#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
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
            max_value = max(max_value, start.map[i][j]);
        }
    }
    bstack.push(start);
}

inline int move_top(Board& nowboard){
    int tempr = 0;
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
            tempr = max(tempr, nowboard.map[ridx][c]);
        }
        
    }
    return tempr;
}
inline int move_down(Board& nowboard){
    int tempr = 0;
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
            tempr = max(tempr, nowboard.map[ridx][c]);
        }
        
    }
    return tempr;
}
inline int move_left(Board& nowboard){
    int tempr = 0;
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
            tempr = max(tempr, nowboard.map[r][cidx]);
        }
        
    }
    return tempr;
}
inline int move_right(Board& nowboard){
    int tempr = 0;
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
            tempr = max(tempr, nowboard.map[r][cidx]);
        }
    }
    return tempr;
}
inline int Board_move(int dir, Board& nowboard){
    switch (dir)
    {
    case 0: return move_top(nowboard);
    case 1: return move_down(nowboard);
    case 2: return move_left(nowboard);
    case 3: return move_right(nowboard);
    
    default: break;
    }
    return 0;
}

inline int find_maxvalue(Board& nowboard){
    int maxv = 0;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            maxv = max(maxv, nowboard.map[r][c]);
        }
    }
    return maxv;
}

inline bool checkboard(Board& bef, Board& now){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(bef.map[i][j] != now.map[i][j]) return false;
        }
    }
    return true;
}
bool can_beMax(int now_max, int move){
    /* 현재 움직인 횟수와 최대값을 통해서, 최고의 상황에서의 기댓값을 계산. */
    int left_move = 10 - move;
    int Expect_Max = now_max * pow(2, left_move);
    
    if (max_value >= Expect_Max) return false;
    return true;
}

int maxdp[11] = {0, };

void DFS(int move, int tmv){
    Board nowboard;
    
    if(!can_beMax(tmv, move+1)){
        return;
    }
    cout << tmv << "\n";
    if(move == 10){
        max_value = max(max_value, tmv);
        return;
    }

    // 상하좌우로 움직이는 경우
    for(int i = 0; i < 4; i++){
        int tr;
        
        nowboard = bstack.top();
        tr = Board_move(i, nowboard);
        // 변화가 없는 경우
        if(checkboard(bstack.top(), nowboard)) continue;
        
        // 움직여서 최댓값을 갱신할 가능성이 있는 경우
        if(can_beMax(tr, move+1)){
            bstack.push(nowboard);
            
            DFS(move+1, tr);
            bstack.pop();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    init();
    DFS(0, max_value);
    cout << max_value;
    return 0;
}