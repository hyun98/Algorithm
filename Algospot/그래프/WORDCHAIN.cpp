#include <bits/stdc++.h>

using namespace std;

// i와 j 사이의 간선의 수
int N, adj[26][26];

// graph[i][j] = i로 시작해서 j로 끝나는 단어 목록
vector<string> graph[26][26];
vector<string> words;
vector<int> indegree, outdegree;
vector<int> Circuit;

void input(){
    words.clear();
    
    cin >> N;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        words.push_back(str);
    }
}

// 각 단어는 정점이 아니라 간선이 된다.
// 정점은 알파벳의 각 글자를 의미한다.
void makeGraph(){
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            graph[i][j].clear();
        }
    }
    memset(adj, 0, sizeof(adj));
    indegree = outdegree = vector<int>(26, 0);
    
    for(int i = 0; i < words.size(); i++){
        int a = words[i][0] - 'a';
        int b = words[i][words[i].size()-1] - 'a';
        graph[a][b].push_back(words[i]);
        adj[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
}

void getEulerCircuit(int now, vector<int> &circuit){
    for(int next = 0; next < 26; next++){
        while(adj[now][next] > 0){
            adj[now][next]--;
            getEulerCircuit(next, circuit);
        }
    }
    circuit.push_back(now);
}

vector<int> getEuler(){
    vector<int> circuit;
    
    // 트레일: 나가는 간선의 수가 들어오는 간선의 수 보다 하나 더 많아야 한다.
    // 우선 오일러 트레일을 찾아본다: 시작점이 존재하는경우
    for(int i = 0; i < 26; i++){
        if(outdegree[i] == indegree[i]+1){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    
    // 트레일이 아니라면 서킷이다.
    for(int i = 0; i < 26; i++){
        if(outdegree[i]){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    
    // 오일러 경로가 아니라면 빈 vector를 반환한다.
    return circuit;
}

bool checkEuler(){
    
    int plus1 = 0, minus1 = 0;
    for(int i = 0; i < 26; i++){
        int delta = outdegree[i] - indegree[i];
        
        // 모든 정점의 차수는 -1, 1, 0 이어야 한다.
        if(delta < -1 || delta > 1) return false;
        if(delta == 1) plus1++;
        if(delta == -1) minus1++;
    }
    
    // 트레일 시작점은 하나만 있거나 하나도 없어야한다. (하나도 없으면 오일러 서킷이다.)
    return ((plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0));
}

string solve(){
    makeGraph();
    
    // 오일러 경로가 아니라면 실패
    if(!checkEuler()) return "IMPOSSIBLE";
    
    // 오일러 서킷 or 트레일을 찾아낸다.
    vector<int> circuit = getEuler();
    
    // 모든 간선을 다 방문하지 못했으면 실패
    if(circuit.size() != words.size()+1) return "IMPOSSIBLE";
    
    // 오일러 서킷 or 트레일을 구하고 모든 간선을 포함하고 있다면
    reverse(circuit.begin(), circuit.end());
    string ret;
    for(int i = 0; i < circuit.size()-1; i++){
        int a = circuit[i], b = circuit[i+1];
        if(ret.size()) ret += " ";
        ret += graph[a][b].back();
        graph[a][b].pop_back();
    }
    return ret;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        input();
        string result = solve();
        cout << result << "\n";
    }
    
    return 0;
}