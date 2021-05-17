#include <iostream>
#include <vector>

using namespace std;

vector<int> *tree;
vector<bool> visit;
int result = 0;
void dfs_search(int node, int r){

    visit[node] = true;

    int cnt = 0;
    for(int i = 0; i < tree[node].size(); i++){
        int next = tree[node][i];
        if(visit[next] == true) continue;

        cnt++;
        dfs_search(next, r+1);
    }

    if(cnt == 0) result += r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, N;
    cin >> N;

    tree = new vector<int>[N+1];
    visit.resize(N+1, false);

    for(int i = 0; i < N-1; i++){
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs_search(1, 0);

    if(result % 2 == 1) cout << "Yes";
    else cout <<"No";

    return 0;
}
