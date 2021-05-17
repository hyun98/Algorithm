#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<char> output;
vector<int> num, inp;
stack<int> _stack;
int a, n;

void solve(){
    int id = 0;
    while(true){
        if(num.size() == 0 && _stack.size() == 0){
            for(auto w : output){
                cout << w << "\n";
            }
            return;
        }
        if(_stack.size() == 0){
            _stack.push(num.front());
            output.push_back('+');
            num.erase(num.begin());
        }
        else{
            if(_stack.top() == inp[id]){
                _stack.pop();
                output.push_back('-');
                id++;
            }
            else{
                if(num.size() == 0){
                    cout << "NO";
                    return;
                }
                _stack.push(num.front());
                output.push_back('+');
                num.erase(num.begin());
            }
        }
    }
}

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        num.push_back(i);
        cin >> a;
        inp.push_back(a);
    }
}

int main(){
    input();
    solve();
    return 0;
}
