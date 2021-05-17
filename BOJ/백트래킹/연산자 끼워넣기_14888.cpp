#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Oper[4], caltime = 0;
int MIN = 1000000000, MAX = -1000000000;
bool visited[10] = {false, };
vector<int> arr;
vector<char> _stack;

int cal(){
    int ans = arr[0];
    for(int i = 0; i < _stack.size(); i++){
        char op = _stack[i];
        switch (op){
            case '+': ans += arr[i+1]; break;
            case '-': ans -= arr[i+1]; break;
            case '*': ans *= arr[i+1]; break;
            case '/': ans /= arr[i+1]; break;
            default: break;
        }
    }
    return ans;
}

void dfs(int now){
//    caltime++;
    if(now == N-1){
        int a = cal();
        if(a > MAX) MAX = a;
        if(a < MIN) MIN = a;
    }
    
    if(!visited[now]){
        visited[now] = true;
        for(int j = 0; j < 4; j++){
            if(Oper[j] == 0) continue;
            else{
                Oper[j]--;
                if(j == 0) _stack.push_back('+');
                else if(j == 1) _stack.push_back('-');
                else if(j == 2) _stack.push_back('*');
                else _stack.push_back('/');
            }
            dfs(now+1);
            Oper[j]++;
            _stack.pop_back();
        }
    }
    visited[now] = false;
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
//    cout <<"\ncaltime : " << caltime;
    return 0;
}
