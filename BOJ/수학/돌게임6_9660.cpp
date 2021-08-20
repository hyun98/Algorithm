#include <iostream>

typedef long long ll;

using namespace std;

int main(){
    ll N;
    cin >> N;
    int rest = N % 7;
    if(rest == 2 || rest == 0) cout << "CY\n";
    else cout << "SK\n";
    
    return 0;
}
