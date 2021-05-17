#include <iostream>
#include <vector>
using namespace std;

// 1���� N������ �� �� M���� �̴� ���
int N, M;
vector<int> _stack;

void dfs(){
    if(_stack.size() == M){
        for(int i = 0; i < M; i++){
            cout << _stack[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        if(_stack.empty()){
            _stack.push_back(i);
            dfs();
            _stack.pop_back();
        }
        else if(_stack.back() <= i){
            _stack.push_back(i);
            dfs();
            _stack.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    dfs();
    return 0;
}
