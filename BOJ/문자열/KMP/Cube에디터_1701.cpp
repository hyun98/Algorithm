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

string text;
int table[5001];

int KMP(string pattern){
    memset(table, 0, sizeof(table));
    int res = 0;
    int j = 0;
    
    for(int i = 1; i < pattern.size(); i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
        res = max(res, table[i]);
    }
    return res;
}

void solve(){
    int res = 0;
    for(int i = 0; i < text.size(); i++){
        res = max(res, KMP(text.substr(i)));
    }
    cout << res << "\n";
}

int main(){
    cin >> text;
    solve();
    
    return 0;
}
