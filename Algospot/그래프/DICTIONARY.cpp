//위상정렬(Topological Sort)
//DFS를 사용한..
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > adj;

//그래프 정렬 기준 :
void makeGraph(const vector<string>& words){
    //알파벳의 수가 26개이므로 인접행렬을 사용해도 메모리에 큰 영향을 주지않는다
    adj = vector<vector<int>> (26, vector<int> (26, 0));

    for(int i = 0; i < words.size() - 1; i++){
        // 첫 번째 단어부터 마지막 단어까지 2개씩 비교
        int len = min(words[i].size(), words[i+1].size());
        // 같은 단어는 없으므로 더 짧은 단어를 기준으로 같은위치에 있는 알파벳을 서로 비교한다
        for(int k = 0; k < len; k++){
            // i 번째 단어와 그 다음 단어의 k번째(같은 위치의) 알파벳 비교 -> 서로 다르면 i번째 단어의 k번째 알파벳이 무조건 빠른것임
            if(words[i][k] != words[i+1][k]){
                int a = words[i][k] - 'a';
                int b = words[i+1][k] - 'a';

                adj[a][b] = 1;  //a번째 행의 알파벳 다음에 b번째 알파벳이 온다는 말.
                break;
            }
        }
    }
}

vector<int> order;
vector<bool> visited;
void dfs(int node){
    visited[node] = true;

    for(int i = 0; i < adj[node].size(); i++){
        if(adj[node][i] && !visited[i]) dfs(i);
    }
    order.push_back(node);
}

vector<int> topologicalSort(){
    visited = vector<bool> (26, false);
    order.clear();

    //아직 방문하지 않은 알파벳 부터 dfs를 반복적으로 시작
    for(int i = 0; i < adj.size(); i++){
        if(!visited[i]) dfs(i);
    }
    reverse(order.begin(), order.end());

    for(int i = 0; i < adj.size(); i++){
        for(int j = i+1; j < adj.size(); j++){
            //order에서 뒷 알파벳이 앞 알파벳 보다 앞선다는 정보(adj[뒤][앞] == 1)가 있으면 fail
            if(adj[order[j]][order[i]]){
                return vector<int>();
            }
        }
    }
    return order;
}

void dic_test(){
    int N;
    cin >> N;
    string input;
    vector<string> words;
    for(int i = 0; i < N; i++){
        cin >> input;
        // 단어들이 입력되고 words라는 벡터에 들어감
        words.push_back(input);
    }
    //만들어진 words 벡터들로 그래프 생성
    makeGraph(words);

    vector<int> to = topologicalSort();
    if(to.empty()) cout << "INVALID HYPOTHESIS\n";
    else{
        for(auto w : to){
            cout << char(w + 'a');
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t_case;
    cin >> t_case;
    for(int i = 0; i < t_case; i++){
        dic_test();
    }

    return 0;
}
