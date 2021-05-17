#include <iostream>

using namespace std;

int N, cnt = 0;
int arr[51];


void test(int a, int b){
    for(int i = 0; i < N-1; i++){
        if(arr[i] * a + b != arr[i+1]) return;
    }
    cnt = 1;
}

// 모든 점이 한 직선위에 있음!!
void make_ab(){
    int a = 0, b = 0, x, y;
    
    x = arr[1] - arr[0];
    y = arr[2] - arr[1];
    if(x != 0) a = y / x;
    b = arr[1] - arr[0] * a;
    
    test(a, b);
    
    if(cnt) cout << arr[N-1] * a + b;
    else cout << 'B';
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    if(N == 1) cout << 'A';
    else if(N == 2){
        if(arr[1] == arr[0]) cout << arr[0];
        else cout << 'A';
    }
    else make_ab();
    
    return 0;
}
