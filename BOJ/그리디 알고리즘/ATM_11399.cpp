#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, in;
    cin >> N;
    vector<int> order;
    
    for(int i = 0; i < N; i++){
        cin >> in;
        order.push_back(in);
    }
    sort(order.begin(), order.end());
    
    int result = 0, temp = 0, before = 0;
    for(int i = 0; i < N; i++){
        temp += order[i];
        result += temp;
    }
    cout << result;
    return 0;
}
