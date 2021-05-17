#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char>::iterator curser;
string str;
list<char> str_l;

void edit(int M){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char command, ch;
    curser = str_l.end();

    for(int i = 0; i < M; i++){
        cin >> command;
        if(command == 'P'){
            cin >> ch;
            curser = str_l.insert(curser, ch);
            curser++;
        }
        else if(command == 'L'){
            if(curser != str_l.begin()){
                curser--;
            }
        }
        else if(command == 'D'){
            if(curser != str_l.end()){
                curser++;
            }
        }
        else if(command == 'B'){
            if(curser != str_l.begin()){
                curser--;
                curser = str_l.erase(curser);
            }
        }
    }
    for(auto w :str_l){
        cout << w;
    }
    return;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    int M;
    cin >> str;
    for(auto w :str){
        str_l.push_back(w);
    }
    cin >> M;

    edit(M);

    return 0;
}
