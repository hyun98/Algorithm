#include <iostream>
#include <string>

using namespace std;

bool pseudo(string& str, int lo, int hi){
    while(lo < hi){
        if(str[lo] == str[hi]){
            lo++;
            hi--;
        }
        else return false;
    }
    return true;
}

int palin_check(string& str, int lo, int hi){
    while(lo < hi){
        if(str[lo] == str[hi]){
            lo++;
            hi--;
        }
        else{
            if(pseudo(str, lo+1, hi) || pseudo(str, lo, hi-1)) return 1; 
            else return 2;
        }
    }
    return 0;
}

int main(){
    int N;
    string input_str;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> input_str;
        cout << palin_check(input_str, 0, input_str.size()-1) << "\n";
    }
    
    return 0;
}
