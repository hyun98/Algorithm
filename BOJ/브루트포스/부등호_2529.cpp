#include <iostream>
#include <vector>

using namespace std;

int N, max_sum, min_sum = 10e9+7;
int Op[10];
bool visited[10];
vector<int> arr, result_max, result_min;

void solve(int now, int cnt){
    if(cnt == N){
        int sum = 0;
        for(auto &w : arr){
            sum += w;
        }
        if(sum >= max_sum){
            max_sum = sum;
            result_max = arr;
        }
        if(sum < min_sum){
            min_sum = sum;
            result_min = arr;
        }
        return;
    }
    
    visited[now] = true;
    
    for(int i = 0; i < 10; i++){
        if(visited[i]) continue;
        if(Op[cnt] == 1 && now < i){
            arr.push_back(i);
            solve(i, cnt+1);
            arr.pop_back();
        }
        else if(Op[cnt] == 0 && now > i){
            arr.push_back(i);
            solve(i, cnt+1);
            arr.pop_back();
        }
    }
    visited[now] = false;
}

int main(){
    cin >> N;
    string ch;
    for(int i = 0; i < N; i++){
        cin >> ch;
        if(ch == "<") Op[i] = 1;  // <
        else Op[i] = 0;           // >
    }
    
    for(int i = 0; i < 10; i++){
        arr.push_back(i);
        solve(i, 0);
        arr.pop_back();
    }
    
    for(auto &w : result_max){
        cout << w;
    }
    cout << "\n";
    for(auto &w : result_min){
        cout << w;
    }
    
    return 0;
}