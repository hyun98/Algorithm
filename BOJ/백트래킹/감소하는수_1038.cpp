#include <iostream>

using namespace std;

int N, res;

void desc_number(int n, int now, int len){
    if(n == N){
        res = now;
        exit(0);
    }
    
    string test;
    test = now + '0';
    if(len > 10){
        res = -1;
        exit(0);
    }
    
    for(int i = 0; i < len-1; i++){
        int lo = i;
        int hi = i+1;
        
        
    }
    
}

int main(){
    cin >> N;
    desc_number(0, 0, 1);
    return 0;
}
