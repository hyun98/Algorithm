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
string patt;
vector<string> strlist;

int cache[101][101];

void input(){
    cin >> patt;
    cin >> N;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        strlist.push_back(str);
    }
}

int matching(string &file, int fileidx, int pattidx){
    int &ret = cache[fileidx][pattidx];
    if(ret != -1) return ret;
    ret = 0;
    
    while(fileidx < file.size() && pattidx < patt.size() &&
            file[fileidx] == patt[pattidx]){
        return ret = matching(file, fileidx+1, pattidx+1);
    }
    if(pattidx == patt.size()){
        return ret = (file.size() == fileidx);
    }
    
    if(patt[pattidx] == '*'){
        for(int i = fileidx; i <= file.size(); i++){
            if(matching(file, i, pattidx+1)) return ret = 1;
        }
    }
    
    return ret;
}

void solve(){
    vector<string> ans;
    for(int i = 0; i < N; i++){
        memset(cache, -1, sizeof(cache));
        if(matching(strlist[i], 0, 0)){
            ans.push_back(strlist[i]);
        }
    }
    
    for(auto s: ans){
        cout << s << "\n";
    }
}

int main(){
    input();
    solve();
    
    return 0;
}
