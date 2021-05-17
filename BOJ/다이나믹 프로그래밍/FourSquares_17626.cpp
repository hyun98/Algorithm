#include <iostream>
#include <cmath>
#define INF 1e9+7

using namespace std;

int N, arr[50001];

void sys_solve(){
    cin >> N;
    
    arr[1] = 1;

    for(int i = 2; i <= N; i++){
        int min_val = INF;
        for(int j = 1; j*j <= i; j++){
            int temp = i - j*j;
            min_val = min(min_val, arr[temp]);
        }
        arr[i] = min_val + 1;
    }
    cout << arr[N];
}

int main(){
    sys_solve();
    
    return 0;
}
