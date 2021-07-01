#include <iostream>


using namespace std;

int N, P;
int Cost[17][17];
int onNoff;

int dp[17][1 << 16 + 1];

void input(){
    cin >> N;
    int c;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> c;
            Cost[i][j] = c;
        }
    }
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'Y') onNoff |= (1 << i);
    }
    cin >> P;
}

int On_num(int x){
    int cnt = 0;
    for(int i = 0; i < 16; i++){
        int offset = (1 << i);
        
        if(x & offset) cnt++;
    }
    return cnt;
}

void solve(){
    for(int i = 0; i < N; i++){
        // 이미 켜져있는 경우 넘어감
        if(onNoff & (1 << i)) continue;
        
        for(int k = 0; k < (1 << 16); k++){
            dp[i][]
        }
    }
}


int main(){
    input();
    
    return 0;
}