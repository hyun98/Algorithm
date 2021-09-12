#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>

typedef long long ll;
// typedef pair<int, int> pii;

using namespace std;

int N, LIM;
int res;
vector<string> words;
int table[27];
bool visited[10];
string alpha = "";

void input(){
    cin >> N;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        words.push_back(str);
    }
}

int word_to_int(string &word){
    int num = 0;
    for(int i = 0; i < word.size(); i++){
        num = num*10 + table[word[i] - 'A'];
    }
    
    return num;
}

void dfs(int cnt){
    if(cnt == LIM){
        // 주어진 모든 알파벳에 대해서 숫자를 부여했다면
        // 각 단어를 숫자로 변환 후 단어의 합을 구한다.
        int sum = 0;
        for(auto &w: words){
            sum += word_to_int(w);
        }
        res = max(res, sum);
        return;
    }
    
    for(int i = 9; i > 9-LIM; i--){
        if(visited[i]) continue;
        visited[i] = true;
        table[alpha[cnt] - 'A'] = i;
        
        dfs(cnt+1);
        
        visited[i] = false;
    }
}

void solve(){
    // ==알파벳 중복 제거==
    set<char> filter;
    
    for(auto &w: words){
        for(auto &c: w){
            filter.insert(c);
        }
    }
    
    
    for(auto &f: filter){
        alpha += f;
    }
    // ===============
    
    LIM = alpha.size();
    
    dfs(0);
    
    cout << res << "\n";
}

int main(){
    fastio
    input();
    solve();
    
    return 0;
}
