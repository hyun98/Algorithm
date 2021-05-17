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
        // i�� �̷�� ���� �� ���峭 ��ư�� ������, ���ڱ��� ��ȯ
        int len = possible(i);
        if (len){
            // ��ư ������ Ƚ���� �� ������
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
