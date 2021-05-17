#include <iostream>
#include <queue>
using namespace std;

int x, N;
priority_queue< int, vector<int>, greater<int> > Heap;
void solve(){
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x > 0) Heap.push(x);
        else{
            if(Heap.empty()) cout << "0\n";
            else{
                cout << Heap.top() << "\n";
                Heap.pop();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    solve();
    return 0;
}
