#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P{
    int x, y;
};

vector<P> arr;
int N;

bool cmp(P &a, P &b){
    if(a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}

void input(){
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), cmp);
}

inline int solve(){
    int st = arr[0].x;
    int ed = arr[0].y;
    
    int result = 0;
    
    for(int i = 1; i < N; i++){
        if(arr[i].x <= ed){
            ed = max(ed, arr[i].y);
        }
        else{
            result += (ed - st);
            st = arr[i].x;
            ed = arr[i].y;
        }
    }
    result += (ed - st);
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << solve();
    return 0;
}