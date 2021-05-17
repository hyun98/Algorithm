#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n, m, Map[1001][1001], dp[1001][1001];

void input(){
    string arr;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr;
        for(int j = 0; j < m; j++){
            Map[i][j] = arr[j] - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
}

int square_check(int row, int col){
    int &ret = dp[row][col];
    if(ret != -1) return ret;
        
    if(Map[row][col] == 1){
        if(col+1 == m || row+1 == n) return ret = 1;
        
        int a = square_check(row+1, col);
        int b = square_check(row, col+1);
        int c = square_check(row+1, col+1);
        if(a > 0 && b > 0 && c > 0){
            if(a == 1 || b == 1 || c == 1) return ret = 4;
            
            else{
                int k;
                int temp = min(a, b);
                temp = min(temp, c);
                k = sqrt(temp) + 1;
                return ret = k*k;
            }
        }
        else return ret = 1;
    }
    else return ret = 0;
}

void solve(){
    int max_size = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            max_size = max(max_size, square_check(i, j));
        }
    }
    cout << max_size;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    
    return 0;
}
