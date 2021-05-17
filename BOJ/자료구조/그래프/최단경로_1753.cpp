#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;

struct P{
    int dest;
    int wei;
};

struct A{
    int idx;
    int cost;
};

vector< vector<P> > Graph;
vector<int> dist;

struct cmp{
    bool operator()(const A& a, const A& b){
        // ��������
        return a.cost > b.cost;
    }
};

void input(){
    cin >> V >> E >> K;
    // K���� K���� �ִܰŸ��� 0
    
    dist.resize(V+1, 1e9+7);
    Graph.resize(V+1);
    int u, v, cost;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> cost;
        // u��° ��忡�� v�ΰ��� cost�� �Է�
        Graph[u].push_back({v, cost});
    }
}

void dijkstra(){
    dist[K] = 0;
    
    priority_queue<A, vector<A>, cmp> heap;
    heap.push({K, 0});
    
    while(!heap.empty()){
        // K���� now_idx���� 
        int min_cost = heap.top().cost;
        int now_idx = heap.top().idx;
        heap.pop();
        
        // �߿��� �κ�
        // K���� now_idx������ �ּڰ��� �̹� ������ �ִٸ� �Ѿ��
        if(min_cost > dist[now_idx]) continue;
        
        for(int i = 0; i < Graph[now_idx].size(); i++){
            int next = Graph[now_idx][i].dest;
            int next_cost = min_cost + Graph[now_idx][i].wei;
            if(dist[next] > next_cost){
                dist[next] = next_cost;
                heap.push({next, dist[next]});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    dijkstra();
    for(int i = 1; i <= V; i++){
        if(dist[i] == 1e9+7) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
