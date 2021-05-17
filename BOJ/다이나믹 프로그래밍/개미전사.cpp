#include <iostream>

using namespace std;


int N, supply[101], dp[101] = {0, };

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> supply[i];
    }
}


int bottom_up(){
    int d[101] = {0, };
    d[0] = supply[0];
    d[1] = max(supply[0], supply[1]);
    for(int i = 2; i < N; i++){
        d[i] = max(d[i-2] + supply[i], d[i-1]);
    }
    cout << d[N-1];
}



int top_down(int start){
    
    if(dp[start] != 0) return dp[start];
    dp[start] = supply[start];
    
    for(int i = start+2; i < N; i++){
        dp[start] = max(dp[start], supply[start] + solve(i));
    }
    
    return dp[start];
}

int main(){
    input();
    int res = 0;
    for(int i = 0; i < N; i++){
        res = max(res, top_down(i));
    }
    cout << res << endl;
    
    bottom_up();
    return 0;
}
