#include <iostream>
#include <queue>    //선입선출
using namespace std;

void solve(int N, int K){
    int temp;
    queue<int> round;
    for (int i = 1; i <= N; i++){
        round.push(i);
    }

    cout << "<";
    while(true){
        for(int i = 0; i < K - 1; i++){
            temp = round.front();
            round.pop();
            round.push(temp);
        }
        cout << round.front();
        round.pop();
        if(round.size() == 0){
            cout << ">";
            return;
        }
        else{
            cout << ", ";
        }
    }
}

int main(){
    int N, K;
    cin >> N >> K;  //K <= N
    solve(N, K);
    return 0;
}
