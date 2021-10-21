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


int N, M, K;
int jew[101];
vector<int> adj[101];
bool visited[(1 << 15) + 1][101];

void input(){
    cin >> N >> M >> K;
    int a;
    for(int i = 0; i < K; i++){
        cin >> a;
        jew[i+1] = a;
    }
}

// state는 보석이 있는 
int solve(int now, int state){
    if(visited[state][now]) return 0;
    
    // 현재 섬에 보석이 있는 경우
    if(jew[now]){
        // 보석을 줍는다
        
        // 줍지 않는다.
        
    }
    else{
        // 그냥 이동해야지
    }
    
    
}

int main(){
    input();
    solve();
    
    return 0;
}
