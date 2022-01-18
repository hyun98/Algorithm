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
int dist[50001];
int max_dist = 0;

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> dist[i];
    }
}

void solve(){
    
}

int main(){
    input();
    solve();
    
    return 0;
}
