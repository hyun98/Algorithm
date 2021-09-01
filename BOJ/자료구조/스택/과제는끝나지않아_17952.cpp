#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

int N, s, A, T, score;
vector<pii > arr;

int main(){
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> s;
        if(s){
            cin >> A >> T;
            arr.push_back({A, T});
        }
        if(arr.empty()) continue;
        if(--arr.back().second == 0){
            score += arr.back().first;
            arr.pop_back();
        }
    }
    
    cout << score;
    
    return 0;
}
