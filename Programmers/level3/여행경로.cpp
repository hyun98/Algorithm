#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;
void DFS(string start, vector<string> &answer, vector<vector<string>> &tickets, vector<int> &used){
    if(cnt == tickets.size()+1){
        return;
    }
    
    for(int next = 0; next < tickets.size(); next++){
        if(start == tickets[next][0] && used[next] != 1){
            answer.push_back(start);
            cnt++;
            used[next] = 1;
            if(cnt == tickets.size()){
                cnt++;
                answer.push_back(tickets[next][1]);
            }
            DFS(tickets[next][1], answer, tickets, used);
            if(cnt < tickets.size()+1){
                answer.pop_back();
                used[next] = 0;
                cnt--;
            }
        }
    }
    
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<int> used (tickets.size()+1, 0);
    sort(tickets.begin(), tickets.end(), [](vector<string> a, vector<string> b) -> bool{return a[1] < b[1];});
    DFS("ICN", answer, tickets, used);

    return answer;
}