#include <iostream>

using namespace std;

// num에 대한 분해합을 반환하는 함수
inline int decompose_sum(int num){
    int be = num;
    int sum = 0;
    // num이 0이 될 때까지 10으로 나눔
    while(be){
        sum += (be % 10);
        be /= 10;
    }
    return sum + num;
}

int main(){
    int N;
    cin >> N;
    // N의 생성자가 N보다 클 수는 없으므로 N 까지 반복
    for(int i = 1; i <= N; i++){
        // i의 분해합이 N과 같으면 i를 출력하고 반복문 종료
        if(N == decompose_sum(i)){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    
    return 0;
}
