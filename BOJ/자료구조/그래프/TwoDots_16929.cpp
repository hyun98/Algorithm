#include <iostream>
#include <cstring>

using namespace std;

int N, M;
char Map[51][51];
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
bool visited[51][51], visited_dfs[51][51];

void dfs(char now, int sr, int sc, int d, int r, int c){
    /*
        �������� �ٽ� �����ϰų� �̵��� ���� ���� ������ Ž��
    */
    
    
    if(d >= 4 && (sr == r && sc == c)){
        /*
            4�� �̻��� ������ ������ ����Ŭ�̰ų� ���� ��ǥ�� ���� ��ǥ�� ������
            ����Ŭ�� ã�����Ƿ� ���α׷� ����
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
        
        // ���� ����ų� ���� ���ڰ� ���� ���ڿ� �ٸ���� Ž������ �ʴ´�
        if(nr < 0 || nc < 0 || nr >= N || nc >= M || next != now) continue;
        else dfs(next, sr, sc, d+1, nr, nc);
    }
}

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            /*
                ���������� ����� ���� �ٽ� Ž���غ� �ʿ䰡 ����
                �̹� �ش� ������ ���� dfs Ž���� �Ϸ��߱� ������ �ٸ����� ���ļ� �Դٰ� �Ͽ� �ٽ� dfs�� �Ѵٴ°�  
                �ߺ��� �ſ� �������� �ȴ�
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
