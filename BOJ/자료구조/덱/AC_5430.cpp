#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> arr;
string command;

void solve(int i){
    int cnt = 0;
    for(auto w : command){
        if(w == 'R'){
            cnt++;
        }
        else if(w == 'D'){
            if(arr.size() == 0){
                cout <<"error\n";
                return;
            }
            if(cnt % 2 == 1){
                arr.pop_back();
            }
            else{
                arr.pop_front();
            }
        }
    }
    cout << "[";
    if(cnt % 2 == 1){
        reverse(arr.begin(), arr.end());
        for(auto w : arr){
            cout << w;
            arr.pop_back();
            if(arr.size() != 0){
                cout << ",";
            }
        }
    }
    else{
        for(auto w : arr){
            cout << w;
            arr.pop_back();
            if(arr.size() != 0){
                cout << ",";
            }
        }
    }
    cout << "]\n";

    command.clear();
    arr.clear();

}   //end of solve

void input(int T){
    for(int i = 0; i < T; i++){
        int n, num;
        char c;
        cin >> command;
        scanf("%d", &n);
        getchar();
        if(n != 0){
            for(int j = 0; j < n; j++){
                scanf("%c%d", &c, &num);
                arr.push_back(num);
            }
            scanf("%c", &c);
            solve(i);
        }
        else{
            scanf("%c%c", &c, &c);
            solve(i);
        }
        getchar();
    }
}   //end if input

int main(){
    int T;
    cin >> T;
    input(T);
    return 0;
}
