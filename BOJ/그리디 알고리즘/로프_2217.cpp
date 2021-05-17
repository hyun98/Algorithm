#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> rope;

void solve(){
    cin >> N;
    rope.resize(N);
    for(int i = 0; i < N; i++){
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end());
    
    int result = 0;
    
    for(int i = 0; i < N; i++){
        result = max(result, (N-i) * rope[i]);
    }
    cout << result;
}

int main(){
    solve();
    
    return 0;
}