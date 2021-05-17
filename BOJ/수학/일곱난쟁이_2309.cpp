#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heights;
int sum = 0;

void input(){
    heights.resize(9);
    for(int i = 0; i < 9; i++){
        cin >> heights[i];
        sum += heights[i];
    }
    sort(heights.begin(), heights.end());
}

void printh_except(int e1, int e2){
    for(auto w : heights){
        if(w == e1 || w == e2) continue;
        cout << w << "\n";
    }
}

void solve(){
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 9; j++){
            if(sum - heights[i] - heights[j] == 100){
                printh_except(heights[i], heights[j]);
                return;
            }
        }
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
