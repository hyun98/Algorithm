#include <iostream>
#include <string>
#include <list>
using namespace std;

void find_pw(string pw){
    list<char> result;
    list<char>::iterator cursor = result.begin();

    for(int i = 0; i < pw.length(); i++){
        if(pw[i] == '<'){
            if(cursor == result.begin()){
                continue;
            }
            else{
                cursor--;
            }
        }

        else if(pw[i] == '>'){
            if(cursor == result.end()){
                continue;
            }
            else{
                cursor++;
            }
        }

        else if(pw[i] == '-'){
            if(cursor == result.begin()){
                continue;
            }
            cursor--;
            cursor = result.erase(cursor);
        }

        else{
            result.insert(cursor, pw[i]);
        }
    }

    for(auto itr = result.begin(); itr != result.end(); itr++){
        cout << *itr;
    }
    cout << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    string pw;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> pw;
        find_pw(pw);
    }
    return 0;
}
