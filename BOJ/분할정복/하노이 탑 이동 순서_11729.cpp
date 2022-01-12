#include <iostream>
#include <string>
using namespace std;

int N, cnt = 0;
string result = "";
// 장대 번호 a, b, c   옮겨야 할 원판의 개수 N
void hanoi(int a, int b, int c, int n){
    cnt++;
    
    if(n == 1) result += (to_string(a) + " " + to_string(c) + "\n");
    else{
        hanoi(a, c, b, n-1);
        result += (to_string(a) + " " + to_string(c) + "\n");
        hanoi(b, a, c, n-1);
    }
}

int main(){
    cin >> N;
    hanoi(1, 2, 3, N);
    cout << cnt << "\n";
    cout << result;
    return 0;
}
