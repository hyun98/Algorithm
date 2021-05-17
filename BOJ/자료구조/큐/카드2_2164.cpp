#include <iostream>
#include <queue>

using namespace std;

void card(int N){
    queue<int> card_bunch;
    int temp;

    if(N == 1){
        cout << 1;
        return;
    }

    for(int i = 1; i <= N; i++){
        card_bunch.push(i);

    }
    while(true){
        card_bunch.pop();
        temp = card_bunch.front();
        card_bunch.pop();
        card_bunch.push(temp);
        if(card_bunch.size() == 1){
            cout << card_bunch.front();
            return;
        }
    }

}

int main(){
    int N;
    cin >> N;
    card(N);

    return 0;
}
