#include <bits/stdc++.h>

using namespace std;

int N;
string res = "", num = "123";

bool is_bad(){
    int mid = res.size()/2;
     
    for(int start = 0; start < res.size(); start++){
        int lolen = (res.size() - start)/2;
        string lo = res.substr(start, lolen);
        string hi = res.substr(start + lolen, res.size() - (start+lolen));
        if(lo == hi) return true;
    }
    return false;
}

void dfs(int pos){
    // �Ź� ���� �� ������ ���ݱ��� ������� ������ ���� �������� Ȯ��
    if(is_bad()) return;
    
    // ���� ���� �׽�Ʈ�� ����ϰ� + N���� ���� �̷�� ������ ����ϰ� exit ����
    // ���� ���� ���� ���� ������ ���� ���� ���� �����ΰ� �ڸ��ϴ�
    if(pos == N){
        cout << res;
        exit(0);
    }
    
    for(int i = 0; i < 3; i++){
        res += num[i];
//        cout << "now : " << res << endl;
        dfs(pos+1);
        res.erase(pos);
    }
    
}

int main(){
    cin >> N;
    dfs(0);
    
    return 0;
}
