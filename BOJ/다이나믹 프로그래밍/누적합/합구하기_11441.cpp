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
int arr[100001];
int psum[100001];
vector<pii > query;

void input(){
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    cin >> M;
    
    int s, e;
    for(int i = 0; i < M; i++){
        cin >> s >> e;
        query.push_back({s, e});
    }
}

void solve(){
    
    for(int i = 1; i <= N; i++){
        psum[i] = arr[i] + psum[i-1];
    }
    
    for(auto &q: query){
        cout << psum[q.second] - psum[q.first-1] << '\n';
    }
    
}

int main(){
    input();
    solve();
    
    return 0;
}
