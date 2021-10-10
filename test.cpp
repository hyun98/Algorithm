#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;


void solve(){
    list<vector<int>> len;
    for(int i = 0; i < 10; i++){
        vector<int> vec;
        for(int j = 0; j < 10; j++){
            vec.push_back(10*i + j);
        }
        len.push_back(vec);
        
    }
    for(auto it = len.begin(); it != len.end(); it++){
        for(auto w: *it){
            cout << w << "\n";
        }
    }
}

int main(){
    solve();
    
    return 0;
}
