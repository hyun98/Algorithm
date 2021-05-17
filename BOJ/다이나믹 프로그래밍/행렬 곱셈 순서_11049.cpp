#include <iostream>
#include <cstring>
using namespace std;

const int INF = 999999999;

struct P{
    int row, col;
};

int N;
P Matrix[501];
// dp[1][N] : 1ºÎÅÍ N±îÁö ¹­Àº È½¼ö
int dp[501][501];

inline void input(){
    int r, c;
    cin >> N;
    for(int i = 1; i <= N; i++){
        P temp;
        cin >> temp.row >> temp.col;
        Matrix[i] = temp;
    }
    memset(dp, 0, sizeof(dp));
}

void Merge(){
    for(int d = 1; d < N; d++){
        for(int st = 1; st+d <= N; st++){
            int ed = st + d;
            dp[st][ed] = INF;
            for(int mid = st; mid < ed; mid++){
                dp[st][ed] = min(dp[st][ed], dp[st][mid] + dp[mid+1][ed] + Matrix[st].row * Matrix[mid].col * Matrix[ed].col);
                
//                cout << "start , ed : " << st << " " << ed << endl;
//                cout << "dp[" << st << "][" << ed << "] : " << dp[st][ed] << endl;
            }
        }
    }
    
    cout << dp[1][N] << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    Merge();
    
    return 0;
}
