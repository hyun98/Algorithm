#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, K, temp;
    cin >> N >> K;
    queue<int> round;
    for(int i = 1; i <= N; i++){
        round.push(i);
    }
    cout << "<";
    while(1){
        for(int i = 1; i <= K; i++){
            if(i == K){
                cout << round.front();
                round.pop();
                break;
            }
            temp = round.front();
            round.pop();
            round.push(temp);
        }
        if(!round.size()){
            cout << ">";
            return 0;
        }
        cout << ", ";
    }
    return 0;
}
