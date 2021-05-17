#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> paren;

void solve(string P){
    vector<char> _stack;
    for(int i = 0; i < P.length(); i++){
        if(P[i] == '('){
            _stack.push_back('(');
        }
        else{
            if(_stack.size() == 0){
                cout <<"NO\n";
                return;
            }
            if(_stack.back() == '('){
                _stack.pop_back();
            }
        }
    }

    if(_stack.size() == 0){
        cout << "YES\n";
    }
    else{
        cout <<"NO\n";
    }
}

void input(){
    int N;
    string P;
    cin >> N;
    for(int i = 0 ;i < N; i++){
        cin >> P;
        solve(P);
    }
}

int main(){
    input();
    return 0;
}
