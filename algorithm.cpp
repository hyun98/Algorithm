#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    if(a + b > b + a) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> snums;
    for(auto w: numbers){
        snums.push_back(to_string(w));
        cout << to_string(w) << '\n';
    }
    
    sort(snums.begin(), snums.end(), cmp);
    for(auto w: snums){
        answer += w;
    }
    
    return answer;
}

int main(){
    vector<int> ss {3, 30, 34, 5, 9};
    string a = solution(ss);
    cout << a;
    return 0;
}