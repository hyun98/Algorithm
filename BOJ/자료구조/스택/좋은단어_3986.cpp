#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N, cnt = 0;
int main(){
    string str;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        stack<char> sleep;
        for(int i = 0; i < str.size(); i++){
            if(sleep.size() != 0){
                if(sleep.top() == str[i]){
                    sleep.pop();
                    continue;
                }
                sleep.push(str[i]);
            }
            else{
               sleep.push(str[i]);
            }
        }
        if(sleep.size() == 0){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
