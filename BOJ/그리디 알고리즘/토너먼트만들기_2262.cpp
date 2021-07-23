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

int N, maxidx, maxnum, ans;
vector<int> Rnk;


void input(){
    cin >> N;
    int a;
    
    for(int i = 0; i < N; i++){
        cin >> a;
        Rnk.push_back(a);
        if(a > maxnum){
            maxnum = a;
            maxidx = i;
        }
    }
}

void rank_diff(){
    if(maxidx - 1 >= 0 && maxidx + 1 < Rnk.size()){
        if(maxnum - Rnk[maxidx-1] < maxnum - Rnk[maxidx+1]){
            ans += (maxnum - Rnk[maxidx-1]);
        }
        else{
            ans += (maxnum - Rnk[maxidx+1]);
        }
    }
    else if(maxidx - 1 >= 0){
        ans += (maxnum - Rnk[maxidx-1]);
    }
    else if(maxidx + 1 < Rnk.size()){
        ans += (maxnum - Rnk[maxidx+1]);
    }
    
    Rnk.erase(Rnk.begin() + maxidx);
    maxnum--;
    
    for(int i = 0; i < Rnk.size(); i++){
        if(maxnum == Rnk[i]){
            maxidx = i;
            return;
        }
    }
}

void solve(){
    
    while(maxnum != 1){
        rank_diff();
    }
    
    cout << ans;
}

int main(){
    input();
    solve();
    
    return 0;
}
