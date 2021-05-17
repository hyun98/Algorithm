#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> dict1;
map<int, string> dict2;

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    string name, answer;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> name;
        dict1[name] = i;
        dict2[i] = name;
    }
    for(int i = 0; i < M; i++){
        cin >> answer;
        if(atoi(answer.c_str()) == 0){
            cout << dict1[answer] << "\n";
        }
        else{
            cout << dict2[atoi(answer.c_str())] <<"\n";
        }
    }

    return 0;
}
