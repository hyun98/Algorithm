#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int indegree[1001];
vector<int> Singer[1001];

void input(){
    cin >> N >> M;
    for(int k = 0; k < M; k++){
        int nos, sn, firstsn;
        cin >> nos >> firstsn;
        for(int i = 1; i < nos; i++){
            cin >> sn;
            Singer[firstsn].push_back(sn);
            indegree[sn]++;
            firstsn = sn;
        }
    }
}

void topological(){
    vector<int> result;
    
    queue<int> que;
    bool visited[1001];
    memset(visited,0, sizeof(visited));
    
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            que.push(i);
            visited[i] = true;
        }
    }
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        
        result.push_back(now);
        
        for(int &next : Singer[now]){
            if(visited[next]) continue;
            
            if(--indegree[next] == 0){
                visited[next] = true;
                que.push(next);
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(indegree[i]){
            cout << 0;
            return;
        }
    }
    for(int &w : result){
        cout << w << "\n";
    }
}

int main(){
    input();
    topological();
    
    return 0;
}