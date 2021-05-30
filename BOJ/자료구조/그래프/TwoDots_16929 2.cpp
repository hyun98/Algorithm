#include <iostream>

using namespace std;

int N, M;
char Map[51][51];


void input(){
    string str;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            Map[i][j] = str[j];
        }
    }
}

int main(){

    return 0;
}
