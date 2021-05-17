#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int L, C;
vector<char> str;
char ret[16];
bool visit[16] = {false, };

// 현재 문자가 모음이면 true
bool is_vowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
    else return false;
}

void dfs(int pos, int d, int vow, int con){
    if(d == L){
        if(vow == 0 || con < 2) return;
        for(int i = 0; i < L; i++){
            cout << ret[i];
        }
        cout << "\n";
        return;
    }
    
    //str[0] 부터 str[C-1]까지 탐색
    for(int i = pos; i < C ; i++){
        if(visit[i]) continue; //방문했을경우 다음 글자로 넘어감
        
        ret[d] = str[i]; // 결과가 될 현재 깊이 위치에 str의 문자를 입력
        if(is_vowel(ret[d])) vow++; //모음과 자음의 갯수를 카운팅
        else con++;
        
        visit[i] = 1;
        dfs(i+1, d+1, vow, con);
        visit[i] = 0;
        if(is_vowel(ret[d])) vow--; // 다시 빼주기
        else con --;
        
    }
}

int main(){
    cin >> L >> C;
    char c;
    for(int i = 0; i < C; i++){
        cin >> c;
        str.push_back(c);
    }
    sort(str.begin(), str.end());
    
    dfs(0, 0, 0, 0);
    
    return 0;
}
