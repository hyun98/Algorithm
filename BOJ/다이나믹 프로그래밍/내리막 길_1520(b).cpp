/*
    BFS를 이용해서 푼 풀이.
    메모리 초과로 인해 풀 수 없음
    queue가 터짐
    2021-01-10
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct P{
    int row, col;
};

vector< vector<P> > dp[501];
int M, N;
int Map[501][501] = {99999, };
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

void BFS(){
    queue<P> que;
    int result = 0;
    que.push({0, 0});
    
    while(!que.empty()){
        P now;
        now = que.front();
        que.pop();
        if(now.row == M-1 && now.col == N-1) result++;
        
        for(int i = 0; i < dp[now.row][now.col].size(); i++){
            P next = dp[now.row][now.col][i];
            que.push(next);
        }
    }
    
    cout << result;
}

void inputNsetting(){
    for(int i = 0; i < 501; i++){
        dp[i].resize(501, vector<P>());
    }
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 4; k++){
                if(i+dr[k] >= 0 && i+dr[k] < M && j+dc[k] >= 0 && j+dc[k] < N){
                    if(Map[i][j] > Map[i+dr[k]][j+dc[k]]){
                        dp[i][j].push_back({i+dr[k], j+dc[k]});
                    }
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    inputNsetting();
    BFS();
    return 0;
}
