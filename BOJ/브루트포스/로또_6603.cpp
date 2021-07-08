#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> arr;
bool visited[15];

void dfs(int nowidx, int d, vector<int> &tmp){
    if(d == 6){
        for(int i = 0; i < 6; i++){
            cout << tmp[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = nowidx; i < K; i++){
        tmp.push_back(arr[i]);
        
        dfs(i+1, d+1, tmp);
        
        tmp.pop_back();
    }
    
}


int main(){
    int a;
    vector<int> tmp;
    cin >> K;
    while(K){
        for(int i = 0; i < K; i++){
            cin >> a;
            arr.push_back(a);
        }
        
        dfs(0, 0, tmp);
        cout << "\n";
        arr.clear();
        cin >> K;
    }
    
    return 0;
}