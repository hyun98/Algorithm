#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string canto(int n){

    if(n == 0) return "-";

    string head = canto(n-1);
    string mid(pow(3, n-1), ' ');
    string tail = canto(n-1);

    return head + mid + tail;
}

int main(){
    int n;
    while(true){
        cin >> n;
        if(cin.eof()) break;
        cout << canto(n) << "\n";
    }

    return 0;
}
