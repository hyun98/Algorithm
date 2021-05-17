#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string bar;
    cin >> bar;
    stack<char> iron_bar;
    int result = 0;

    for (int i = 0; i < bar.size(); i++){ //������� ���ۺ��� ������
        if (bar[i] == '('){
            iron_bar.push(bar[i]);
        }
        else{   // ')'�� ������ �� �������� �ִ��� �������� ������ ����
            iron_bar.pop(); // ��� �߰��� ������ '(' ���Ҹ� ���� (������ ��ġ �߰�)
            if (bar[i-1] == '('){       //������ ���ٸ�
                result += iron_bar.size();  //����� �ڸ���
            }
            else{
                result++;       // �������� �ƴ϶� ������� ���̸� �߸��� ���� �ϳ� �߰�
            }

        }
    }
    cout << result;

    return 0;
}
