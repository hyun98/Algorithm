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
int dist[50010];
int dist_sum[50010];
int max_dist = 0;


void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> dist[i];
        dist_sum[i] = dist_sum[i-1] + dist[i];
    }
}

void solve(){
    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){
            int i_to_j = dist_sum[j-1] - dist_sum[i-1];
            // cout << i << " to " << j << " : " << i_to_j << '\n';
            int j_to_i = dist_sum[N] - i_to_j;
            
            int temp = min(i_to_j, j_to_i);
            max_dist = max(max_dist, temp);
        }
    }
    
    cout << max_dist;
}

int main(){
    input();
    solve();
    
    return 0;
}
