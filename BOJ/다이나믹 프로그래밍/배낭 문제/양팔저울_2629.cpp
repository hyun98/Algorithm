#include <iostream>

using namespace std;

int N, T;
int chu[31], gram[10];
bool dp[31][40501];

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> chu[i];
    }
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> gram[i];
    }
}

void init_DP(){
    for(int i = 1; i <= 40500; i++){
        if(chu[1] == i) dp[1][i] = true;
        else dp[1][i] = false;
    }
    
    for(int i = 2; i <= N; i++){
        
        for(int j = 1; j <= 40500; j++){
            if(dp[i-1][j]){
                dp[i][j] = true;
                continue;
            }
            if(dp[i-1][chu[i] + j]){
                dp[i][j] = true;
                continue;
            }
            
            if(chu[i] == j) dp[i][j] = true;
            else if(chu[i] > j) dp[i][j] = dp[i-1][chu[i]-j];
            else dp[i][j] = dp[i-1][j - chu[i]];
        }
    }
    
    for(int i = 0; i < T; i++){
        cout << (dp[N][gram[i]] ? "Y" : "N") << " ";
    }
    
}

int main(){
    input();
    init_DP();
    
    return 0;
}
