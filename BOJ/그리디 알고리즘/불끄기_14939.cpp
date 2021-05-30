#include <iostream>

#define INF 1e9+7
using namespace std;

int Map[11][11], TMap[11][11], result = INF, cnt = 0;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void turn(int r, int c){
    TMap[r][c] = !TMap[r][c];
    
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nc < 0 || nr >= 10 || nc >= 10) continue;
        TMap[nr][nc] = !TMap[nr][nc];
    }
}

bool is_solved(){
    // ���� ���� �ٷ� �� ������ 1�̸� �����ϹǷ� ���� ��������ġ�� ������
    for(int r = 1; r < 10; r++){
        for(int c = 0; c < 10; c++){
            if(TMap[r-1][c]){
                turn(r, c);
                cnt++;
            }
        }
    }
    
    // ������ �࿡ ������ ���������� �� �� �����Ƿ� false
    for(int c = 0; c < 10; c++){
        if(TMap[9][c]) return false;
    }
    
    return true;
}

void solve(){
    for(int k = 0; k < 1024; k++){
        // Map ����
        for(int r = 0 ; r < 10 ; r++){
            for(int c = 0 ; c < 10 ; c++){
                TMap[r][c] = Map[r][c];
            }
        }   
        
        cnt = 0;
        for(int i = 0; i < 10; i++){
            if(k & (1 << i)){
                cnt++;
                turn(0, i);
            }
        }
        
        if(is_solved()) result = min(result, cnt);
    }
    
    if(result == INF) cout << -1;
    else cout << result;
}

// dfs�� ����ϸ� �� �������� ������ ���¸� ��Ʈ��ŷ�ϱ� ����� ���δ�....

//void dfs(int r, int c){
//    if(c == 10){
//        if(is_solved()) result = min(result, cnt);
//        return;
//    }
//    dfs(r, c+1);
//    
//    turn(r, c, 0);
//    dfs(r, c+1);
//    turn(r, c, 0);
//    
//}

void input(){
    string str;
    for(int i = 0; i < 10; i++){
        cin >> str;
        for(int j = 0; j < 10; j++){
            if(str[j] == 'O') Map[i][j] = 1;
            else Map[i][j] = 0;
        }
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
