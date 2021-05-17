#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K, result = 0;
vector<string> words;
bool visited[26] = {false, };

void input(){
    string temp;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> temp;
        words.push_back(temp.substr(4, temp.size()-8));
    }
}

inline int search_word(){
    int cnt = 0;
    for(auto w : words){
        bool learn = true;
        for(int i = 0; i < w.size(); i++){
            if(!visited[w[i]-'a']){
                learn = false;
                break;
            }
        }
        if(learn) cnt++;
    }
    
    return cnt;
}

void dfs(int now, int k){
    if(k == K-5){
        result = max(result, search_word());
        return;
    }
    for(int i = now; i < 26; i++){
        if(visited[i]) continue;
        else{
            visited[i] = true;
            dfs(i+1, k+1);
            visited[i] = false;
        }
    }
}

void solve(){
    if(K < 5){
        cout << 0;
        return;
    }
    else if(K == 26){
        cout << N;
        return;
    }
    
    visited['a'-'a'] = true;
    visited['n'-'a'] = true;
    visited['t'-'a'] = true;
    visited['i'-'a'] = true;
    visited['c'-'a'] = true;
    
    dfs(1, 0);
    
    cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}

//7 9
//antarotica
//antajapwtica
//antarnlhtica
//antavfytica
//antarwtica
//antaltica
//antantica
