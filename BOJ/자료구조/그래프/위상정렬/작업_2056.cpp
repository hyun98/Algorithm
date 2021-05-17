#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> times, indg, dp;
vector< vector<int> > graph;

void input(){
    int t, before;
    cin >> N;
    
    times.resize(N+1, 0);
    indg.resize(N+1, 0);
    dp.resize(N+1, 0);
    graph.resize(N+1);
    
    for(int i = 1; i <= N; i++){
        cin >> times[i] >> t;
        for(int j = 0; j < t; j++){
            cin >> before;
            graph[before].push_back(i);
            indg[i]++;
        }
    }
}

void process(){
    queue<int> que;
    int result = 0;
    
    for(int i = 1; i <= N; i++){
        if(indg[i] == 0){
            que.push(i);
            dp[i] = times[i];
        }
    }
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        
        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i];
            
            if(--indg[next] == 0){
                que.push(next);
            }
            dp[next] = max(dp[next], dp[now] + times[next]);
        }
    }
    
    for(int i = 1; i <= N; i++){
        result = max(result, dp[i]);
    }
    
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    process();
    return 0;
}
