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

int N, M;
vector<int> arr;
bool visited[10];
vector<vector<int> > result;

void input(){
    int a;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
}

void dfs(vector<int> &save, int now, int cnt){
    if(cnt == M){
        vector<int> temp;
        for(auto &w : save){
            temp.push_back(w);
        }
        result.push_back(temp);
        return;
    }
    
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        save.push_back(arr[i]);
        dfs(save, i, cnt+1);
        save.pop_back();
        visited[i] = false;
    }
}

void solve(){
    vector<int> save;
    dfs(save, 0, 0);
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    for(auto &vec : result){
        for(auto &w : vec){
            cout << w << " ";
        }
        cout << "\n";
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
