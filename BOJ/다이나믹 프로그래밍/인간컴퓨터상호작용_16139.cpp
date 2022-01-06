#include <iostream>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

string S;
int Q;
int psum[200001][26];

void init(){
    for(int i = 1; i <= S.size(); i++){
        char now = S[i-1];
        for(int j = 0; j < 26; j++){
            if(now - 'a' == j) psum[i][j] = psum[i-1][j] + 1;
            else psum[i][j] = psum[i-1][j];
        }
    }
}

int main(){
    fastio
    cin >> S >> Q;
    init();
    int l, r;
    char c;
    for(int i = 0; i < Q; i++){
        cin >> c >> l >> r;
        cout << psum[r+1][c-'a'] - psum[l][c-'a'] << "\n";
    }
    
    return 0;
}
