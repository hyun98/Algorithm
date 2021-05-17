#include <iostream>
#include <cstring>
using namespace std;

class Morse{
    int N, M, k, skip, INF = 1000000001, bino[201][201];
    string result = "";
    
public:
    Morse(){
        cin >> N >> M >> k;
        skip = k-1;
        calcbino();
        generate3(N, M, result);
    }
    
    void calcbino(){
        memset(bino, 0, sizeof(bino));
        for(int i = 0; i <= 200; i++){
            bino[i][0] = bino[i][i] = 1;
            for(int j = 1; j < i; j++){
                bino[i][j] = min(INF, bino[i-1][j-1] + bino[i-1][j]);
            }
        }
    }
    
    void generate3(int n, int m, string s){
        if(skip < 0) return;
        
        if(n == 0 && m == 0){
            if(skip == 0) cout << s << endl;
            skip--;
            return;
        }
//        cout << skip << " " << "n : " << n << "  m : " << m << "  "<< bino[n+m][n] <<endl;
        if(bino[n+m][m] <= skip){
//            cout << "return?\n";
//            cout << skip << " " << bino[n+m][n] << endl;
            skip -= bino[n+m][n];
            return;
        }
        if(n > 0) generate3(n-1, m, s+"-");
        if(m > 0) generate3(n, m-1, s+"o");
    }
};

int main(){
    int test;
    cin >> test;
    while(test--){
        Morse M1;
    }
    return 0;
}
