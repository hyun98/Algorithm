#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> numbers, psum;

void input(){
    cin >> N >> S;
    numbers.resize(N+1, 0);
    psum.resize(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> numbers[i];
    }
    
    psum[1] = numbers[1];
    for(int i = 2; i <= N; i++){
        psum[i] = numbers[i] + psum[i-1];
    }
}

void solve(){
    int st = 0, result = 100001;
    for(int ed = 1; ed <= N; ed++){
        if(psum[ed] - psum[st] >= S){
            while(st < ed){
                if(psum[ed] - psum[st] < S) break;
                result = min(result, ed-st);
                st++;
            }
        }
    }
    if(result == 100001) cout << 0;
    else cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}
