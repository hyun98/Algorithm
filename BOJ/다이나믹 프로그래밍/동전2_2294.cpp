#include <iostream>
#include <cstring>
using namespace std;

//1, 5, 12
//idx| 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15       동전의 가치의 합이 idx 일 때 사용한 동전의 개수
//----------------------------------------------------------
//dp | 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15       1 만 사용했을 때
//dp | 0  1  2  3  4  1  2  3  4  5  2   3   4   5   6   3        1, 5 만 사용했을 때
//dp | 0  1  2  3  4  1  2  3  4  5  2   3   1   2   3   4        1, 5, 12 를 모두 사용했을 때

const int INF = 100001;

int N, K;
int value[101], dp[100001];

void input(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> value[i];
    }
    
    for(int i = 0; i <= K; i++){
        dp[i] = INF;
    }
    dp[0] = 0;
}

//void print(){
//    for(int i = 1; i <= K; i++){
//        cout << dp[i] << " ";
//    }
//    cout << endl;
//}

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = value[i]; j <= K; j++){
            dp[j] = min(dp[j], dp[j - value[i]] + 1);
        }
//        print();
    }
    if(dp[K] == 100001) cout << -1;
    else cout << dp[K];
}


int main(){
    input();
    solve();
    
    return 0;
}
