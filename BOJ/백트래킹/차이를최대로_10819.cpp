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

int N, ans;
vector<int> arr;
bool visited[10];

void input(){
    cin >> N;
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        arr.push_back(a);
    }
}

int cal(vector<int> &temp){
    int sum = 0;
    for(int i = 0; i < temp.size()-1; i++){
        sum += abs(temp[i] - temp[i+1]);
    }
    return sum;
}

void dfs(int cnt, vector<int> &temp){
    if(cnt == N){
        ans = max(ans, cal(temp));
        return;
    }
    
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        
        visited[i] = true;
        temp.push_back(arr[i]);
        dfs(cnt+1, temp);
        temp.pop_back();
        visited[i] = false;
    }
    
}

void solve(){
    vector<int> asd;
    dfs(0, asd);
    
    cout << ans;
}

int main(){
    input();
    solve();
    
    return 0;
}
