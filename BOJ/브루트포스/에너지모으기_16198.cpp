#include <iostream>
#include <vector>

using namespace std;

int N;
int res = 0, tres = 0;
vector<int> W;

void input(){
    cin >> N;
    W.resize(N);
    for(int i = 0; i < N; i++){
        cin >> W[i];
    }
}

void dfs(){
    if(W.size() == 2){
        res = max(res, tres);
        return;
    }
    
    for(int i = 1; i < W.size()-1; i++){
        int select = W[i];
        tres += (W[i-1] * W[i+1]);
        W.erase(W.begin() + i);
        dfs();
        W.insert(W.begin() + i, select);
        tres -= (W[i-1] * W[i+1]);
    }
}

int main(){
    input();
    dfs();
    cout << res;
    return 0;
}