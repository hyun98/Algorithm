#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;


// char kakao[9] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
int visited[9];

void map_insert(map<char, int> &m){
    m.insert({'A', 0});
    m.insert({'C', 1});
    m.insert({'F', 2});
    m.insert({'J', 3});
    m.insert({'M', 4});
    m.insert({'N', 5});
    m.insert({'R', 6});
    m.insert({'T', 7});
}

bool is_valid(vector<string> &data, map<char, int> &m){
    for(int i = 0; i < data.size(); i++){
        int target1 = visited[m[data[i][0]]];
        int target2 = visited[m[data[i][2]]];
        char op = data[i][3];
        int xop = data[i][4] - '0';
        
        if(op == '='){
            if(abs(target1 - target2) == xop + 1) continue;
            else return false;
        }
        else if(op == '>'){
            if(abs(target1 - target2) > xop + 1) continue;
            else return false;
        }
        else if(op == '<'){
            if(abs(target1 - target2) < xop + 1) continue;
            else return false;
        }
    }
    
    return true;
}

void sorting(int cnt, int &answer, vector<string> &data, map<char, int> &m){
    if(cnt == 8){
        if(is_valid(data, m)){
            answer++;
        }
        return;
    }
    
    for(int i = 0; i < 8; i++){
        if(visited[i]) continue;
        visited[i] = cnt+1;
        sorting(cnt+1, answer, data, m);
        visited[i] = 0;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    memset(visited, 0, sizeof(visited));
    int answer = 0;
    map<char, int> m;
    map_insert(m);
    
    sorting(0, answer, data, m);
    
    return answer;
}

int main(int argc, const char** argv) {
    int N = 2;
    vector<string> data;
    data.push_back("N~F=0");
    data.push_back("R~T>2");
    // data.push_back("M~C<2");
    // data.push_back("C~M>1");
    cout << solution(N, data);
    return 0;
}

