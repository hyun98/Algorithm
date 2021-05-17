#include <iostream>
#include <string>
using namespace std;

const int MOD = 1234567891;

int main(void){
    int N;
    string str;
    cin >> N;
    cin >> str;
    long long result = 0;
    long long r = 1;
    
    for(int i = 0; i < N; i++){
        result = (result + (str[i] - 'a' + 1) * r) % MOD;
        r = (r * 31) % MOD;
    }
    cout << result << "\n";
    return 0;
}

//#include <iostream> 
//#include <string> 
//using namespace std; 
//const int MOD = 1234567891;
//
//int main(void) { 
//    int L; 
//    cin >> L;
//    string s;
//    cin >> s;
//    long long sum = 0; 
//    long long R = 1; 
//    for (int i = 0; i < L; i++) { 
//        sum = (sum + (s[i] - 'a' + 1) * R) % MOD; 
//        R = (R*31) % MOD; 
//    } 
//    cout << sum << "\n"; 
//    return 0; 
//}

