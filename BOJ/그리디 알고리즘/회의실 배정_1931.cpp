#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct P{
    int st, ed;
};

int N;
vector<P> times;

bool cmp(P x, P y){
    if(x.ed == y.ed) return x.st < y.st;
    else return x.ed < y.ed;
}

void input(){
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        times.push_back({a, b});
    }
    
    sort(times.begin(), times.end(), cmp);
}

void solve(){
    int result = 1;
    int lo, hi = times[0].ed;
    for(int i = 1; i < N; i++){
        if(times[i].st >= hi){
            lo = times[i].st;
            hi = times[i].ed;
            result++;
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    
    return 0;
}
