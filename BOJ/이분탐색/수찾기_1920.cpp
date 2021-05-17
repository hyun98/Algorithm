#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, x, y;
    vector<int> num;
    num.reserve(100001);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end());

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> y;
        if(binary_search(num.begin(), num.end(), y)){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
    return 0;
}
