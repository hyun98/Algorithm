#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define error cout<<"0"; return;

vector<char> arr;
string p;

void solve(){
    int temp = 1, result = 0;
    cin >> p;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == '('){
            temp *= 2;
            arr.push_back(p[i]);
        }
        else if(p[i] == '['){
            temp *= 3;
            arr.push_back(p[i]);
        }
        else if(p[i] == ')'){
            if(arr.size() == 0){
                error
            }
            if(arr.back() == '('){
                if(p[i-1] == '('){
                    result += temp;
                }
                temp /= 2;
                arr.pop_back();
            }
            else{
                error
            }
        }
        else if(p[i] == ']'){
            if(arr.size() == 0){
                error
            }
            if(arr.back() == '['){
                if(p[i-1] == '['){
                    result += temp;
                }
                temp /= 3;
                arr.pop_back();
            }
            else{
                error
            }
        }
    }
    if(arr.size() != 0){
        error
    }
    else{
        cout << result;
    }
}

int main(){
    solve();
    return 0;
}
