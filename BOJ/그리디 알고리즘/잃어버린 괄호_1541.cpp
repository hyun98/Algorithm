#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string cal, cache;
bool is_minus = false;
int result = 0;

inline int parse_si(string str){
    int k, res = 0;
    for(int i = 0; i < str.size(); i++){
        k = str[i] - '0';
        res += (pow(10, str.size()-1-i) * k);
    }
    return res;
}

inline void exint(){
    if(is_minus) result -= parse_si(cache);
    else result += parse_si(cache);
    cache = "";
}

void solve(){
    for(int i = 0; i < cal.size(); i++){
        if(cal[i] == '-'){
            exint();
            is_minus = true;
        }
        else if(cal[i] == '+') exint();
        else cache += cal[i];
    }
    exint();
    cout << result;
}

int main(){
    cin >> cal;
    solve();
    
    return 0;
}
