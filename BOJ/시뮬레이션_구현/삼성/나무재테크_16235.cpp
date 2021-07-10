#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1e9+7

typedef long long ll;
typedef pair<int, int> pii;
// #define pii pair<int, int>
using namespace std;

int N, M, K;
deque<int> tree[11][11];
int food[11][11];
int feeding[11][11];

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool is_tree;

void input(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> feeding[i][j];
            food[i][j] = 5;
        }
    }
    
    int r, c, a;
    for(int i = 0; i < M; i++){
        cin >> r >> c >> a;
        tree[r-1][c-1].push_back(a);
    }
    
}

void SpringSummer(){
    // Spring
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            for(int i = 0; i < tree[r][c].size(); i++){
                if (tree[r][c][i] > food[r][c]){
                    while(i < tree[r][c].size()){
                        food[r][c] += tree[r][c].back()/2;
                        tree[r][c].pop_back();
                    }
                }
                else{
                    food[r][c] -= tree[r][c][i];
                    tree[r][c][i]++;
                }
            }
        }
    }
}

void FallWinter(){
    //Fall
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            food[r][c] += feeding[r][c]; // Winter
            for(int i = 0; i < tree[r][c].size(); i++){
                if (tree[r][c][i] % 5 != 0) continue;
                
                for(int k = 0; k < 8; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    
                    if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                    tree[nr][nc].push_front(1);
                }
            }
        }
    }
}

void solve(){
    
    while(K--){
        SpringSummer();
        FallWinter();
    }
    
    int cnt = 0;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            cnt += tree[r][c].size();
        }
    }
    
    cout << cnt;
}

int main(){
    input();

    // 4계절이 있다
    // 봄에는 양분을 먹는다. 자신의 나이만큼 양분을 먹지 못하면 죽는다
    // 여름에는 죽은 나무마다 나이/2 만큼 해당 칸에 양분으로 추가된다. 소수점버림
    // 가을에는 나이가 5의 배수인 나무의 주위 8칸에 나무가 생긴다.(나이 1)
    // 겨울에는 주어진 입력만큼 각 칸에 양분이 추가된다.
    // K년 후 살아있는 나무의 개수

    solve();

    return 0;
}
