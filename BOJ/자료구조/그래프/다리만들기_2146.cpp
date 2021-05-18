#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9+7
using namespace std;

struct point{
    int r, c;
};

int N, Map[101][101];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
bool visited[101][101];

vector< vector<point> > boundary;

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
        }
    }
}

void island_boundary(int r, int c){
    vector<point> land;
    queue<point> que;
    que.push({r, c});
    
    visited[r][c] = true;
    
    while(!que.empty()){
        point now = que.front();
        que.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(Map[nr][nc] == 0){
                land.push_back({now.r, now.c});
                break;
            }
        }
        
        for(int i = 0; i < 4; i++){
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || !Map[nr][nc]) continue;
            
            visited[nr][nc] = true;
            que.push({nr, nc});
        }
    }
    
    boundary.push_back(land);
}

int dist(point &a, point &b){
    return abs(a.r - b.r) + abs(a.c - b.c) - 1;
}

int min_dist(vector<point> &a, vector<point> &b){
    int min_d = INF;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            min_d = min(min_d, dist(a[i], b[j]));
        }
    }
    return min_d;
}

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Map[i][j] == 1 && !visited[i][j]){
                island_boundary(i, j);
            }
        }
    }
    
    int result = INF;
    
    // 섬간의 거리를 모두 탐색
    for(int i = 0; i < boundary.size()-1; i++){
        for(int j = i+1; j < boundary.size(); j++){
            // 섬간의 거리중 최솟값 반환
            result = min(result, min_dist(boundary[i], boundary[j]));
        }
    }
    
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    
    return 0;
}
