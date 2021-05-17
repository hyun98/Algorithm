#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point{
    int r, c;
};

int Box[1001][1001];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int N, M, day = 0;

void BFS(){
    queue<Point> que1, que2;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Box[i][j] == 1) que1.push({i, j});
        }
    }
    
    while(!que1.empty() || !que2.empty()){
        while(!que1.empty()){
            que2.push({que1.front().r, que1.front().c});
            que1.pop();
        }
        
        day++;
        while(!que2.empty()){
            int now_r = que2.front().r;
            int now_c = que2.front().c;
            que2.pop();
            
            for(int i = 0; i < 4; i++){
                int nr = now_r + dr[i];
                int nc = now_c + dc[i];
                if(0 <= nr && nr < N && 0 <= nc && nc < M){
                    if(Box[nr][nc] == 0){
                        Box[nr][nc] = 1;
                        que1.push({nr, nc});
                    }
                }
            }
        }
    }
    
    bool all_ripped = true;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Box[i][j] == 0) all_ripped = false;
        }
    }
    
    cout << (all_ripped? day-1:-1);
    
}

void input(){
    int a;
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Box[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    BFS();
    return 0;
}
