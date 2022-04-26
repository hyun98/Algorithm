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

struct Ball{
    int idx;
    int color;
    int weight;
};

bool cmp(Ball const &a, Ball const &b){
    if(a.weight == b.weight) return a.color < b.color;
    else return a.weight < b.weight;
}

int N;
Ball vec[200022];
int colorDp[200022];
int weightDp[2022];
int ans[200022];

void input(){
    cin >> N;
    int c, w;
    for(int i = 0; i < N; i++){
        cin >> c >> w;
        vec[i] = {i, c, w};
    }
}

void solve(){
    
    sort(vec, vec+N, cmp);
    int sum = 0;
    
    for(int i = 0; i < N; i++){
        int color = vec[i].color;
        int weight = vec[i].weight;
        int idx = vec[i].idx;
        
        sum += weight;
        colorDp[color] += weight;
        weightDp[weight] += weight;
        
        ans[idx] = sum - colorDp[color] - weightDp[weight] + weight;
        if(i != 0 && vec[i-1].color == color && vec[i-1].weight == weight){
            ans[idx] = ans[vec[i-1].idx];
        }
    }
    
    for(int i = 0; i < N; i++){
        cout << ans[i] << '\n';
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
