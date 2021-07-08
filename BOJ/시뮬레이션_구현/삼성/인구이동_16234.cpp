#include <iostream>
#include <queue>
#include <cstring>

#define pii pair<int, int>
using namespace std;

int N, L, R;
int Map[51][51];
bool visited[51][51];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool is_moved;

void input(){
    cin >> N >> L >> R;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> Map[i][j];
        }
    }
}

void open_boarder(int r, int c, vector<pii > &country){
    queue<pii > que;
    visited[r][c] = true;
    
    que.push({r, c});
    
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        
        for(int k = 0; k < 4; k++){
            int nr = now.first + dr[k];
            int nc = now.second + dc[k];
            
            if(nr < 1 || nr > N || nc < 1 || nc > N || visited[nr][nc]) continue;
            
            int sub = abs(Map[nr][nc] - Map[now.first][now.second]);
            if(L <= sub && sub <= R){
                is_moved = true;
                visited[nr][nc] = true;
                country.push_back({nr, nc});
                que.push({nr, nc});
            }
        }
    }
}

void union_country(vector<pii > &country){
    int sum = 0;
    for(auto &w : country){
        sum += Map[w.first][w.second];
    }
    int avg = sum / country.size();
    
    for(int i = 0; i < country.size(); i++){
        Map[country[i].first][country[i].second] = avg;
    }
}

void show(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << Map[i][j] << " ";
            
        }
        cout << "\n";
    }
}

void solve(){
    int move_cnt = 0;
    
    while(!is_moved){
        memset(visited, 0, sizeof(visited));
        
        
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(visited[i][j]) continue;
                vector<pii > country;
                country.push_back({i, j});
                
                open_boarder(i, j, country);
                
                union_country(country);
            }
        }
        if(!is_moved){
            cout << move_cnt;
            return;
        }
        is_moved = false;
        // cout << "one cycle fin\n";
        // show();
        move_cnt++;
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
    
    return 0;
}