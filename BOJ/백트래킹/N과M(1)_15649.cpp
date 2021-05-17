#include <iostream>
#include <vector>
using namespace std;

int N, M, visited[10];
vector<int> arr;

void dfs(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        // cout << endl; 로 하면 시간초과 난다 ㅡ,ㅡ
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            arr.push_back(i);
            visited[i] = 1;
            dfs(cnt+1);
            visited[i] = 0;
            arr.pop_back();
        }
    }
}

int main(){
    cin >> N >> M;
    dfs(0);
    
    return 0;
}
