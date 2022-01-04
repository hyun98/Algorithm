#include <vector>
#include <queue>
#include <cstring>

#define pii pair<int, int>

using namespace std;

int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
bool visited[101][101];
int bfs(int r, int c, int m, int n, vector<vector<int>> &picture){
    // 영역의 개수
    int ret = 1;
    int color = picture[r][c];
    queue<pii > que;
    que.push({r, c});
    visited[r][c] = true;

    while(!que.empty()){
        pii now = que.front();
        que.pop();

        for(int i = 0; i < 4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if(nr < 0 || nr >= m || nc < 0 || nc >= n || \
               visited[nr][nc] || picture[nr][nc] != color) continue;

            visited[nr][nc] = true;
            que.push({nr, nc});
            ret++;
        }
    }
    return ret;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] || !picture[i][j]) continue;
            number_of_area++;
            max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, m, n, picture));
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
