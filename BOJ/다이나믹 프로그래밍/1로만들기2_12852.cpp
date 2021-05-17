#include <bits/stdc++.h>

using namespace std;

int result = 999999;
vector<int> temp, ret;

void solve(int n, int cnt){
    if(cnt > result) return;
    if(n == 1){
        if(cnt < result){
            result = cnt;
            temp.push_back(n);
            ret = temp;
            temp.pop_back();
        }
        return;
    }

    temp.push_back(n);
    
    if(n % 3 == 0) solve(n/3, cnt+1);
    if(n % 2 == 0) solve(n/2, cnt+1);
    solve(n-1, cnt+1);
    
    temp.pop_back();
}

int main(){
    int N;
    cin >> N;
    solve(N, 0);
    cout << result << "\n";
    for(auto w : ret){
        cout << w << " ";
    }
    return 0;
}
