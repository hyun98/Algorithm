#include <bits/stdc++.h>

using namespace std;

struct P{
    int r, c;
};

int M, N, K;
bool Map[101][101];
int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
vector<int> area;

void input(){
    cin >> M >> N >> K;
    int r1, c1, r2, c2;
    for(int i = 0; i < K; i++){
        cin >> c1 >> r1 >> c2 >> r2;
        for(int r = r1; r < r2; r++){
            for(int c = c1; c < c2; c++){
                Map[r][c] = true;
            }
        }
    }
}

void BFS(int r, int c){
    
    int now_area = 1;
    
    queue<P> que;
    que.push({r, c});
    
    while(!que.empty()){
        int nowr = que.front().r;
        int nowc = que.front().c; 
        que.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = nowr + dr[i];
            int nc = nowc + dc[i];
            if(!Map[nr][nc] && nr >= 0 && nr < M && nc >= 0 && nc < N){
                Map[nr][nc] = true;
                now_area++;
                que.push({nr, nc});
            }
        }
    }
    
    area.push_back(now_area);
}

void solve(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!Map[i][j]){
                Map[i][j] = true;
                BFS(i, j);
            }
        }
    }
    
    sort(area.begin(), area.end());
    cout << area.size() << "\n";
    for(auto w : area){
        cout << w << " ";
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
