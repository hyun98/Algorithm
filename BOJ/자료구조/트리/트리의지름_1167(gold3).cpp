#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

vector< pii > tree[100001];
int visited[100001];
int max_dist = 0;
int farthest_leaf;


void dfs(int now, int dist){
    if(dist > max_dist){
        max_dist = dist;
        farthest_leaf = now;
    }
    
    visited[now] = true;
    
    for(int i = 0; i < tree[now].size(); i++){
        int next = tree[now][i].first;
        int nwei = tree[now][i].second;
        
        if(visited[next]) continue;
        dfs(next, dist + nwei);
    }
    
}

void input(){
    int N, apex, to, wei;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> apex >> to;
        while(to != -1){
            cin >> wei;
            tree[apex].push_back({to, wei});
            cin >> to;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    
    // ������ �̷�� ù ��° ��� ã��
    dfs(1, 0);
    max_dist = 0;
    memset(visited, 0, sizeof(visited));
    
    // ������ �̷�� �� ��° ��� ã�� ���� ���ϱ�
    dfs(farthest_leaf, 0);
    
    cout << max_dist;
    
    return 0;
}
