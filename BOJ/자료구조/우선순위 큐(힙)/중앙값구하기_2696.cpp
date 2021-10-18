#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;


void solve(){
    int M = 0, middle, a;
    priority_queue<int, vector<int>, greater<int> > minheap;
    priority_queue<int> maxheap;
    vector<int> ans;
    
    cin >> M;
    cin >> middle;
    ans.push_back(middle);
    
    for(int i = 2; i <= M; i++){
        cin >> a;
        if(a > middle)  minheap.push(a);
        else            maxheap.push(a);
        
        if(i % 2 == 0) continue;
        else if(minheap.size() < maxheap.size()){
            minheap.push(middle);
            middle = maxheap.top();
            maxheap.pop();
            ans.push_back(middle);
        }
        else if(maxheap.size() < minheap.size()){
            maxheap.push(middle);
            middle = minheap.top();
            minheap.pop();
            ans.push_back(middle);
        }
        else ans.push_back(middle);
    }
    
    cout << M/2 + 1 << "\n";
    for(int i = 0; i < ans.size(); i++){
        if(i % 10 == 0 && i != 0){
            cout << "\n";
        }
        cout << ans[i] << " ";
    }
}


int main(){
    fastio
    int T;
    cin >> T;
    while(T--){
        solve();
        cout << "\n";
    }
    return 0;
}
