#include <iostream>

using namespace std;

int result = 999999;
void solve(int n, int cnt){
    if(cnt > result) return;
    if(n == 1){
        if(cnt < result) result = cnt;
        return;
    }

    cnt++;
    if(n % 3 == 0) solve(n/3, cnt);
    if(n % 2 == 0) solve(n/2, cnt);
    solve(n-1, cnt);
}

int main(){
    int N;
    cin >> N;
    solve(N, 0);
    cout << result;
    return 0;
}
