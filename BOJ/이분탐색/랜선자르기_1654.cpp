#include <iostream>
#include <vector>
using namespace std;

int N, K;
long long sum = 0;
vector<int> lancable;

void input(){
    int in;
    cin >> K >> N;
    for(int i = 0; i < K; i++){
        cin >> in;
        lancable.push_back(in);
        sum += in;
    }
}

bool cutting(long long mid){
    int lan_num = 0;
    for(int i = 0; i < K; i++){
        lan_num += (lancable[i] / mid);
    }
    if(lan_num >= N) return true;
    else return false;
}

void solve(){
    long long result = 0;
    long long lo = 1, hi = sum/N + 1;
    
    while(lo <= hi){
        long long mid = (lo+hi)/2;
        if(mid == lo){
            cout << lo;
            return;
        }
        if(cutting(mid)){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
