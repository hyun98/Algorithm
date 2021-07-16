#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class WildCard{
    string pattern;
    vector<string> filenames, finds;
    int cache[101][101];
    
public:
    WildCard(){
        int n;
        cin >> pattern;
        cin >> n;
        filenames.resize(n+1);
        for(int i = 0; i < n; i++){
            cin >> filenames[i];
        }
    }
    
    void cachereset(){
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                cache[i][j] = -1;
            }
        }
    }
    
    void findStart(){
        for(int i = 0; i < filenames.size(); i++){
            cachereset();
            if(matching(0, 0, i) == 1){
                finds.push_back(filenames[i]);
            }
        }
        sort(finds.begin(), finds.end());
        for(auto word : finds){
            cout << word << "\n";
        }
    }
    
    //p :패턴단어의 인덱스, s :filename의 인덱스, i :filename을 지정해주는 filenames의 인덱스 
    int matching(int p, int s, int i){
        if(cache[p][s] != -1) return cache[p][s];
        
        while(p < pattern.size() && s < filenames[i].size() 
              && (pattern[p] == '?' || pattern[p] == filenames[i][s])){
            // 1글자씩 순환
            return cache[p][s] = matching(p+1, s+1, i);
        }
        
        // 패턴 끝에 도달해서 끝난 경우라면 비교 문자열도 끝에 도달해야함
        if(p == pattern.size()){
            return cache[p][s] = (s == filenames[i].size());
        }
        
        //*을 만난 경우
        if(pattern[p] == '*'){
            // pattern을 1 증가시켜서 비교 || 문자열을 1증가시켜서 비교
            if(matching(p+1, s, i) == 1 || 
               (s < filenames[i].size() && matching(p, s+1, i) == 1)){
                return cache[p][s] = 1;
            }

//            for(int k = 0; k+s < filenames[i].size(); k++){
//                if(matching(p+1, k+s, i) == 1){
//                    return cache[p][s] = 1;
//                }
//            }
        }
        // 위의 조건문이 모두 해당되지 않으면 일치하지 않는 문자
        return cache[p][s] = 0;
    }
    
};

int main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        WildCard w1;
        w1.findStart();
    }
    return 0;
}
