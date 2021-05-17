#include <iostream>

using namespace std;

long long A, B, result = 1e9+7;

void DFS(long long now, long long cnt){
    if(now == B){
        result = min(result, cnt);
        return;
    }
    if(now > B) return;
    
    DFS(now*2, cnt+1);
    DFS(now*10+1, cnt+1);
}

int main(){
    cin >> A >> B;
    DFS(A, 0);
    if(result == 1e9+7) cout << -1;
    else cout << result+1;
    
    return 0;
}