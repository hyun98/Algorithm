#include <iostream>

using namespace std;

int N, start, result = 99999999;
int Link[11][11];
bool visited[11] = {false, };

inline void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Link[i][j];
        }
    }
}

// now : 현재 위치한 도시 
// sum : 지금까지 사용된 비용
// v_num : 지금까지 방문한 도시의 수
void dfs(int now, int sum, int v_num){
    if(v_num == N && Link[now][start]){
        result = min(result, sum + Link[now][start]);
        return;
    }
    
    visited[now] = true;
    for(int next = 0; next < N; next++){
        if(!visited[next] && Link[now][next] && sum + Link[now][next] < result){
            dfs(next, sum + Link[now][next], v_num+1);
        }
    }
    visited[now] = false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    dfs(0, 0, 1);
    cout << result;
    
    return 0;
}
