#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int L, C;
vector<char> str;
char ret[16];
bool visit[16] = {false, };

// ���� ���ڰ� �����̸� true
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
    
    //str[0] ���� str[C-1]���� Ž��
    for(int i = pos; i < C ; i++){
        if(visit[i]) continue; //�湮������� ���� ���ڷ� �Ѿ
        
        ret[d] = str[i]; // ����� �� ���� ���� ��ġ�� str�� ���ڸ� �Է�
        if(is_vowel(ret[d])) vow++; //������ ������ ������ ī����
        else con++;
        
        visit[i] = 1;
        dfs(i+1, d+1, vow, con);
        visit[i] = 0;
        if(is_vowel(ret[d])) vow--; // �ٽ� ���ֱ�
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
