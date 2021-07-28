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

string text, pattern;
vector<int> table;
vector<int> idxans;
int anscnt = 0;

void input(){
    getline(cin, text);
    getline(cin, pattern);
}

void preset(){
    table.resize(pattern.size(), 0);
    int j = 0;
    for(int i = 1; i < pattern.size(); i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
}

void KMP(){
    int j = 0;
    for(int i = 0; i < text.size(); i++){
        while(j > 0 && text[i] != pattern[j]){
            j = table[j-1];
        }
        if(text[i] == pattern[j]){
            if(j == pattern.size()-1){
                idxans.push_back(i - pattern.size() + 2);
                anscnt++;
                j = table[j];
            }
            else{
                j++;
            }
        }
    }
}

void solve(){
    preset();
    KMP();
    
    cout << anscnt << "\n";
    for(auto &w : idxans){
        cout << w << " ";
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
