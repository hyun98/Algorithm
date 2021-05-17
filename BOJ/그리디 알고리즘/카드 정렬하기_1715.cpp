#include <iostream>
#include <queue>
using namespace std;

int N, result = 0;
priority_queue<int, vector<int>, greater<int> > card;

void input(){
    int in;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> in;
        card.push(in);
    }
}

void solve(){
    int p;
    int t = card.top();
    card.pop();
    while(!card.empty()){
        p = card.top();
        card.pop();
        result += (t + p);
        card.push(t + p);
        t = card.top();
        card.pop();
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    
    return 0;
}
