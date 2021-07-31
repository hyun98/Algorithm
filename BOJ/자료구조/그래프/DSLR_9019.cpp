#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
#define MOD 10000
typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int T, A, B;

int D(int now){
    return (now*2) % MOD;
}
int S(int now){
    if(!now) return 9999;
    return now-1;
}
int L(int now){
    int k = now/1000;
    return (now%1000)*10+ k;
}
int R(int now){
    int k = now%10;
    return (now/10) + k*1000;
}

string bfs(int source, int sink){
    queue<pair<int, string> > que;
    que.push({source, ""});
    bool visited[10001];
    memset(visited, 0, sizeof(visited));
    
    while(!que.empty()){
        int now = que.front().first;
        string str = que.front().second;
        que.pop();
        
        int d = D(now);
        if(!visited[d]) que.push({d, str+'D'});
        visited[d] = true;
        if(d == sink) return str+'D';
        
        int s = S(now);
        if(!visited[s]) que.push({s, str+'S'});
        visited[s] = true;
        if(s == sink) return str+'S';
        
        int l = L(now);
        if(!visited[l]) que.push({l, str+'L'});
        visited[l] = true;
        if(l == sink) return str+'L';
        
        int r = R(now);
        if(!visited[r]) que.push({r, str+'R'});
        visited[r] = true;
        if(r == sink) return str+'R';
    }
    return "";
}

void solve(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> A >> B;
        cout << bfs(A, B) << "\n";
    }
    
}

int main(){
    fastio
    solve();
    
    return 0;
}
