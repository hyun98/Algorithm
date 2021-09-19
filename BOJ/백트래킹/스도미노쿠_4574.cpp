#include <iostream>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int, int>

using namespace std;


int N, puzzlecnt;
int Map[10][10];
int row[10][10];
int col[10][10];
int box[10][10];
int dr[2] = {0, 1}, dc[2] = {1, 0};
bool flag;
bool check[10][10];


pii parse_coord(string s){
    pii ret;
    ret.first = s[0] - 'A';
    ret.second = s[1] - '1';
    return ret;
}

inline int boxnum(int r, int c){
    return (r/3)*3 + (c/3);
}

void input(){
    flag = false;
    memset(Map, 0, sizeof(Map));
    memset(check, 0, sizeof(check));
    int u, v;
    pii coord;
    string lu, lv;
    for(int i = 0; i < N; i++){
        cin >> u >> lu >> v >> lv;
        coord = parse_coord(lu);
        Map[coord.first][coord.second] = u;
        coord = parse_coord(lv);
        Map[coord.first][coord.second] = v;
        check[u][v] = check[v][u] = true;
    }
    for(int i = 1; i <= 9; i++){
        cin >> lu;
        coord = parse_coord(lu);
        Map[coord.first][coord.second] = i;
    }
}

// bool is_possible(int r, int c, int num){
//     return !row[r][num] && !col[c][num] && !box[boxnum(r, c)][num];
// }

bool is_possible(int r, int c){
    // row, col check
    for(int i = 0; i < 9; i++){
        if(Map[r][c] == Map[r][i] && i != c) return false;
        if(Map[r][c] == Map[i][c] && i != r) return false;
    }
    
    int sr = (r / 3) * 3;
    int sc = (c / 3) * 3;
    
    // box check
    for(int i = sr; i < sr + 3; i++){
        for(int j = sc; j < sc + 3; j++){
            if(i == r && j == c) continue;
            if(Map[r][c] == Map[i][j]) return false;
        }
    }
    
    return true;
}

void print_Map(){
    cout << "Puzzle " << puzzlecnt << "\n";
    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            cout << Map[r][c];
        }
        cout << "\n";
    }
}

void dfs(int cnt){
    if(flag) return;
    if(cnt == 81){
        print_Map();
        flag = true;
        return;
    }
    
    int r = cnt / 9;
    int c = cnt % 9;

    if(!Map[r][c]){
        // right, down
        for(int k = 0; k < 2; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr < 0 || nr >= 9 || nc < 0 || nc >= 9 || Map[nr][nc]) continue;
            
            for(int i = 1; i <= 9; i++){
                for(int j = 1; j <= 9; j++){
                    if(check[i][j] || i == j) continue;
                    Map[r][c] = i;
                    Map[nr][nc] = j;
                    check[i][j] = check[j][i] = true;
                    
                    if(is_possible(r, c) && is_possible(nr, nc)){
                        
                        // row[r][i] = col[c][i] = box[boxnum(r, c)][i] = true;
                        // row[nr][j] = col[nc][j] = box[boxnum(nr, nc)][j] = true;
                        
                        dfs(cnt+1);
                        if(flag) return;
                        
                        // row[r][i] = col[c][i] = box[boxnum(r, c)][i] = false;
                        // row[nr][j] = col[nc][j] = box[boxnum(nr, nc)][j] = false;
                        
                    }
                    check[i][j] = check[j][i] = false;
                    Map[r][c] = Map[nr][nc] = 0;
                }
            }
            
        }
    }
    else dfs(cnt+1);
}

int main(){
    int puzzle = 1;
    cin >> N;
    while(N){
        puzzlecnt++;
        input();
        dfs(0);
        cin >> N;
    }
    
    return 0;
}
