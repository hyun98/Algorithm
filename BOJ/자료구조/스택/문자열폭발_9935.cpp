#include <iostream>
#include <string>
using namespace std;

string str, boom;
char result[1000001];

void solve(){
    int now = 0;
    for(int i = 0; i < str.length(); i++){

        result[now++] = str[i];
        if(result[now - 1] == boom[boom.length()-1]){

            if(now < boom.length()){
                continue;
            }

            bool bomb_find = true;
            for(int j = 0; j < boom.length(); j++){
                if(result[now - 1 - j] != boom[boom.length() - 1 - j]){
                    bomb_find = false;
                    break;
                }
            }
            if(bomb_find){
                now -= boom.length();
            }
        }
    }

    if(now){
        for(int i = 0; i < now; i++){
            cout <<result[i];
        }
    }
    else{
        cout << "FRULA";
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    cin >> boom;
    solve();
    return 0;
}
