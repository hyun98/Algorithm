#include <iostream>
#include <algorithm>
#include <vector>

#define pii pair<int, int>

using namespace std;

int N, cnt, resnum;
int arr[1000001];

vector<int> temparr, stk;
pii check[1000001];


void solve(){
    temparr.push_back(arr[0]);
    check[0] = {arr[0], 0};
    
    for(int i = 1; i < N; i++){
        if(temparr.back() < arr[i]){
            temparr.push_back(arr[i]);
            cnt++;
            
            check[i] = {arr[i], cnt};
        }
        else{
            int lbidx = lower_bound(temparr.begin(), temparr.end(), arr[i]) - temparr.begin();
            temparr[lbidx] = arr[i];
            
            check[i] = {arr[i], lbidx};
        }
    }
    
    cout << cnt + 1 << "\n";
    
    for(int i = N-1; i >= 0; i--){
        if(cnt == check[i].second){
            stk.push_back(check[i].first);
            cnt--;
        }
    }
    
    for(int i = stk.size()-1; i >= 0; i--){
        cout << stk[i] << " ";
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    solve();
    
    return 0;
}
