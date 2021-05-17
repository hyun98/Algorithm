#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string bar;
    cin >> bar;
    stack<char> iron_bar;
    int result = 0;

    for (int i = 0; i < bar.size(); i++){ //막대기의 시작부터 끝까지
        if (bar[i] == '('){
            iron_bar.push(bar[i]);
        }
        else{   // ')'가 나왔을 때 레이저만 있는지 파이프의 끝인지 구분
            iron_bar.pop(); // 방금 추가한 스택의 '(' 원소를 삭제 (레이저 위치 발견)
            if (bar[i-1] == '('){       //레이저 였다면
                result += iron_bar.size();  //막대기 자르기
            }
            else{
                result++;       // 레이저가 아니라 막대기의 끝이면 잘리고 남은 하나 추가
            }

        }
    }
    cout << result;

    return 0;
}
