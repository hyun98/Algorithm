#include <iostream>
#include <unordered_map>
using namespace std;

int N, M, x;
unordered_map<int, int> card;

void solve(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        card[x]++;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> x;
        cout << card[x] <<" ";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
