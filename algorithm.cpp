#include <iostream> 
using namespace std;
int main(){int K;cin >> K;int a = 1, b = 0;for(int i = 0; i < K; i++){int temp = a;a = b;b += temp;}cout << a << " " << b << '\n';return 0;}
