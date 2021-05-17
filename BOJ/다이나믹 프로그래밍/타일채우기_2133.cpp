#include <iostream>

using namespace std;

int memo[1001] = {0, };

int DP(int x){
    if(x == 0) return 1;
    if(x % 2 == 1) return 0;
    if(x == 2) return 3;
    if(memo[x] != 0) return memo[x];
    
    int result = 3 * DP(x-2);
    for(int i = 4; i <= x; i++){
        if(i % 2 == 0){
            result += 2 * DP(x-i);
        }
    }
    return memo[x]  = result;
}

int main(){
    int n;
    cin >> n;
    cout << DP(n);
    return 0;
}
