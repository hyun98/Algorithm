#include <iostream>

using namespace std;

struct P{
    vector<string> words;
    bool visited[100] = {false, };
};

class WordChain{
    int n;
    vector<string> words, result;
    vector<P> linked_words[26];
    
public:
    WordChain(){
        cin >> n;
        string w;
        for(int i = 0; i < n; i++){
            cin >> w;
            P input;
            input.words.push_back(w);
            int now = w.front() - 'a';
            
            linked_words[now].push_back(input);
        }
    }
    
    void dfs(int alpha, int now){
        
        result.push_back(words[now]);
        
        int index = words[alpha].back() - 'a';
        for(int i = 0; i < linked_words[].size(); i++){
            if(!visited[index]){
                
            }
        }
        result.pop_back();
    }
    
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test;
    cin >> test;
    while(test--){
        WordChain W1;
        
    }
    return 0;
}
