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
int bridge[110];
bool visited[110];

void input(){
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < N + M; i++){
        cin >> x >> y;
        bridge[x] = y;
    }
}

void bfs(){
    // 현재 위치, 주사위 횟수
    queue<pii > que;
    que.push({1, 0});
    visited[1] = true;
    
    while(!que.empty()){
        int now = que.front().first;
        int now_cnt = que.front().second;
        que.pop();
        
        if(now == 100){
            cout << now_cnt;
            return;
        }
        
        for(int k = 1; k <= 6; k++){
            int next = now + k;
            
            if(visited[next]) continue;
            if(bridge[next]) next = bridge[next];
            
            visited[next] = true;
            que.push({next, now_cnt+1});
        }
    }
}

int main(){
    input();
    bfs();
    
    return 0;
}
