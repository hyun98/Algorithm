#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N;
string form;
int bracketOpen[22]; // 1은 open, -1은 close
int answer = -pow(2, 31);

void input(){
    cin >> N;
    cin >> form;
}

int calc(int p, int q, char op){
    int ret;
    
    switch (op){
        case '+': ret = p + q; break;
        case '*': ret = p * q; break;
        case '-': ret = p - q; break;
        default: break;
    }
    return ret;
}

int calcForm(){
    
    int left = form[0]-'0';
    
    for(int i = 1; i < N; i+=2){
        int now = form[i+1]-'0';
        if(bracketOpen[i]){
            left = calc(form[i-1]-'0', form[i+1]-'0', form[i]);
        }
        else if(bracketOpen[i+2]){
            left = calc(left, calc(form[i+1]-'0', form[i+3]-'0', form[i+2]), form[i]);
            i += 2;
        }
        else{
            left = calc(left, now, form[i]);
        }
    }
    
    return left;
}

void bruteForce(int now){
    if(now >= form.size()){
        answer = max(answer, calcForm());
        return;
    }
    
    bruteForce(now+2);
    
    // open&close bracket
    // 연산자 기준
    if(now % 2 == 1){
        bracketOpen[now] = 1;
        bruteForce(now+4);
        bracketOpen[now] = 0;
    }
}

void solve(){
    bruteForce(1);
    cout << answer;
}

int main(){
    input();
    solve();
    
    return 0;
}
