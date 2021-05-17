#include <iostream>

using namespace std;

int memo[1001];

int DP(int x){
    if(x == 1) return 1;
    if(x == 2) return 2;
    if(memo[x] != 0) return memo[x];
    return memo[x] = (DP(x-1) +DP(x-2)) % 10007;
}

int main(){
    int n;
    cin >> n;
    cout << DP(n);
    return 0;
}
