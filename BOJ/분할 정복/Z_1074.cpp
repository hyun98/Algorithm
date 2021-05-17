#include <iostream>
#include <cmath>
using namespace std;

int N, r, c, result = 0;

void solve(int n, int row, int col){
    if(n == 0){
        return;
    }
    //1사분면
    if(row + n > r && col + n > c){
        solve(n/2, row, col);
    }
    //2사분면
    else if(row + n > r && col + n <= c){
        result = result + pow(n, 2);
        solve(n/2, row, col + n);
    }
    //3사분면
    else if(row + n <= r && col + n > c){
        result = result + 2*pow(n, 2);
        solve(n/2, row + n, col);
    }
    //4사분면
    else if(row + n <= r &&col + n <= c){
        result = result + 3*pow(n, 2);
        solve(n/2, row + n, col + n);
    }

}

int main(){
    cin >> N >> r >> c;
    solve(pow(2, N-1), 0, 0);
    cout << result << endl;

    return 0;
}
