#include <iostream>

using namespace std;

long long N;

int main(){
    cin >> N;
    if(N % 5 == 0 || N % 5 == 2){
        cout << "CY";
    }
    else cout << "SK";
    return 0;
}
