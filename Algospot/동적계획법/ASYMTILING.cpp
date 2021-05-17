#include <iostream>

#define MOD 1000000007
using namespace std;

class Asymtiling{
    int n, tile[101];
    
public:
    Asymtiling(){
        cin >> n;
    }
    
    void count_tile(){
        tile[1] = 1;
        tile[2] = 2;
        for(int i = 3; i <= n; i++){
            tile[i] = (tile[i-1] + tile[i-2]) % MOD;
        }
    }
    
    int count_Atile(){
        if(n == 1 || n == 2) return 0;
        if(n % 2 == 1) return (tile[n] - tile[n/2] + MOD) % MOD;
        int result = tile[n];
        result = (result - tile[n/2] + MOD) % MOD;
        result = (result - tile[n/2-1] + MOD) % MOD;
        return result;
    }
    
};

int main(){
    int test;
    cin >> test;
    while(test--){
        Asymtiling T;
        T.count_tile();
        cout << T.count_Atile() << endl;
    }
    return 0;
}
