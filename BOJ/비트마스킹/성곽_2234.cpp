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

int N, M;
int Map[51][51];
int setMap[51][51];
int setnum[2505];
int setcount = 1;
int dr[4] = {0, -1, 0, 1}, dc[4] = {-1, 0, 1, 0};
int dir[4] = {1, 1 << 1, 1 << 2, 1 << 3}; // 서 북 동 남

void input(){
    cin >> M >> N;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> Map[r][c];
        }
    }
}

int bfs12(int r, int c){
    int cnt = 0;
    queue<pii > que;
    que.push({r, c});
    
    setMap[r][c] = setcount;
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        cnt++;
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            // 뚫려 있는 경우
            if(!(dir[k] & Map[now.first][now.second]) && !setMap[nr][nc]){
                setMap[nr][nc] = setcount;
                que.push({nr, nc});
            }
        }
    }
    setnum[setcount] = cnt;
    setcount++;
    return cnt;
}


int find3(int r, int c){
    int ret = setnum[setMap[r][c]];
    for(int k = 0; k < 4; k++){
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(setMap[nr][nc] != setMap[r][c]){
            ret = max(ret, setnum[setMap[r][c]] + setnum[setMap[nr][nc]]);
        }
    }
    
    return ret;
}

void solve(){
    int number_of_rooms_in_this_castle = 0, largest_room_area = 0;
    int largest_room_size_obtained_by_removing_one_wall = 0;
    
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(setMap[r][c]) continue;
            largest_room_area = max(largest_room_area, bfs12(r, c));
            number_of_rooms_in_this_castle++;
        }
    }
    
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            largest_room_size_obtained_by_removing_one_wall = \
            max(largest_room_size_obtained_by_removing_one_wall, find3(r, c));
        }
    }
    
    cout << number_of_rooms_in_this_castle << "\n";
    cout << largest_room_area << "\n";
    cout << largest_room_size_obtained_by_removing_one_wall << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
