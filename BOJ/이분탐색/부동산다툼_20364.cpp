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

int N, Q;
vector<int> Duck;
int Land[(1 << 21) + 1];
int tempres;

void input(){
    cin >> N >> Q;
    int a ;
    for(int i = 0; i < Q; i++){
        cin >> a;
        Duck.push_back(a);
    }
}

void recur(int dest){
    if(!dest) return;
    
    if(dest % 2 == 0){
        recur(dest / 2);
        if(Land[dest]){
            tempres = min(tempres, dest);
        }
    }
    else{
        recur((dest-1)/2);
        if(Land[dest]){
            tempres = min(tempres, dest);
        }
    }
}

void solve(){
    for(int i = 0; i < Q; i++){
        tempres = INF;
        int dest = Duck[i];
        Land[dest]++;
        recur(dest);
        if(tempres == dest && Land[dest] == 1) cout << 0 << "\n";
        else cout << tempres << "\n";
    }
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
