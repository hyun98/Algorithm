#include <iostream>
#include <vector>
using namespace std;

struct V{
    vector<int> indegree;
    int time;
};

int N, dp[501];
vector<V> buildings;

void input(){
    int t;
    cin >> N;
    buildings.resize(N+1);
    for(int i = 1; i <= N; i++){
        V build;
        cin >> buildings[i].time;
        cin >> t;
        while(t != -1){
            buildings[i].indegree.push_back(t);
            cin >> t;
        }
        
        dp[i] = -1;
    }
}

int topological(int v){
    if(dp[v] != -1) return dp[v];
    int spend_time = 0;
    for(int i = 0; i < buildings[v].indegree.size(); i++){
        int next = buildings[v].indegree[i];
        spend_time = max(spend_time, topological(next));
    }
    spend_time += buildings[v].time;
    return dp[v] = spend_time;
}

void solve(){
    for(int i = 1; i <= N; i++){
        cout << topological(i) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    
    return 0;
}
