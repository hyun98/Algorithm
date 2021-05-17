#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str, result = "";
stack<char> st;

int priority(char c){
    if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}

void process(){
    for(int i = 0; i < str.size(); i++){
        char now = str[i];
        
        if('A' <= now && now <= 'Z') result += now;
        else if(now == '(') st.push(now);
        else if(now == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop(); // '(' pop
        }
        else{
            while(!st.empty() && (priority(now) <= priority(st.top()))){
                result += st.top();
                st.pop();
            }
            st.push(now);
        }
    }
    
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    
    cout << result;
}

int main(){
    cin >> str;
    process();
    
    return 0;
}