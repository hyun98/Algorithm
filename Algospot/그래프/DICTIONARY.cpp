//��������(Topological Sort)
//DFS�� �����..
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > adj;

//�׷��� ���� ���� :
void makeGraph(const vector<string>& words){
    //���ĺ��� ���� 26���̹Ƿ� ��������� ����ص� �޸𸮿� ū ������ �����ʴ´�
    adj = vector<vector<int>> (26, vector<int> (26, 0));

    for(int i = 0; i < words.size() - 1; i++){
        // ù ��° �ܾ���� ������ �ܾ���� 2���� ��
        int len = min(words[i].size(), words[i+1].size());
        // ���� �ܾ�� �����Ƿ� �� ª�� �ܾ �������� ������ġ�� �ִ� ���ĺ��� ���� ���Ѵ�
        for(int k = 0; k < len; k++){
            // i ��° �ܾ�� �� ���� �ܾ��� k��°(���� ��ġ��) ���ĺ� �� -> ���� �ٸ��� i��° �ܾ��� k��° ���ĺ��� ������ ��������
            if(words[i][k] != words[i+1][k]){
                int a = words[i][k] - 'a';
                int b = words[i+1][k] - 'a';

                adj[a][b] = 1;  //a��° ���� ���ĺ� ������ b��° ���ĺ��� �´ٴ� ��.
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

    //���� �湮���� ���� ���ĺ� ���� dfs�� �ݺ������� ����
    for(int i = 0; i < adj.size(); i++){
        if(!visited[i]) dfs(i);
    }
    reverse(order.begin(), order.end());

    for(int i = 0; i < adj.size(); i++){
        for(int j = i+1; j < adj.size(); j++){
            //order���� �� ���ĺ��� �� ���ĺ� ���� �ռ��ٴ� ����(adj[��][��] == 1)�� ������ fail
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
        // �ܾ���� �Էµǰ� words��� ���Ϳ� ��
        words.push_back(input);
    }
    //������� words ���͵�� �׷��� ����
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
