#include <iostream>
#include <cstring>

using namespace std;

int N, M;
char Map[51][51];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
bool visited[51][51], visited_dfs[51][51];

void dfs(char now, int sr, int sc, int d, int r, int c){
    /*
        시작점에 다시 도착하거나 이동할 곳이 없을 때까지 탐색
    */
    
    
    if(d >= 4 && (sr == r && sc == c)){
        /*
            4개 이상의 점으로 구성된 사이클이거나 현재 좌표가 시작 좌표와 같으면
            사이클을 찾았으므로 프로그램 종료
        */
        cout << "Yes";
        exit(0);
    }
    
    
    if(visited_dfs[r][c] || (visited[r][c] && d)) return;
    visited_dfs[r][c] = true;
    
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        char next = Map[nr][nc];
        
        // 맵을 벗어나거나 다음 문자가 시작 문자와 다를경우 탐색하지 않는다
        if(nr < 0 || nc < 0 || nr >= N || nc >= M || next != now) continue;
        else dfs(next, sr, sc, d+1, nr, nc);
    }
}

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            /*
                시작점으로 지목된 점은 다시 탐색해볼 필요가 없다
                이미 해당 점으로 부터 dfs 탐색을 완료했기 때문에 다른점을 거쳐서 왔다고 하여 다시 dfs를 한다는건  
                중복이 매우 많아지게 된다
            */
            visited[i][j] = true;
            char now = Map[i][j];
            memset(visited_dfs, 0, sizeof(visited_dfs));
            dfs(now, i, j, 0, i, j);
        }
    }
    cout << "No";
}

void input(){
    string str;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            Map[i][j] = str[j];
        }
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
