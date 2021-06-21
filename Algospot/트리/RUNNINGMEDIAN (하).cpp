#include <iostream>
#include <vector>

using namespace std;
struct RNG{
    int seed, a, b;
    RN(int _a, _b) : a(_a), b(_b), seed(1983){}
    int next(){
        int ret = seed;
        seed = ((seed * (long long)a) + b) % 20090711;
        return ret;
    }
};
int N, a, b;
int input[200001];

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> a >> b;
    }
    return 0;
}
