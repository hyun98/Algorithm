//------------------------------
//      2021-03-04
//      BFS  DFS
//       바이러스
//-----------------------------

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, pairs;
vector< vector<int> > Network;

void input(){
    int a, b;
    cin >> N >> pairs;
    Network.resize(N+1);
    for(int i = 0; i < pairs; i++){
        cin >> a >> b;
        Network[a].push_back(b);
        Network[b].push_back(a);
    }
}

int dfs_result = 0;
bool dfs_visited[101] = {false, };

void DFS(int now){
    
    dfs_result++;
    dfs_visited[now] = true;
    
    for(int i = 0; i < Network[now].size(); i++){
        int next = Network[now][i];
        if(!dfs_visited[next]){
            
            DFS(next);
        }
    }
}

void BFS(){
    int result = 0;
    queue<int> que;
    bool visited[101] = {false, };
    
    visited[1] = true;
    que.push(1);
    
    while(!que.empty()){
        int now = que.front();
        result++;
        que.pop();
        
        for(int i = 0; i < Network[now].size(); i++){
            int next = Network[now][i];
            if(!visited[next]){
                // 여기서 방문 처리를 해주어야 했ㅇㅓ
                // 다음 for문에서 지금 방문한 next인자를 또 방문 할 수도 있으니까 그걸 방지해야함
                visited[next] = true;
                que.push(next);
            }
        }
    }
    
    cout << result - 1;
}

int main(){
    input();
    BFS();
//    DFS(1);
//    cout << dfs_result - 1;
    
    return 0;
}
