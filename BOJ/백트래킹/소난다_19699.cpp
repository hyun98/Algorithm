#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;

using namespace std;


int N, M;
vector<int> weight;
set<int> ans;
bool visited[10];

void input(){
    cin >> N >> M;
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        weight.push_back(a);
    }
}

bool isPrime(int num){
    if(num < 2) return false;
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

void dfs(int cnt, int sum){
    if(cnt == M){
        if(isPrime(sum)) ans.insert(sum);
        return;
    }
    
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        
        dfs(cnt+1, sum+weight[i]);
        
        visited[i] = false;
    }
}

void solve(){
    
    dfs(0, 0);
    
    if(!ans.size()) cout << "-1\n";
    else{
        for(auto &w: ans){
            cout << w << " ";
        }
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
