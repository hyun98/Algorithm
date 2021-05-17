#include <iostream>
#include <string>

using namespace std;

string name, result;

void solve(){
    result += name[0];
    
    for(int i = 1; i < name.size(); i++){
        if(name[i-1] == '-') result += name[i];
    }
    
    cout << result;
}

int main(){
    cin >> name;
    solve();
    
    return 0;
}
// Knuth-Morris-Pratt
