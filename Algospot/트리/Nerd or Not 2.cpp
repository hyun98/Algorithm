#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> nerd;
int result = 0, cnt = 0;

//포함하면 true
bool Included(int key, int value){
    auto itr = nerd.lower_bound(key);
    if(itr == nerd.end()) return false;

    return value < itr->second;
}

void Delete(int key, int value){
    auto itr = nerd.lower_bound(key);
    if(itr == nerd.begin()) return;

    itr--;
    while(1){
        if(itr->second < value) itr = nerd.erase(itr);
        else break;
        itr--;
    }
}

void solve(){
    int N, p, q, result = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p >> q;
        if(!Included(p, q)){
            Delete(p, q);
            nerd[p] = q;
        }
        result += nerd.size();
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int C;
    cin >> C;
    for(int i = 0; i < C; i++){
        solve();
        cout << "\n";
    }

    return 0;
}
