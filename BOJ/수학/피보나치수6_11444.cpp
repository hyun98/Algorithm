#include <iostream>

using namespace std;

const long long MOD = 1000000007;
long long N;

struct Mat{
    long long m[2][2];
};
Mat basic;

Mat MatMul(Mat a, Mat b){
    Mat res;
    res.m[0][0] = (a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % MOD;
    res.m[0][1] = (a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % MOD;
    res.m[1][0] = (a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % MOD;
    res.m[1][1] = (a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % MOD;
    return res;
}

Mat fibo(long long n){
    if(n == 1) return basic;
    
    Mat res, temp;
    temp = fibo(n/2);
    if(n % 2 == 1){
        res = MatMul(temp, temp);
        res = MatMul(res, basic);
    }
    else{
        res = MatMul(temp, temp);
    }
    
    return res;
}

int main(){
    cin >> N;
    basic.m[0][0] = 1; basic.m[0][1] = 1;
    basic.m[1][0] = 1; basic.m[1][1] = 0;
    Mat res;
    res = fibo(N);
    cout << res.m[0][1];
    return 0;
}