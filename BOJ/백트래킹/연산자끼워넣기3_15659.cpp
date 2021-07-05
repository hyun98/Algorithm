#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, Oper[4]; // 덧셈, 뺄셈, 곱셈, 나눗셈
int MIN = 1000000001, MAX = -1000000001;
vector<int> arr;
vector<char> _stack;

int cal(){
    vector<int> tarr = arr;
    vector<int> temparr;
    vector<char> tempop;
    int temp = 0;
    
    int i;
    for(i = 0; i < _stack.size(); i++){
        if(_stack[i] == '*'){
            temp = tarr[i] * tarr[i+1];
            tarr[i+1] = temp;
        }
        else if(_stack[i] == '/'){
            temp = tarr[i] / tarr[i+1];
            tarr[i+1] = temp;
        }
        else{
            temparr.push_back(tarr[i]);
            tempop.push_back(_stack[i]);
        }
    }
    temparr.push_back(tarr[i]);
    
    int ans = temparr[0];
    
    // for(int k = 0; k < temparr.size(); k++){
    //     cout << temparr[k] << " ";
    // }
    // cout << "\n";
    // for(int k = 0; k < tempop.size(); k++){
    //     cout << tempop[k] << " ";
    // }
    // cout << "\n";
    for(int j = 0; j < tempop.size(); j++){
        char op = tempop[j];
        switch (op){
            case '+': ans += temparr[j+1]; break;
            case '-': ans -= temparr[j+1]; break;
            default: break;
        }
    }
    
    return ans;
}

void dfs(int now){
    
    if(now == N-1){
        int a = cal();
        MAX = max(MAX, a);
        MIN = min(MIN, a);
    }
    
    for(int j = 0; j < 4; j++){
        if(Oper[j] == 0) continue;
        
        Oper[j]--;
        if     (j == 0) _stack.push_back('+');
        else if(j == 1) _stack.push_back('-');
        else if(j == 2) _stack.push_back('*');
        else if(j == 3) _stack.push_back('/');
        
        dfs(now+1);
        
        _stack.pop_back();
        Oper[j]++;
    }
}

void input(){
    int a;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
    }
    for(int i = 0; i < 4; i++){
        cin >> Oper[i];
    }
}

int main(){
    input();
    dfs(0);
    cout << MAX << "\n" << MIN;
    
    return 0;
}
