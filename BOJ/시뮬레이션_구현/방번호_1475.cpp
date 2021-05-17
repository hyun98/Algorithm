#include <iostream>
#include <string>
#include <map>

using namespace std;
string num;
map<int, int> hashed_num;

void input(){
    cin >> num;
    for(int i = 0; i < 9; i++){
        hashed_num[i] = 0;
    }
}

void solve(){
    for(int i = 0; i < num.size(); i++){
        int now = num[i] - '0';
        
        if(now == 9) hashed_num[6]++;
        else hashed_num[now]++;
    }
    // 세트 개수를 저장하는 변수 
    int result = 0;
    for(int i = 0; i < 9; i++){
        if(i == 6){
            if(hashed_num[i]%2 == 1) result = max(result, hashed_num[i]/2 + 1);
            else result = max(result, hashed_num[i]/2);
        }
        else result = max(result, hashed_num[i]);
    }
    
    cout << result;
}

int main(){
    input();
    solve();

    return 0;
}
