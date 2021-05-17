#include <iostream>
#include <vector>
using namespace std;

struct P{
    int row, col;
};

int N, M;
int Paper[501][501];
bool visited[501][501];
int result = 0;

void input(){
    cin >> N >> M;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> Paper[r][c];
            visited[r][c] = false;
        }
    }
}

vector<P> tblock;
bool temp_visited[501][501];

// dfs가 돌아가면서 어떤 좌표에 어떤 테트로미노가 놓이는지 보여줌
void show_block(){
    int Map[501][501];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            Map[i][j] = 1;
        }
    }
    for(int i = 0; i < tblock.size(); i++){
        Map[tblock[i].row][tblock[i].col] = 0;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << Map[i][j] << " ";
        }
        cout << endl;
    }
}

inline bool is_near(int row, int col){
    for(int i = 0; i < tblock.size(); i++){
        int a = abs(tblock[i].row - row);
        int b = abs(tblock[i].col - col);
        // 새로운 블럭의 좌표가 기존 블럭의 좌표들과 하나라도 붙어있으면 true 리턴 
        if((a == 1 && b == 0) || (a == 0 && b == 1)) return true;
    }
    return false;
}

void dfs(int row, int col, int used_block){
    // 여러 과정을 거쳐 만들어진 블럭의 개수가 4개이면 블럭들의 좌표에 있는 값들을 더해서
    // 지금까지의 결과값과 비교해 큰 값으로 갱신한다
    // 그리고 마지막에 들어왔던 블럭을 삭제하고 다른 자리의 마지막 블럭을 탐색해본다
    if(used_block == 4){
        tblock.push_back({row, col});
        int temp_result = 0;
        for(int i = 0; i < 4; i++){
//            cout << tblock[i].row << " " << tblock[i].col << endl;
            temp_result += Paper[tblock[i].row][tblock[i].col];
        }
        
        result = max(result, temp_result);
//        cout << endl;
//        show_block();
        tblock.pop_back();
        return;
    }
    
    temp_visited[row][col] = true;
    tblock.push_back({row, col});
//    show_block();
//    cout << endl;
    // r과 c모두 -1 부터 1까지라서 현재 블럭의 대각선 좌표까지도 접근 가능하다 -> 'ㅗ'를 만들기 위함
    for(int r = -1; r <= 1; r++){
        for(int c = -1; c <= 1; c++){
            // 다음 방문할 좌표가 Paper 안에 있지 않거나 dfs를 돌면서 방문한 좌표거나 지금까지 탐색한 좌표중 하나이면 좌표를 탐색하지 않는다
            if(row+r < 0 || col+c < 0 || row+r >= N || col+c >= M || visited[row+r][col+c] || temp_visited[row+r][col+c]) continue;
            // 현재 만들어진 블럭들과 다음 방문할 좌표가 붙어있으면 다음 방문할 좌표의 블럭을 지금까지 만들어진 블럭에 추가할 수 있다
            if(is_near(row+r, col+c)){
                dfs(row+r, col+c, used_block+1);
            }
        }
    }
    // 현재 좌표를 사용해서 만들 수 있는 블럭을 다 만들었으면
    // 마지막에 들어간 블럭을 빼고 다른 블럭을 넣어서 탐색해 본다
    tblock.pop_back();
    temp_visited[row][col] = false;
}

void solve(){
    
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            visited[r][c] = true;
            dfs(r, c, 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    cout << result;
    
    return 0;
}
