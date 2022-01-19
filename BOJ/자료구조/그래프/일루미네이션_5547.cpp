#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int W, H;
int Map[101][101];

int odx[6] = {1, 1, 1, 0, -1, 0};
int ody[6] = {-1, 0, 1, 1, 0, -1};
int edx[6] = {0, 1, 0, -1, -1, -1};
int edy[6] = {-1, 0, 1, 1, 0, -1};

void input(){
    cin >> W >> H;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> Map[j][i];
        }
    }
}

void bfs1(pii start){
    queue<pii > que;
    que.push(start);
    
    bool visited[101][101];
    memset(visited, 0, sizeof(visited));
    visited[start.first][start.second] = true;
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        Map[x][y] = 2;
        
        for(int i = 0; i < 6; i++){
            int nx = x + (y % 2? odx[i]: edx[i]);
            int ny = y + (y % 2? ody[i]: edy[i]);
            
            if(nx < 1 || nx > W || ny < 1 || ny > H || \
            visited[nx][ny] || Map[nx][ny] == 1) continue;
            
            visited[nx][ny] = true;
            que.push({nx, ny});
        }
    }
}

bool Tvisited[101][101];
int bfs2(pii start){
    int ret = 0;
    
    queue<pii > que;
    que.push(start);
    
    Tvisited[start.first][start.second] = true;
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 6; i++){
            int nx = x + (y % 2? odx[i]: edx[i]);
            int ny = y + (y % 2? ody[i]: edy[i]);
        
            if(Tvisited[nx][ny]) continue;
            if(nx < 1 || nx > W || ny < 1 || ny > H || Map[nx][ny] == 2){
                ret++;
                continue;
            }
            if(Map[nx][ny] == 0) continue;
            
            Tvisited[nx][ny] = true;
            que.push({nx, ny});
        }
    }
    
    return ret;
}


void solve(){
    // 가운데 들어간 빈 공간이 문제
    
    // 빈 공간이 건물 내부인지 외부인지 판별
    for(int i = 1; i <= W; i++){
        for(int j = 1; j <= H; j++){
            if(Map[i][j] == 1) continue;
            if(i == 1 || j == 1 || i == W || j == H){
                bfs1({i, j});
            }
        }
    }
    
    // 건물 내부의 빈 공간이면 0, 외부의 빈 공간이면 2, 건물이면 1
    int answer = 0;
    
    memset(Tvisited, 0, sizeof(Tvisited));
    for(int i = 1; i <= W; i++){
        for(int j = 1; j <= H; j++){
            if(Map[i][j] == 0 || Map[i][j] == 2 || Tvisited[i][j]) continue;
            answer += bfs2({i, j});
        }
    }
    cout << answer;
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
