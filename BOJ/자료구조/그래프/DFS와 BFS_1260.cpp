#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

//첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000),
//탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
//어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.
//첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

struct C{
    int x, y;
};

vector< C > temp;
vector< vector<int> > graph;
int D_visit[1001] = {0, }, B_visit[1001] = {0, };
int M, N, V;

bool comp(C a, C b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    else{
       return a.x < b.x;
    }
}

void DFS(int node){
    if(D_visit[node]){
        return;
    }
    cout << node << " ";

    D_visit[node] = 1;

    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        DFS(next);
    }
}

void BFS(int node){
    queue<int> que;

    que.push(node);
    B_visit[node] = 1;

    while(que.size() > 0){
        int x = que.front();
        que.pop();
        cout << x << " ";
        for(int i = 0; i < graph[x].size(); i++){
            int y = graph[x][i];
            if(B_visit[y] == 0){
                que.push(y);
                B_visit[y] = 1;
            }
        }
    }
}

void input(){
    int a, b;
    cin >> N >> M >> V;
    graph.reserve(10000);

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        temp.push_back({a, b});
        temp.push_back({b, a});
    }

    sort(temp.begin(), temp.end(), comp);

    for(int i = 0; i < M*2; i++){

        int rem = temp[i].x;
        vector<int> v;
        while(rem == temp[i].x){
            v.push_back(temp[i].y);
            i++;
        }
        i--;
        graph[rem] = v;
        v.clear();
    }
}

int main(){
    input();
    DFS(V);
    cout << "\n";
    BFS(V);
    return 0;
}
