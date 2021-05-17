#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> plus_order, minus_order;

void input(){
    cin >> N;
    int t;
    for(int i = 0; i < N; i++){
        cin >> t;
        if(t > 0) plus_order.push_back(t);
        else minus_order.push_back(t);
        
    }
    
    sort(plus_order.begin(), plus_order.end(), greater<>());
    sort(minus_order.begin(), minus_order.end());
}

void solve(){
    int lo, hi, result = 0;
    
    for(int i = 0; i < plus_order.size(); i++){
        if(i % 2 == 0){
            hi = plus_order[i];
            result += hi;
        }
        else{
            lo = plus_order[i];
            result -= hi;
            if(lo * hi > lo + hi) result += (lo*hi);
            else result += (lo + hi);
        }
    }
    
    for(int i = 0; i < minus_order.size(); i++){
        if(i % 2 == 0){
            hi = minus_order[i];
            result += hi;
        }
        else{
            lo = minus_order[i];
            result -= hi;
            if(lo * hi > lo + hi) result += (lo*hi);
            else result += (lo+hi);
        }
    }
    cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}
