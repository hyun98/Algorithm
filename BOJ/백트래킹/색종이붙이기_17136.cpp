#include <iostream>

using namespace std;

int Map[11][11], paper_count[6] = {0, 5, 5, 5, 5, 5}, entire_count = 99999;
bool find_res = false;

// NxN 색종이를 r,c 기준으로 덮을 수 있는지 없는지 확인하는 함수
inline bool Map_check(int n, int r, int c, int state){
    bool go = true;
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
            if(Map[i][j] != state || i >= 10 || j >= 10){
                return false;
            }
        }
    }
    return true;
}

// NxN 색종이를 r,c 기준으로 nxn만큼 뒤집는 함수
inline void Map_reverse(int n, int r, int c){
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
            Map[i][j] = !Map[i][j];
        }
    }
}

void schedule(int r, int c, int cnt){
    // 지금까지 사용한 색종이의 수가 저장된 결과 값 보다 같거나크면 안됨
    if(cnt >= entire_count) return;
    
    // map을 모두 탐색하면 결과 값 비교
    if(r == 10){
        if(cnt < entire_count){
            entire_count = cnt;
            find_res = true;
        }
        return;
    }
    
    // 현재 행을 모두 탐색했으면 다음 행으로 
    if(c == 10) schedule(r+1, 0, cnt);
    
    int now_state = Map[r][c];
    if(!now_state) schedule(r, c+1, cnt);   // 현재 위치가 0이면 다음 위치로 이동
    
    // 5부터 내림차순으로 찾기 -> 큰 색종이 부터 찾아야 (cnt >= entire_count) 조건을 효과적으로 사용가능
    for(int k = 5; k >= 1; k--){
        // 색종이가 남아있고 덮을 수 있다면
        if(Map_check(k, r, c, 1) && paper_count[k] >= 1){
            paper_count[k]--;
            Map_reverse(k, r, c);
    
            schedule(r, c+k, cnt+1);
            
            Map_reverse(k, r, c);
            paper_count[k]++;
        }
    }
}

void derive_result(){
    if(find_res) cout << entire_count;
    else cout << -1;
}

void fork_map(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> Map[i][j];
        }
    }
}

void sys_process17136(){
    fork_map();
    schedule(0, 0, 0);
    derive_result();
}

int main(){
    sys_process17136();
    
    return 0;
}
