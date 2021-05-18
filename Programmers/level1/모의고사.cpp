#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int right[3] = {0, 0, 0};
    int one[5] = {1, 2, 3, 4, 5};
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int p1=0, p2=0, p3=0;
    for(int i = 0; i < answers.size(); i++){
        if(one[p1] == answers[i]) right[0]++;
        if(two[p2] == answers[i]) right[1]++;
        if(three[p3] == answers[i]) right[2]++;
        
        p1++;
        p2++;
        p3++;
        if(p1 == 5) p1 = 0;
        if(p2 == 8) p2 = 0;
        if(p3 == 10) p3 = 0;
    }
    
    int max_val = 0;
    for(int i = 0; i < 3; i++){
        if(right[i] > max_val){
            answer.clear();
            answer.push_back(i+1);
            max_val = right[i];
        }
        else if(right[i] == max_val){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}