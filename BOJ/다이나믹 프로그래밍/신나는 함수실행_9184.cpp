#include <iostream>
#include <cstring>
using namespace std;

int A, B, C;
int dp[21][21][21];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }   
    if(a > 20 || b > 20 || c > 20){
        return w(20, 20, 20);
    }
    
    int &ret = dp[a][b][c];
    if(ret != -1) return ret;
    
    if(a < b && b < c){
        ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else{
        ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    return ret;
}

void input(){
    memset(dp, -1, sizeof(dp));
    while(true){
        cin >> A >> B >> C;
        if(A == -1 && B == -1 && C == -1) return;
        else cout << "w(" << A << ", " << B << ", " << C << ") = "<< w(A, B, C) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    return 0;
}
