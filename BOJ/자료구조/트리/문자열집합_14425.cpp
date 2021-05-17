#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M, cnt = 0;
vector<string> init, to_find;

void solve(){
    for(auto w : to_find){
        if(binary_search(init.begin(), init.end(), w)){
            cnt++;
        }
    }
    cout << cnt;
}

void input(){
    string in;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> in;
        init.push_back(in);
    }
    sort(init.begin(), init.end());
    for(int i = 0; i < M; i++){
        cin >> in;
        to_find.push_back(in);
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    return 0;
}
