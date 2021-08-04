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

int K, N, F;
bool is_friend[901][901];

void input(){
    cin >> K >> N >> F;
    int a, b;
    for(int i = 0; i < F; i++){
        cin >> a >> b;
        is_friend[a][b] = is_friend[b][a] = true;
        is_friend[a][a] = is_friend[b][b] = true;
    }
}

void recurecurecursive(int now, vector<int> &nums){
    if(nums.size() == K){
        for(auto &w : nums){
            cout << w << "\n";
        }
        exit(0);
    }
    
    for(int next = now+1; next <= N; next++){
        if(!is_friend[now][next]) continue;
        bool ad = true;
        for(auto &i : nums){
            if(!is_friend[i][next]){
                ad = false;
                break;
            }
        }
        if(!ad) break;
        nums.push_back(next);
        recurecurecursive(next, nums);
        nums.pop_back();
    }
}

void solve(){
    vector<int> num;
    for(int i = 1; i <= N; i++){
        num.push_back(i);
        recurecurecursive(i, num);
        num.pop_back();
    }
    cout << -1 << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
