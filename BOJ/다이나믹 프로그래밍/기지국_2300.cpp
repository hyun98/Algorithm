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
vector<pii > arr;
int min_width[10001];

void input(){
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        arr.push_back({a, abs(b)});
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < 10001; i++){
        min_width[i] = INF;
    }
}

void solve(){
    min_width[0] = abs(arr[0].second) * 2;
    
    for(int i = 1; i < N; i++){
        int temp_height = arr[i].second;
        min_width[i] = min_width[i-1] + temp_height*2;
        
        for(int j = i-1; j >= 0; j--){
            temp_height = max(temp_height, arr[j].second);
            int temp_width = arr[i].first - arr[j].first;
            int area_jtoi = max(temp_height*2, temp_width);
            
            if(j > 0) min_width[i] = min(min_width[i], area_jtoi + min_width[j-1]);
            else      min_width[i] = min(min_width[i], area_jtoi);
        }
    }
    
    cout << min_width[N-1] << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
