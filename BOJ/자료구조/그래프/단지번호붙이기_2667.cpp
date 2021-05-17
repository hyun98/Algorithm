#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
string MAP[25];
bool visit[25][25] = { false, };
int N, cnt;
vector<int> ans;

void dfs(int i, int j) {
    visit[i][j] = true;
    cnt++;

    for (int k = 0; k < 4; k++) {
        int newY = i + dy[k];
        int newX = j + dx[k];

        if (0 <= newX && newX < N && 0 <= newY && newY < N)
            if(MAP[newY][newX] == '1' && !visit[newY][newX]) dfs(newY, newX);
    }
}

int main() {
    int i, j;
    cin >> N;
    for (i = 0; i < N; i++) cin >> MAP[i];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if(MAP[i][j] == '1' && !visit[i][j]) {
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto w : ans) cout << w << "\n";

    return 0;
}
