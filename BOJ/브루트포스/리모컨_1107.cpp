#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool num[10] = {true, };
int M, channel, cnt;
string nearest = "";

void init(){
    cin >> channel >> M;
    int broke;
    for(int i = 0; i < M; i++){
        cin >> broke;
        num[broke] = false;
    }
    cnt = channel - 100;
}

int possible(int N){
    int len = 0;
    if(!num[N%10]) return 0;
    while(N){
        if(num[N%10]){
            len++;
        }
        N /= 10;
    }
 
    return len;
}


void solve(){
     for (int i = 0; i <= 1000000; i++){
        // i를 이루는 숫자 중 고장난 버튼이 없으면, 숫자길이 반환
        int len = possible(i);
        if (len){
            // 버튼 누르는 횟수가 더 작으면
            if (cnt > abs(channel - i) + len){
                cnt = abs(channel - i) + len;
            }
        }
    }
}

int main(){
    init();
    solve();
    cout << cnt;
    return 0;
}
