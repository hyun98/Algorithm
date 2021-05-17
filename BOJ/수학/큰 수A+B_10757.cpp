#include <iostream>
#include <string>
using namespace std;

string solve(){
    
    string a, b, result = "";
    cin >> a >> b;
    
    if(a.length() > b.length()){
        while(a.length() != b.length()){
            b = '0' + b; 
        }
    }
    else{
        while(a.length() != b.length()){
            a = '0' + a; 
        }
    }
    
    int n, carry = 0;
    for(int i = a.length()-1; i >= 0; i--){
        n = (a[i]-'0' + b[i]-'0' + carry) % 10;
        carry = (a[i]-'0' + b[i]-'0' + carry) / 10;
        result = to_string(n) + result;
    }
    if(carry != 0){
        result = to_string(carry) + result;
    }
    return result;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solve();
	return 0;
}
