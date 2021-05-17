//--------------DFS�� �̿��� ��������------------------

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N;
vector< vector<int> > order;
deque<int> result;
vector<bool> visit;

void dfs(int node){
    visit[node] = true;

    for(int i = 0; i < order[node].size(); i++){
        int next = order[node][i];
        if(!visit[next]) dfs(next);

    }
    result.push_back(node);
}

void topologicalSort(){
    for(int i = 1; i <= N; i++){
        if(!visit[i]){
            dfs(i);
        }
    }

    for(auto w :result){
        cout << w << " ";
    }
}


void input(){
    int M, A, B;
    cin >> N >> M;
    visit.resize(N+1, false);
    order.resize(N+1, vector<int>());
    while(M--){
        cin >> A >> B;  //�л� A�� �л� B�� �տ� ���� �Ѵٴ� �ǹ�
        order[A].push_back(B);
    }
}

int main(){
    input();
    topologicalSort();

    return 0;
}
