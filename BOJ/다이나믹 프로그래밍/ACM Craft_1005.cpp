#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ACM{
    int N, K, X, Y, W;
    vector<int> times, indg, dp;
    vector< vector<int> > graph;
public:
    ACM(){
        cin >> N >> K;
        times.resize(N+1);
        graph.resize(N+1);
        indg.resize(N+1, 0);
        dp.resize(N+1, 0);
        for(int i = 1; i <= N; i++){
            cin >> times[i];
        }
        for(int i = 0; i < K; i++){
            cin >> X >> Y;
            graph[X].push_back(Y);
            indg[Y]++;
        }
        cin >> W;
        
//        cout << "input done\n";
    }
    
    void BFS(){
        queue<int> que;
        //indegree가 0인 원소들을 que에 넣어준다
        for(int i = 1; i <= N; i++){
            if(indg[i] == 0){
                que.push(i);
                dp[i] = times[i];
            }
        }
        
        while(!que.empty()){
            int now = que.front();
            que.pop();
            if(now == W) break;
            
            for(int i = 0; i < graph[now].size(); i++){
                int next = graph[now][i];
                if(--indg[next] == 0){
                    que.push(next);
                }
                if(dp[next] < dp[now] + times[next]){
                    dp[next] = dp[now] + times[next];
                }
                
            }
        }
        cout << dp[W] << "\n";
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        ACM A1;
        A1.BFS();
    }
    return 0;
}
