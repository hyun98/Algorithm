#include <string>
#include <vector>

using namespace std;


// 제한사항
// 2 ≤ info의 길이 ≤ 17
// info의 원소는 0 또는 1 입니다.
// info[i]는 i번 노드에 있는 양 또는 늑대를 나타냅니다.
// 0은 양, 1은 늑대를 의미합니다.
// info[0]의 값은 항상 0입니다. 즉, 0번 노드(루트 노드)에는 항상 양이 있습니다.
// edges의 세로(행) 길이 = info의 길이 - 1
// edges의 가로(열) 길이 = 2
// edges의 각 행은 [부모 노드 번호, 자식 노드 번호] 형태로, 서로 연결된 두 노드를 나타냅니다.
// 동일한 간선에 대한 정보가 중복해서 주어지지 않습니다.
// 항상 하나의 이진 트리 형태로 입력이 주어지며, 잘못된 데이터가 주어지는 경우는 없습니다.
// 0번 노드는 항상 루트 노드입니다.

bool visited[1 << 18];
vector<int> adj[18];
int answer;
int N;

void backtracking(int history, vector<int> &info){
    if(visited[history] == 1) return;
    visited[history] = true;
    
    int sheep = 0, wolf = 0;
    
    for(int i = 0; i < N; i++){
        // 현재 방문한 정점들 확인
        if(history & (1 << i)){
            if(info[i]) sheep++;
            else wolf++;
        }
    }
    
    if(wolf >= sheep) return;
    
    answer = max(answer, sheep);
    
    for(int i = 0; i < N i++){
        if(!(history | (1 << i))) continue;
        for(int k = 0; k < adj[i].size(); k++){
            int newHistory = history | (1 << i);
            backtracking(newHistory, info);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    N = info.size();
    
    for(int i = 0; i < edges.size(); i++){
        adj[edges[0]].push_back(edges[1]);
    }
    
    // root 방문
    int history = 1;
    
    backtracking(history, info);
    
    return answer;
}