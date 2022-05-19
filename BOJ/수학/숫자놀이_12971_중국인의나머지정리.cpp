#include <iostream>

using namespace std;

void solve(){
    int X1, X2, X3, M1, M2, M3, X;
    cin >> M1 >> M2 >> M3 >> X1 >> X2 >> X3;
    X = -1;
    
    for(int i = 1; i <= M1 * M2 * M3; i++){
        if((i % M1 == X1) && (i % M2 == X2) && (i % M3 == X3)){
            X = i;
            break;
        }
    }
    cout << X << '\n';
}

int main(){
    solve();
    cout << 2516 % 3 << '\n';
    cout << 2516 % 5 << '\n';
    cout << 2516 % 7 << '\n';
    
    return 0;
}
