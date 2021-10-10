#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N;
string WILD;

vector<string> inputstr;

void input(){
    inputstr.clear();
    cin >> WILD >> N;
    string str;
    for(int i = 0; i < N; i++){
        inputstr.push_back(str);
    }
}

bool match(int idx, string& target){
    while(idx < WILD.size() && idx < target.size() && (target[idx] == WILD[idx] || WILD[idx] == '?')){
        idx++;
    }
    
    if(idx == WILD.size()){
        return target.size() == idx;
    }
    
    if(WILD[idx] == '*'){
        for(int i = idx; i < target.size(); i++){
            
        }
    }
    
}

void solve(){
    
}

int main(){
    int T;
    while(T--){
        input();
        solve();
    }
    
    return 0;
}
