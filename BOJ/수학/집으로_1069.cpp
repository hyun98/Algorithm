#include <iostream>
#include <cmath>
#define INF 1e9+7
using namespace std;

double X, Y, T, D;

void solve(){
    double base = sqrt(X*X + Y*Y);
    
    double jumpcnt = 0, jumpdist = 0;
    while(jumpdist < base){
        jumpdist += D;
        jumpcnt++;
    }
    jumpcnt--;
    jumpdist -= D;
    
    double dt = (double)T;
    double res = INF;
    
    res = min(res, base);
    res = min(res, T*jumpcnt + (base - D*jumpcnt));
    res = min(res, T*(jumpcnt+1) + (D*(jumpcnt+1) - base));
    res = min(res, max(T*(jumpcnt+1), 2*T));
    
    printf("%.10lf\n", res);
}

int main(){
    cin >> X >> Y >> D >> T;
    solve();
    
    return 0;
}
