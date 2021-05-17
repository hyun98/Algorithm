#include <iostream>

using namespace std;

int N;
int fibo[46];

void find_fibo(){
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i <= N; i++){
        fibo[i] = fibo[i-2] + fibo[i-1];
    }
    cout << fibo[N];
}

int main(){
    cin >> N;
    find_fibo();
    
    return 0;
}
